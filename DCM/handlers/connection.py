import queue
from enum import Enum, unique
from queue import Queue
from time import sleep
from typing import List, Optional

from PyQt5.QtCore import QThread, pyqtSignal
from PyQt5.QtWidgets import QMessageBox
from serial import Serial
from serial.tools import list_ports
from serial.tools.list_ports_common import ListPortInfo


@unique
class PacemakerState(Enum):
    NOT_CONNECTED = 1
    CONNECTED = 2
    REGISTERED = 3


# https://github.com/pyserial/pyserial/issues/216#issuecomment-369414522
class _SerialHandler(QThread):
    running: bool
    buf: bytearray
    conn: Serial
    in_q: Queue

    def __init__(self):
        super().__init__()
        print("Serial handler init")

        self.running = False
        self.buf = bytearray()
        self.conn = Serial(baudrate=1152000, timeout=1)
        self.in_q = queue.Queue()

    def run(self):
        self.running = True

        while self.running:
            if self.conn.is_open:
                # try:
                line = self.readline().decode()  # read one line
                print(f"received from pacemaker: {line}")
                self.in_q.put(line)
                # except
            else:
                sleep(1)

    def stop(self):
        self.running = False

    def start_serial_comm(self, port: str):
        print(f"opening serial port {port} with pacemaker")
        self.conn.port = port
        # try:
        #     self.conn.open()
        # except SerialException as e:
        #     raise e

    def readline(self):
        i: int = self.buf.find(b"\n")

        if i >= 0:
            r = self.buf[:i + 1]
            self.buf = self.buf[i + 1:]
            return r

        while self.running:
            i = max(1, min(2048, self.conn.in_waiting))
            data: Optional[bytes] = self.conn.read(i)
            i = data.find(b"\n")

            if i >= 0:
                r = self.buf + data[:i + 1]
                self.buf[0:] = data[i + 1:]
                return r
            else:
                self.buf.extend(data)


class ConnectionHandler(QThread):
    running: bool
    device: ListPortInfo
    devices: List[ListPortInfo]
    old_devices: List[ListPortInfo]
    first_serial_num: str
    wanted_state: PacemakerState
    prev_state: PacemakerState
    current_state: PacemakerState
    serial: _SerialHandler

    connectStatusChange: pyqtSignal = pyqtSignal(PacemakerState, str)  # (not conn, conn, reg), (serial_num and/or msg)

    def __init__(self):
        super().__init__()
        print("Connection handler init")

        self.running = False

        self.device = ListPortInfo()
        self.devices = self.old_devices = []

        self.first_serial_num = ""

        self.current_state = self.prev_state = self.wanted_state = PacemakerState.NOT_CONNECTED

        self.serial = _SerialHandler()
        self.serial.start()

    # Gets called when the thread starts
    def run(self):
        self.running = True
        self.connectStatusChange.emit(PacemakerState.NOT_CONNECTED, "")

        while self.running:
            self.update_state()
            sleep(0.01)

    def stop(self):
        self.running = False
        self.serial.stop()

    # State machine for pacemaker connection state. It was implemented like this because it offers us many benefits
    # such as cleaner, easier to read code, ensuring that a pacemaker gets registered only once, handling multiple
    # pacemakers being plugged into the same computer, and handling the New Patient btn presses in a much simpler way.
    def update_state(self):
        self.devices = self.filter_devices(list_ports.comports())

        added = [dev for dev in self.devices if dev not in self.old_devices]  # difference between new and old
        removed = [dev for dev in self.old_devices if dev not in self.devices]  # difference between old and new

        if self.current_state != self.wanted_state:
            self.current_state = self.wanted_state

        if self.current_state == PacemakerState.NOT_CONNECTED:
            if len(added) > 0:
                self.device = added[0]

                if self.first_serial_num == "":
                    self.first_serial_num = self.device.serial_number
                    self.wanted_state = PacemakerState.REGISTERED
                elif self.first_serial_num == self.device.serial_number:
                    self.wanted_state = PacemakerState.REGISTERED
                else:
                    self.wanted_state = PacemakerState.CONNECTED

        elif self.current_state == PacemakerState.CONNECTED:
            # The only way to go from CONNECTED to REGISTERED is if the New Patient btn is pressed
            if self.prev_state == PacemakerState.NOT_CONNECTED:
                self.connectStatusChange.emit(PacemakerState.CONNECTED, f"{self.device.serial_number}, press New "
                                                                        f"Patient to register")

            self.handle_removed_device(removed)

        elif self.current_state == PacemakerState.REGISTERED:
            if self.prev_state == PacemakerState.NOT_CONNECTED or self.prev_state == PacemakerState.CONNECTED:
                self.serial.start_serial_comm(self.device.device)
                self.connectStatusChange.emit(PacemakerState.REGISTERED, self.device.serial_number)

            self.handle_removed_device(removed)

        self.old_devices = self.devices
        self.prev_state = self.current_state

    def register_device(self):
        if self.current_state == PacemakerState.CONNECTED:
            self.wanted_state = PacemakerState.REGISTERED
        elif self.device.serial_number:
            self.show_alert("Already registered this pacemaker!")
        elif len(self.devices) > 0:
            self.show_alert("Please unplug and replug the pacemaker you want to connect to!")
        else:
            self.show_alert("Please plug in a pacemaker!")

    def handle_removed_device(self, removed: List[ListPortInfo]):
        if len(removed) > 0 and self.device.serial_number == removed[0].serial_number:
            self.wanted_state = PacemakerState.NOT_CONNECTED
            self.connectStatusChange.emit(PacemakerState.NOT_CONNECTED, removed[0].serial_number)
            self.device = ListPortInfo()

    def send_data_to_pacemaker(self):
        if self.current_state == PacemakerState.REGISTERED:
            print("sending data to pacemaker")
        elif self.current_state == PacemakerState.CONNECTED:
            self.show_alert("Please register the pacemaker first!")
        else:
            self.show_alert("Please plug in a pacemaker!")

    @staticmethod
    def show_alert(msg: str):
        qm = QMessageBox()
        QMessageBox.information(qm, "Connection", msg, QMessageBox.Ok, QMessageBox.Ok)

    @staticmethod
    def filter_devices(data: List[ListPortInfo]) -> List[ListPortInfo]:
        """
        Filter plugged in COM port devices so that we only connect to pacemaker devices
        The SEGGER devices have a Vendor ID of 0x1366 and Product ID of 0x1015

        :param data: list of all plugged in COM port devices
        :return: list of all plugged in pacemaker devices
        """
        return [dev for dev in data if dev.vid == 0x1366 and dev.pid == 0x1015]
