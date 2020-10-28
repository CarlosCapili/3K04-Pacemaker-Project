import json
from typing import Dict

from PyQt5.QtWidgets import QTableWidget

PARAMETERS_FILE_PATH = "parameters.json"


class ParametersHandler:
    params_store: Dict[str, str]
    default_params_store: Dict[str, str]

    def __init__(self, table: QTableWidget):
        print("Parameters handler init")

        keys = [table.verticalHeaderItem(row).text() for row in range(table.rowCount())]
        print(keys)

        self.default_params_store = {key: "" for key in keys}

        try:
            with open(PARAMETERS_FILE_PATH, mode='r') as f:
                self.params_store = json.load(f)
        except FileNotFoundError:
            self.params_store = dict.fromkeys(keys, "")

    # def confirm(self):
