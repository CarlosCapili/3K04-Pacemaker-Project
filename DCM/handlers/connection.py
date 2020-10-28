import serial


class ConnectionHandler:
    def __init__(self):
        print("Connection handler init")

        self.conn = serial.Serial()
