import json
from json import JSONDecodeError
from typing import Callable, Dict

from PyQt5.QtWidgets import QMessageBox


# This class handles the authentication for the DCM
class AuthHandler:
    _on_success: Callable[[str], None]
    _cred_store: Dict[str, str]

    _CREDENTIAL_FILE_PATH = "credentials.json"

    def __init__(self, on_success: Callable[[str], None]):
        print("Auth handler init")

        # Keys are usernames, values are passwords
        # Try and load optionally existing credentials from file
        try:
            with open(self._CREDENTIAL_FILE_PATH, mode='r') as f:
                self._cred_store = json.load(f)
        except (FileNotFoundError, JSONDecodeError):
            self._cred_store = {}

        # Function to call when the authentication (register/login) process is successful
        self._on_success = on_success

    # Handles the login process
    def login(self, username: str, password: str) -> None:
        # Check if username exists
        if username in self._cred_store.keys():
            # Check if password is correct
            if password == self._cred_store[username]:
                self._on_success(username)
            else:
                self._show_alert("Incorrect password!")
        else:
            self._show_alert("Username does not exist, please register instead!")

    # Handles the registration process
    def register(self, username: str, password: str) -> None:
        # Check if username exists
        if username in self._cred_store.keys():
            self._show_alert("Username already exists, please login instead!")
        else:
            # Check if there are already 10 users
            if len(self._cred_store.keys()) == 10:
                self._show_alert("Already 10 users, please login instead!")
            else:
                self._cred_store[username] = password  # add new user to credentials store

                with open(self._CREDENTIAL_FILE_PATH, mode='w+') as f:  # write credential store to file
                    json.dump(self._cred_store, f)

                self._on_success(username)

    @staticmethod
    def _show_alert(msg: str) -> None:
        """
        Displays a critical message with the specified text

        :param msg: the text to show
        """
        qm = QMessageBox()
        QMessageBox.critical(qm, 'Auth', msg, QMessageBox.Ok, QMessageBox.Ok)
