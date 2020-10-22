import json
from typing import Dict

from PyQt5.QtWidgets import QMessageBox

CREDENTIAL_FILE_PATH = "credentials.json"


class AuthHandler:
    cred_store: Dict[str, str]

    def __init__(self):
        print("Login handler init")

        try:
            with open(CREDENTIAL_FILE_PATH, mode='r') as f:
                self.cred_store = json.load(f)
        except FileNotFoundError:
            self.cred_store = {}

    def login(self, username: str, password: str):
        print(f"Login credentials: {username} | {password}")

        if username in self.cred_store.keys():
            if password == self.cred_store[username]:
                print("Welcome back.")
                # SHOW DCM
            else:
                print("Incorrect password!")
                self.show_alert("Incorrect password!")
        else:
            print("Username does not exist, please register instead!")
            self.show_alert("Username does not exist, please register instead!")

    def register(self, username: str, password: str):
        print(f"Register credentials: {username} | {password}")

        if username in self.cred_store.keys():
            print("Username already exists, please login instead!")
            self.show_alert("Username already exists, please login instead!")
        else:
            if len(self.cred_store.keys()) == 10:
                print("Already 10 users, please login instead!")
                self.show_alert("Already 10 users, please login instead!")
            else:
                self.cred_store[username] = password

                with open(CREDENTIAL_FILE_PATH, mode='a+') as f:
                    json.dump(self.cred_store, f)

                # SHOW DCM

    @staticmethod
    def show_alert(msg: str):
        alert = QMessageBox(text=msg)
        alert.exec_()
