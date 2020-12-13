from enum import Enum, unique
from struct import calcsize, pack, unpack_from
from threading import Lock
from time import sleep
from typing import Dict, List, Optional, Union

from PyQt5.QtCore import QThread, pyqtSignal
from PyQt5.QtWidgets import QMessageBox
from serial import Serial, SerialException
from serial.tools import list_ports
from serial.tools.list_ports_common import ListPortInfo


# Enum for pacemaker connection states
@unique
class PacemakerState(Enum):
    NOT_CONNECTED = 1
    CONNECTED = 2
    REGISTERED = 3


# This class is a private class that handles the serial communication with the pacemaker
# https://github.com/pyserial/pyserial/issues/216#issuecomment-369414522
class _SerialHandler(QThread):
    _running: bool
    _buf: bytearray
    _conn: Serial
    _num_bytes_to_read: int
    _sent_data: bytes
    _send_params: bool
    _lock: Lock

    # A signal that's emitted every time we receive ECG data
    ecg_data_update: pyqtSignal = pyqtSignal(tuple, tuple)

    # A signal that's emitted upon param verification with the pacemaker
    params_received: pyqtSignal = pyqtSignal(bool, str)

    # https://docs.python.org/3.7/library/struct.html#format-strings
    _num_floats = 20
    _PARAMS_FMT_STR, _ECG_FMT_STR, _ECG_DATA_STR = "=3BfB2fBf4H5B", f"={_num_floats}f", f"={_num_floats // 2}f"
    _PARAMS_NUM_BYTES, _ECG_NUM_BYTES, _ECG_DATA = calcsize(_PARAMS_FMT_STR), calcsize(_ECG_FMT_STR), calcsize(
        _ECG_DATA_STR)
    _REQUEST_ECG = pack("=B33x", 0x55)
    _PARAMS_ORDER = ["Pacing Mode", "Lower Rate Limit", "Upper Rate Limit", "Atrial Amplitude", "Atrial Pulse Width",
                     "Atrial Sensitivity", "Ventricular Amplitude", "Ventricular Pulse Width",
                     "Ventricular Sensitivity", "VRP", "ARP", "PVARP", "Fixed AV Delay", "Maximum Sensor Rate",
                     "Reaction Time", "Response Factor", "Recovery Time", "Activity Threshold"]

    def __init__(self):
        super().__init__()
        print("Serial handler init")

        self._running = False
        self._buf = bytearray()
        self._conn = Serial(baudrate=115200, timeout=0)
        self._num_bytes_to_read = self._ECG_NUM_BYTES + 1
        self._sent_data = bytes()
        self._send_params = False
        self._lock = Lock()  # lock is used to prevent concurrent accessing/modification of variables

    # Gets called when the thread starts, overrides method in QThread
    def run(self):
        self._running = True

        while self._running:
            # Check if the serial connection with the pacemaker is open
            if self._conn.is_open:
                try:
                    with self._lock:
                        if self._send_params:  # if we want to send params
                            self._send_params = False
                            self._conn.write(self._sent_data)
                        else:
                            self._conn.write(self._REQUEST_ECG)

                    line = self._readline()  # read one packet of num_bytes_to_read size

                    control_byte = line[0]  # first byte
                    line = line[1:]  # the rest of them

                    # If we've received ECG data, elif we've received params data
                    if control_byte == 0:
                        a_data = unpack_from(self._ECG_DATA_STR, line, 0)
                        v_data = unpack_from(self._ECG_DATA_STR, line, self._ECG_DATA)

                        self.ecg_data_update.emit(a_data, v_data)
                    elif control_byte == 1:
                        self._verify_params(line)

                except Exception as e:
                    print(e)
                    pass
            elif self._conn.port:
                self._try_to_open_port()
            else:
                sleep(1)

    # Read the output stream of the pacemaker
    def _readline(self) -> bytearray:
        buf_len: int = len(self._buf)

        # If buffer already contains more than num_bytes_to_read bytes, remove and return the oldest ones from buffer
        if buf_len >= self._num_bytes_to_read:
            r = self._buf[:self._num_bytes_to_read]
            self._buf = self._buf[self._num_bytes_to_read:]
            return r

        # Read serial data and store in buffer until we have num bytes to read bytes, then remove and return those
        while self._running and self._conn.is_open:
            data: Optional[bytes] = self._conn.read(self._num_bytes_to_read)
            buf_len = len(self._buf)

            if buf_len >= self._num_bytes_to_read:
                r = self._buf[:self._num_bytes_to_read]
                self._buf = self._buf[self._num_bytes_to_read:] + data
                return r
            else:
                self._buf.extend(data)

    # Attempt to open serial port with pacemaker
    def _try_to_open_port(self) -> None:
        with self._lock:
            try:
                self._conn.open()
                print("opened port")
            except SerialException:
                pass

    # Verify that the params sent to the pacemaker are the ones received
    def _verify_params(self, received_params: bytes) -> None:
        if self._sent_data != bytes(received_params[:self._PARAMS_NUM_BYTES]):
            self.params_received.emit(False, "The received parameters were not the same as the sent ones!\nPlease "
                                             "restart the DCM/Pacemaker or try a different Pacemaker!")
        else:
            self.params_received.emit(True, "Successfully sent parameters!")

    # Stops the thread
    def stop(self) -> None:
        with self._lock:
            self._running = False
            self._conn.close()

    # Set the serial connection port to that of the pacemaker, and clear the buffer
    def start_serial_comm(self, port: str) -> None:
        print(f"opening serial port {port} with pacemaker")
        self._buf = bytearray()
        with self._lock:
            self._conn.port = port

    # Safely close the serial connection and clear the port
    def stop_serial_comm(self) -> None:
        with self._lock:
            self._conn.close()
            self._conn.port = None

    # Update the parameters to send to the pacemaker, and enable the send flag
    def send_params_to_pacemaker(self, params_to_send: Dict[str, Union[int, float]]) -> None:
        with self._lock:
            self._sent_data = pack(self._PARAMS_FMT_STR, *[params_to_send[key] for key in self._PARAMS_ORDER])
            self._send_params = True


# This class handles the pacemaker connection for the DCM and extends the QThread class to allow for multithreading
class ConnectionHandler(QThread):
    _running: bool
    _device: ListPortInfo
    _devices: List[ListPortInfo]
    _old_devices: List[ListPortInfo]
    _first_serial_num: str
    _current_state: PacemakerState
    _prev_state: PacemakerState
    _wanted_state: PacemakerState
    serial: _SerialHandler

    # A signal that's emitted every time we change state
    connect_status_change: pyqtSignal = pyqtSignal(PacemakerState, str)  # the str is the serial_num and/or a msg

    def __init__(self):
        super().__init__()
        print("Connection handler init")

        self._running = False

        self._device = ListPortInfo()
        self._devices = self._old_devices = []

        self._first_serial_num = ""

        self._current_state = self._prev_state = self._wanted_state = PacemakerState.NOT_CONNECTED

        # Initialize and start the serial connection handler
        self.serial = _SerialHandler()
        self.serial.start()

    # Gets called when the thread starts, overrides method in QThread
    def run(self):
        self._running = True
        self.connect_status_change.emit(PacemakerState.NOT_CONNECTED, "")

        while self._running:
            self._update_state()
            sleep(0.01)

    # Stops the thread and stops the serial conn thread
    def stop(self) -> None:
        self._running = False
        self.serial.stop()

    # State machine for pacemaker connection state. It was implemented like this because it offers us many benefits
    # such as cleaner, easier to read code, ensuring that a pacemaker gets registered only once, handling multiple
    # pacemakers being plugged into the same computer, and handling the New Patient btn presses in a much simpler way.
    def _update_state(self) -> None:
        # Get list of connected COM port devices
        self._devices = self._filter_devices(list_ports.comports())

        added = [dev for dev in self._devices if dev not in self._old_devices]  # difference between new and old
        removed = [dev for dev in self._old_devices if dev not in self._devices]  # difference between old and new

        # Update the current state if its not aligned with the state we want to be in
        if self._current_state != self._wanted_state:
            self._current_state = self._wanted_state

        # We're not connected to any pacemaker
        if self._current_state == PacemakerState.NOT_CONNECTED:
            if len(added) > 0:  # if there is a new device added
                self._device = added[0]

                if self._first_serial_num == "":  # if this is the first device connected, auto-register
                    self._first_serial_num = self._device.serial_number
                    self._wanted_state = PacemakerState.REGISTERED
                elif self._first_serial_num == self._device.serial_number:  # if the first device was replugged in
                    self._wanted_state = PacemakerState.REGISTERED
                else:  # another device is plugged in
                    self._wanted_state = PacemakerState.CONNECTED

        # We're connected to an unregistered pacemaker
        elif self._current_state == PacemakerState.CONNECTED:
            # The only way to go from CONNECTED to REGISTERED is if the New Patient btn is pressed
            if self._prev_state == PacemakerState.NOT_CONNECTED:
                self.connect_status_change.emit(PacemakerState.CONNECTED, f"{self._device.serial_number}, press New "
                                                                          f"Patient to register")
            # Handle a device being removed
            self._handle_removed_device(removed)

        # We're connected to a registered pacemaker
        elif self._current_state == PacemakerState.REGISTERED:
            # If we've just transitioned to REGISTERED, open the serial communication link
            if self._prev_state == PacemakerState.NOT_CONNECTED or self._prev_state == PacemakerState.CONNECTED:
                self.serial.start_serial_comm(self._device.device)
                self.connect_status_change.emit(PacemakerState.REGISTERED, self._device.serial_number)

            # Handle a device being removed
            self._handle_removed_device(removed)

        # Update variables that store previous cycle information
        self._old_devices = self._devices
        self._prev_state = self._current_state

    # Called when the New Patient button is pressed
    def register_device(self) -> None:
        if self._current_state == PacemakerState.CONNECTED:
            self._wanted_state = PacemakerState.REGISTERED
        elif self._device.serial_number:  # at this point, we've already registered the device
            self._show_alert("Already registered this pacemaker!")
        elif len(self._devices) > 0:  # we only connect to 1 device at a time, so the rest are ignored
            self._show_alert("Please unplug and replug the pacemaker you want to connect to!")
        else:
            self._show_alert("Please plug in a pacemaker!")

    # Handles the transition to NOT_CONNECTED if the pacemaker we're connected to is unplugged
    def _handle_removed_device(self, removed: List[ListPortInfo]) -> None:
        if any(self._device.serial_number == dev.serial_number for dev in removed):
            self._wanted_state = PacemakerState.NOT_CONNECTED
            self.connect_status_change.emit(PacemakerState.NOT_CONNECTED, removed[0].serial_number)
            self._device = ListPortInfo()
            self.serial.stop_serial_comm()

    # Called when the Pace Now button is pressed
    def send_data_to_pacemaker(self, params: Dict[str, Union[int, float]]) -> None:
        if self._current_state == PacemakerState.REGISTERED:
            self.serial.send_params_to_pacemaker(params)
        elif self._current_state == PacemakerState.CONNECTED:
            self._show_alert("Please register the pacemaker first!")
        else:
            self._show_alert("Please plug in a pacemaker!")

    @staticmethod
    def _show_alert(msg: str) -> None:
        """
        Displays an information message with the specified text

        :param msg: the text to show
        """
        qm = QMessageBox()
        QMessageBox.information(qm, "Connection", msg, QMessageBox.Ok, QMessageBox.Ok)

    @staticmethod
    def _filter_devices(data: List[ListPortInfo]) -> List[ListPortInfo]:
        """
        Filter plugged in COM port devices so that we only connect to pacemaker devices
        The SEGGER devices have a Vendor ID of 0x1366 and Product ID of 0x1015

        :param data: list of all plugged in COM port devices
        :return: list of all plugged in pacemaker devices
        """
        return [dev for dev in data if dev.vid == 0x1366 and dev.pid == 0x1015]
