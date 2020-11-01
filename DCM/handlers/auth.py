import json
from collections import Callable
from json import JSONDecodeError
from typing import Dict

from PyQt5.QtWidgets import QMessageBox

CREDENTIAL_FILE_PATH = "credentials.json"


# This class handles the authentication for the DCM
class AuthHandler:
    on_success: Callable[[], None]
    cred_store: Dict[str, str]

    def __init__(self, on_success: Callable[[], None]):
        print("Login handler init")

        # Keys are usernames, values are passwords
        # Try and load optionally existing credentials from file
        try:
            with open(CREDENTIAL_FILE_PATH, mode='r') as f:
                self.cred_store = json.load(f)
        except (FileNotFoundError, JSONDecodeError):
            self.cred_store = {}

        # Function to call when the authentication (register/login) process is successful
        self.on_success = on_success

    # Handles the login process
    def login(self, username: str, password: str) -> None:
        # Check if username exists
        if username in self.cred_store.keys():
            # Check if password is correct
            if password == self.cred_store[username]:
                print("Welcome back.")
                self.on_success()
            else:
                print("Incorrect password!")
                self.show_alert("Incorrect password!")
        else:
            print("Username does not exist, please register instead!")
            self.show_alert("Username does not exist, please register instead!")

    # Handles the registration process
    def register(self, username: str, password: str) -> None:
        # Check if username exists
        if username in self.cred_store.keys():
            print("Username already exists, please login instead!")
            self.show_alert("Username already exists, please login instead!")
        else:
            # Check if there are already 10 users
            if len(self.cred_store.keys()) == 10:
                print("Already 10 users, please login instead!")
                self.show_alert("Already 10 users, please login instead!")
            else:
                self.cred_store[username] = password  # add new user to credentials store

                with open(CREDENTIAL_FILE_PATH, mode='w+') as f:  # write credential store to file
                    json.dump(self.cred_store, f)

                self.on_success()

    @staticmethod
    def show_alert(msg: str) -> None:
        """
        Displays a critical message with the specified text

        :param msg: the text to show
        """
        qm = QMessageBox()
        QMessageBox.critical(qm, 'Auth', msg, QMessageBox.Ok, QMessageBox.Ok)
