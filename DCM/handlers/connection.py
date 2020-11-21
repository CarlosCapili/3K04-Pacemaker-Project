import struct
from enum import Enum, unique
from threading import Lock
from time import sleep
from typing import Dict, List, NamedTuple, Optional, Union

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


# Typed version of namedtuple() for received ECG data
class ECGData(NamedTuple):
    atri_pace: float
    vent_pace: float
    atri_sense: float
    vent_sense: float


# This class is a private class that handles the serial communication with the pacemaker
# https://github.com/pyserial/pyserial/issues/216#issuecomment-369414522
class _SerialHandler(QThread):
    _running: bool
    _buf: bytearray
    _conn: Serial
    _num_bytes_to_read: int
    _sent_data: bytes

    # A signal that's emitted every time we receive ECG data
    ecg_data_update: pyqtSignal = pyqtSignal(ECGData)

    # A signal that's emitted upon failed param verification with the pacemaker
    diff_params_received: pyqtSignal = pyqtSignal(str)

    # https://docs.python.org/3.7/library/struct.html#format-strings
    PARAMS_FMT_STR, ECG_FMT_STR = "=3B6f4H5B", "=4f"
    PARAMS_NUM_BYTES, ECG_NUM_BYTES = struct.calcsize(PARAMS_FMT_STR), struct.calcsize(ECG_FMT_STR)
    PARAMS_ORDER = ["Pacing Mode", "Lower Rate Limit", "Upper Rate Limit", "Atrial Amplitude", "Atrial Pulse Width",
                    "Atrial Sensitivity", "Ventricular Amplitude", "Ventricular Pulse Width", "Ventricular Sensitivity",
                    "VRP", "ARP", "PVARP", "Fixed AV Delay", "Maximum Sensor Rate", "Reaction Time", "Response Factor",
                    "Recovery Time", "Activity Threshold"]

    def __init__(self):
        super().__init__()
        print("Serial handler init")

        self._running = False
        self._buf = bytearray()
        self._conn = Serial(baudrate=115200, timeout=0)
        self._num_bytes_to_read = 1
        self._sent_data = bytes()
        self._lock = Lock()

    # Gets called when the thread starts, overrides method in QThread
    def run(self):
        self._running = True

        while self._running:
            # Check if the serial connection is open with the pacemaker
            if self._conn.is_open:
                try:
                    line = self._readline()  # read one line
                    print(f"received from pacemaker: {line}")

                    if self._num_bytes_to_read == self.PARAMS_NUM_BYTES:
                        self._verify_params(line)
                    elif self._num_bytes_to_read == self.ECG_NUM_BYTES:
                        self.ecg_data_update.emit(ECGData._make(struct.unpack(self.ECG_FMT_STR, line)))

                except Exception:
                    pass
            elif self._conn.port:
                self._try_to_open_port()
            else:
                sleep(1)

    # Stops the thread
    def stop(self) -> None:
        with self._lock:
            self._running = False
            self._conn.close()

    # Open the serial connection with the pacemaker on the specified port
    def start_serial_comm(self, port: str) -> None:
        print(f"opening serial port {port} with pacemaker")
        self._conn.port = port
        self._try_to_open_port()

    def stop_serial_comm(self) -> None:
        with self._lock:
            self._conn.close()
            self._conn.port = None

    def _try_to_open_port(self):
        with self._lock:
            try:
                self._conn.open()
                print("opened port")
            except SerialException:
                pass

    # Read the output stream from the pacemaker
    def _readline(self) -> bytearray:
        i: int = len(self._buf)

        if i >= self._num_bytes_to_read:
            r = self._buf[:i + 1]
            self._buf = self._buf[i + 1:]
            return r

        self._num_bytes_to_read = 1
        while self._running and self._conn.is_open:
            data: Optional[bytes] = self._conn.read(self._num_bytes_to_read)
            i = len(self._buf)

            if data and self._num_bytes_to_read == 1:
                self._num_bytes_to_read = self.ECG_NUM_BYTES if data[0] == 0 else self.PARAMS_NUM_BYTES
                continue

            if i >= self._num_bytes_to_read:
                r = self._buf + data[:i + 1]
                self._buf[0:] = data[i + 1:]
                return r
            else:
                self._buf.extend(data)

    def _verify_params(self, received_params: bytes):
        if self._sent_data != received_params:
            self.diff_params_received.emit("The received parameters were not the same as the sent ones!\nPlease "
                                           "restart the DCM/Pacemaker or try a different Pacemaker!")

    # Sends the DCM parameters to the pacemaker
    def send_params_to_pacemaker(self, params_to_send: Dict[str, Union[int, float]]) -> None:
        self._sent_data = struct.pack(self.PARAMS_FMT_STR, *[params_to_send[key] for key in self.PARAMS_ORDER])

        # Check if the serial connection is open with the pacemaker
        with self._lock:
            if self._conn.is_open:
                self._conn.write(self._sent_data)


# This class handles the pacemaker connection for the DCM and extends the QThread class to allow for multithreading
class ConnectionHandler(QThread):
    running: bool
    device: ListPortInfo
    devices: List[ListPortInfo]
    old_devices: List[ListPortInfo]
    first_serial_num: str
    current_state: PacemakerState
    prev_state: PacemakerState
    wanted_state: PacemakerState
    serial: _SerialHandler

    # A signal that's emitted every time we change state
    connect_status_change: pyqtSignal = pyqtSignal(PacemakerState, str)  # the str is the serial_num and/or a msg

    def __init__(self):
        super().__init__()
        print("Connection handler init")

        self.running = False

        self.device = ListPortInfo()
        self.devices = self.old_devices = []

        self.first_serial_num = ""

        self.current_state = self.prev_state = self.wanted_state = PacemakerState.NOT_CONNECTED

        # Initialize and start the serial connection handler
        self.serial = _SerialHandler()
        self.serial.start()

    # Gets called when the thread starts, overrides method in QThread
    def run(self):
        self.running = True
        self.connect_status_change.emit(PacemakerState.NOT_CONNECTED, "")

        while self.running:
            self._update_state()
            sleep(0.01)

    # Stops the thread and stops the serial conn thread
    def stop(self) -> None:
        self.running = False
        self.serial.stop()

    # State machine for pacemaker connection state. It was implemented like this because it offers us many benefits
    # such as cleaner, easier to read code, ensuring that a pacemaker gets registered only once, handling multiple
    # pacemakers being plugged into the same computer, and handling the New Patient btn presses in a much simpler way.
    def _update_state(self) -> None:
        # Get list of connected COM port devices
        self.devices = self._filter_devices(list_ports.comports())

        added = [dev for dev in self.devices if dev not in self.old_devices]  # difference between new and old
        removed = [dev for dev in self.old_devices if dev not in self.devices]  # difference between old and new

        # Update the current state if its not aligned with the state we want to be in
        if self.current_state != self.wanted_state:
            self.current_state = self.wanted_state

        # We're not connected to any pacemaker
        if self.current_state == PacemakerState.NOT_CONNECTED:
            if len(added) > 0:  # if there is a new device added
                self.device = added[0]

                if self.first_serial_num == "":  # if this is the first device connected, auto-register
                    self.first_serial_num = self.device.serial_number
                    self.wanted_state = PacemakerState.REGISTERED
                elif self.first_serial_num == self.device.serial_number:  # if the first device was replugged in
                    self.wanted_state = PacemakerState.REGISTERED
                else:  # another device is plugged in
                    self.wanted_state = PacemakerState.CONNECTED

        # We're connected to an unregistered pacemaker
        elif self.current_state == PacemakerState.CONNECTED:
            # The only way to go from CONNECTED to REGISTERED is if the New Patient btn is pressed
            if self.prev_state == PacemakerState.NOT_CONNECTED:
                self.connect_status_change.emit(PacemakerState.CONNECTED, f"{self.device.serial_number}, press New "
                                                                          f"Patient to register")
            # Handle a device being removed
            self._handle_removed_device(removed)

        # We're connected to a registered pacemaker
        elif self.current_state == PacemakerState.REGISTERED:
            # If we've just transitioned to REGISTERED, open the serial communication link
            if self.prev_state == PacemakerState.NOT_CONNECTED or self.prev_state == PacemakerState.CONNECTED:
                self.serial.start_serial_comm(self.device.device)
                self.connect_status_change.emit(PacemakerState.REGISTERED, self.device.serial_number)

            # Handle a device being removed
            self._handle_removed_device(removed)

        # Update variables that store previous cycle information
        self.old_devices = self.devices
        self.prev_state = self.current_state

    # Called when the New Patient button is pressed
    def register_device(self) -> None:
        if self.current_state == PacemakerState.CONNECTED:
            self.wanted_state = PacemakerState.REGISTERED
        elif self.device.serial_number:  # at this point, we've already registered the device
            self._show_alert("Already registered this pacemaker!")
        elif len(self.devices) > 0:  # we only connect to 1 device at a time, so the rest are ignored
            self._show_alert("Please unplug and replug the pacemaker you want to connect to!")
        else:
            self._show_alert("Please plug in a pacemaker!")

    # Handles the transition to NOT_CONNECTED if the pacemaker we're connected to is unplugged
    def _handle_removed_device(self, removed: List[ListPortInfo]) -> None:
        if any(self.device.serial_number == dev.serial_number for dev in removed):
            self.wanted_state = PacemakerState.NOT_CONNECTED
            self.connect_status_change.emit(PacemakerState.NOT_CONNECTED, removed[0].serial_number)
            self.device = ListPortInfo()
            self.serial.stop_serial_comm()

    # Called when the Pace Now button is pressed
    def send_data_to_pacemaker(self, params: Dict[str, Union[int, float]]) -> None:
        if self.current_state == PacemakerState.REGISTERED:
            self.serial.send_params_to_pacemaker(params)
        elif self.current_state == PacemakerState.CONNECTED:
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
