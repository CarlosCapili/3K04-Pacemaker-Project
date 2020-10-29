import time
from typing import List

from PyQt5.QtCore import QThread, pyqtSignal
from serial.tools import list_ports
from serial.tools.list_ports_common import ListPortInfo


class ConnectionHandler(QThread):
    connectStatusChange = pyqtSignal(bool, str)  # connected or not, serial number

    def __init__(self):
        super().__init__()
        print("Connection handler init")

        # self.conn = serial.Serial()
        self.devices = self.old_devices = list_ports.comports()
        self.running = False

    def run(self):
        self.running = True
        while self.running:
            self.check_new_pacemakers()
            time.sleep(1)

    def stop(self):
        self.running = False

    def check_new_pacemakers(self):
        self.devices = list_ports.comports()
        self.devices = self.filter_devices(self.devices)
        added = [f"info:{dev.usb_info()} vid:{dev.vid} pid:{dev.pid}" for dev in self.devices if
                 dev not in self.old_devices]  # difference between new and old
        removed = [f"info:{dev.usb_info()} vid:{dev.vid} pid:{dev.pid}" for dev in self.old_devices if
                   dev not in self.devices]  # difference between old and new
        if added:
            self.connectStatusChange.emit(True, str(self.devices[0].serial_number))
            print(f'added: {added}')
        if removed:
            self.connectStatusChange.emit(False, str(self.devices[0].serial_number))
            print(f'removed: {removed}')
        self.old_devices = self.devices

    @staticmethod
    def filter_devices(data: List[ListPortInfo]) -> List[ListPortInfo]:
        return [dev for dev in data if dev.vid == 1366 and dev.pid == 1015]
