import time

from PyQt5.QtCore import QThread
from serial.tools import list_ports


class ConnectionHandler(QThread):
    def __init__(self):
        super().__init__()
        print("Connection handler init")

        # self.conn = serial.Serial()
        self.devices = self.old_devices = list_ports.comports()
        self.running = False

    def run(self):
        self.running = True
        while self.running:
            self.check_new_devices()
            time.sleep(1)

    def check_new_devices(self):
        self.devices = list_ports.comports()
        added = [
            f"info:{dev.usb_info()} dev:{dev.device} int:{dev.interface} man:{dev.manufacturer} prod:{dev.product} desc:{dev.description}"
            for dev in self.devices if dev not in self.old_devices]  # difference between new and old
        removed = [
            f"info:{dev.usb_info()} dev:{dev.device} int:{dev.interface} man:{dev.manufacturer} prod:{dev.product} desc:{dev.description}"
            for dev in self.old_devices if dev not in self.devices]  # difference between old and new
        if added:
            print(f'added: {added}')
        if removed:
            print(f'removed: {removed}')
        self.old_devices = self.devices

    def stop(self):
        self.running = False
