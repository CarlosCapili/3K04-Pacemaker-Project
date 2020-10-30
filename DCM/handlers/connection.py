import queue
from enum import Enum, unique
from time import sleep
from typing import List

from PyQt5.QtCore import QThread, pyqtSignal
from serial import Serial
from serial.tools import list_ports
from serial.tools.list_ports_common import ListPortInfo


@unique
class PacemakerState(Enum):
    NOT_CONNECTED = 1
    CONNECTED = 2
    REGISTERED = 3


# https://github.com/pyserial/pyserial/issues/216#issuecomment-369414522
class SerialHandler(QThread):
    def __init__(self):
        super().__init__()
        print("Serial handler init")

        self.running = False
        self.buf = bytearray()
        self.conn = Serial(baudrate=1152000)
        self.in_q = queue.Queue()

    def run(self):
        self.running = True

        while self.running:
            if self.conn.is_open:
                line = self.readline().decode().split(", ")  # read one line
                print(f"received from pacemaker: {line}")
                self.in_q.put(line)
            else:
                sleep(1)

    def start_serial_comm(self, port: str):
        print("opening serial port with pacemaker")
        self.conn.port = port
        # self.conn.open()

    def readline(self):
        i = self.buf.find(b"\n")

        if i >= 0:
            r = self.buf[:i + 1]
            self.buf = self.buf[i + 1:]
            return r

        while self.running:
            i = max(1, min(2048, self.conn.in_waiting))
            data = self.conn.read(i)
            i = data.find(b"\n")

            if i >= 0:
                r = self.buf + data[:i + 1]
                self.buf[0:] = data[i + 1:]
                return r
            else:
                self.buf.extend(data)


class ConnectionHandler(QThread):
    conn: Serial
    reg_serial_num: str
    running: bool
    old_devices: List[ListPortInfo]
    devices: List[ListPortInfo]

    connectStatusChange: pyqtSignal = pyqtSignal(PacemakerState, str)  # (not conn, conn, reg), serial number

    def __init__(self):
        super().__init__()
        print("Connection handler init")

        self.running = False
        self.devices = self.old_devices = self.filter_devices(list_ports.comports())
        self.reg_serial_num = ""

        if len(self.devices) > 0:
            device = self.devices[0]
            self.reg_serial_num = device.serial_number

            self.connectStatusChange.emit(PacemakerState.REGISTERED, device.serial_number)
        else:
            self.connectStatusChange.emit(False, self.devices[0].serial_number)

    def run(self):
        self.running = True

        while self.running:
            self.check_new_pacemakers()
            sleep(0.5)

    def stop(self):
        self.running = False

    def check_new_pacemakers(self):
        self.devices = self.filter_devices(list_ports.comports())
        added = [dev for dev in self.devices if dev not in self.old_devices]  # difference between new and old
        removed = [dev for dev in self.old_devices if dev not in self.devices]  # difference between old and new

        if len(added) > 0:
            self.connectStatusChange.emit(True, added[0].serial_number)
            print(f'added: {[f"info:{dev.usb_info()}" for dev in added]}')
        if len(removed) > 0:
            self.connectStatusChange.emit(False, removed[0].serial_number)
            print(f'removed: {[f"info:{dev.usb_info()}" for dev in removed]}')

        self.old_devices = self.devices

    @staticmethod
    def filter_devices(data: List[ListPortInfo]) -> List[ListPortInfo]:
        """
        Filter plugged in COM port devices so that we only connect to pacemaker devices
        The SEGGER devices have a Vendor ID of 0x1366 and Product ID of 0x1015

        :param data: list of all plugged in COM port devices
        :return: list of all plugged in pacemaker devices
        """
        return [dev for dev in data if dev.vid == 0x1366 and dev.pid == 0x1015]
