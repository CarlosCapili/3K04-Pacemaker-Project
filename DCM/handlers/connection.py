import queue
import struct
from enum import Enum, unique
from queue import Queue
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
# It is just a placeholder and not fully implemented, because that happens in Assignment 2
# https://github.com/pyserial/pyserial/issues/216#issuecomment-369414522
class _SerialHandler(QThread):
    running: bool
    buf: bytearray
    conn: Serial
    in_q: Queue
    num_bytes_to_read: int
    sent_data: bytes

    # A signal that's emitted every time we receive ECG data
    ecg_data_update: pyqtSignal = pyqtSignal(str)  # the str is the serial_num and/or a msg

    # https://docs.python.org/3.7/library/struct.html#format-strings
    PARAMS_FMT_STR, ECG_FMT_STR = "=3B6f4H5B", "=4f"
    PARAMS_NUM_BYTES, ECG_NUM_BYTES = struct.calcsize(PARAMS_FMT_STR), struct.calcsize(ECG_FMT_STR)
    PARAMS_ORDER = ["Pacing Mode", "Lower Rate Limit", "Upper Rate Limit", "Atrial Amplitude", "Atrial Pulse Width",
                    "Atrial Sensitivity", "Ventricular Amplitude", "Ventricular Pulse Width", "Ventricular Sensitivity",
                    "VRP", "ARP", "PVARP", "Fixed AV Delay", "Maximum Sensor Rate", "Reaction Time", "Response Factor",
                    "Recovery Time", "Activity Threshold"]
    ECG_ORDER = ["Atrial Pace Amp", "Vent Pace Amp", "Atrial Sense Amp", "Vent Sense Amp"]

    def __init__(self):
        super().__init__()
        print("Serial handler init")

        self.running = False
        self.buf = bytearray()
        self.conn = Serial(baudrate=115200, timeout=0)
        self.in_q = queue.Queue()
        self.num_bytes_to_read = 1
        self.sent_data = bytes()

    # Gets called when the thread starts, overrides method in QThread
    def run(self):
        self.running = True

        while self.running:
            # Check if the serial connection is open with the pacemaker
            if self.conn.is_open:
                try:
                    line = self._readline()  # read one line
                    print(f"received from pacemaker: {line}")

                    if self.num_bytes_to_read == self.PARAMS_NUM_BYTES:
                        self._verify_params(line)
                    elif self.num_bytes_to_read == self.ECG_NUM_BYTES:
                        self.ecg_data_update.emit(line)

                except Exception:
                    pass
            elif self.conn.port:
                self._try_to_open_port()
            else:
                sleep(1)

    # Stops the thread
    def stop(self) -> None:
        self.running = False
        self.conn.close()

    # Open the serial connection with the pacemaker on the specified port
    def start_serial_comm(self, port: str) -> None:
        print(f"opening serial port {port} with pacemaker")
        self.conn.port = port
        self._try_to_open_port()

    def stop_serial_comm(self) -> None:
        self.conn.close()
        self.conn.port = None

    def _try_to_open_port(self):
        try:
            self.conn.open()
            print("opened port")
        except SerialException:
            pass

    # Read the output stream from the pacemaker
    def _readline(self) -> bytearray:
        i: int = len(self.buf)

        if i >= self.num_bytes_to_read:
            r = self.buf[:i + 1]
            self.buf = self.buf[i + 1:]
            return r

        self.num_bytes_to_read = 1
        while self.running and self.conn.is_open:
            data: Optional[bytes] = self.conn.read(self.num_bytes_to_read)
            i = len(self.buf)

            if data and self.num_bytes_to_read == 1:
                self.num_bytes_to_read = self.ECG_NUM_BYTES if data[0] == 0 else self.PARAMS_NUM_BYTES
                continue

            if i >= self.num_bytes_to_read:
                r = self.buf + data[:i + 1]
                self.buf[0:] = data[i + 1:]
                return r
            else:
                self.buf.extend(data)

    def _verify_params(self, received_params: bytes):
        print(self.sent_data == received_params)
        if self.sent_data != received_params:
            print("params are not the same")

    # Sends the DCM parameters to the pacemaker
    def send_params_to_pacemaker(self, params_to_send: Dict[str, Union[int, float]]) -> None:
        self.sent_data = struct.pack(self.PARAMS_FMT_STR, *[params_to_send[key] for key in self.PARAMS_ORDER])
        print(self.sent_data)

        # Check if the serial connection is open with the pacemaker
        if self.conn.is_open:
            self.conn.write(self.sent_data)


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
