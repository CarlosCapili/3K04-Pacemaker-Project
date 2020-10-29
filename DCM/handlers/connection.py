import time

import serial
from PyQt5.QtCore import QThread
from serial.tools import list_ports


class ConnectionHandler(QThread):
    def __init__(self):
        super().__init__()
        print("Connection handler init")

        self.conn = serial.Serial()
        self.devices = self.old_devices = self.enumerate_serial_devices()
        self.running = False

    def run(self):
        self.running = True
        while self.running:
            # print("com ports", list_ports.comports())
            self.check_new_devices()
            time.sleep(1)

    @staticmethod
    def enumerate_serial_devices() -> set:
        return set([item for item in list_ports.comports()])

    def check_new_devices(self):
        self.devices = self.enumerate_serial_devices()
        added = self.devices.difference(self.old_devices)
        removed = self.old_devices.difference(self.devices)
        if added:
            print(f'added: {added}')
        if removed:
            print(f'removed: {removed}')
        self.old_devices = self.devices

    def stop(self):
        self.running = False
