import json
from typing import Dict, List

from PyQt5.QtWidgets import QTableWidget

PARAMETERS_FILE_PATH = "parameters.json"


class ParametersHandler:
    params_store: Dict[str, str]
    default_params_store: Dict[str, str]
    params_per_mode: Dict[str, List[str]]

    def __init__(self, table: QTableWidget):
        print("Parameters handler init")

        self.params_per_mode = {
            "AOO": ['Lower Rate Limit', 'Upper Rate Limit', 'Atrial Amplitude', 'Atrial Pulse Width'],
            "AAI": ['Lower Rate Limit', 'Upper Rate Limit', 'Atrial Amplitude', 'Atrial Pulse Width', 'ARP'],
            "VOO": ['Lower Rate Limit', 'Upper Rate Limit', 'Ventricular Amplitude', 'Ventricular Pulse Width'],
            "VVI": ['Lower Rate Limit', 'Upper Rate Limit', 'Ventricular Amplitude', 'Ventricular Pulse Width', 'VRP']}

        self.keys = [table.verticalHeaderItem(row).text() for row in range(table.rowCount())]
        print(self.keys)

        self.default_params_store = {key: "" for key in self.keys}

        try:
            with open(PARAMETERS_FILE_PATH, mode='r') as f:
                self.params_store = json.load(f)
        except FileNotFoundError:
            self.params_store = {key: "" for key in self.keys}

    def confirm(self):
        print("Writing values to file")
        with open(PARAMETERS_FILE_PATH, mode='w+') as f:
            json.dump(self.params_store, f)
