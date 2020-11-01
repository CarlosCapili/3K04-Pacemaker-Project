import json
from json import JSONDecodeError
from typing import Dict, List

from PyQt5.QtWidgets import QMessageBox, QTableWidget

PARAMETERS_FILE_PATH = "parameters.json"


class ParametersHandler:
    table: QTableWidget
    units: Dict[str, str]
    params_store: Dict[str, str]
    default_params_store: Dict[str, str]
    params_per_mode: Dict[str, List[str]]

    def __init__(self, table: QTableWidget):
        print("Parameters handler init")
        self.table = table

        self.params_per_mode = {
            'AOO': ["Lower Rate Limit", "Upper Rate Limit", "Atrial Amplitude", "Atrial Pulse Width"],
            'AAI': ["Lower Rate Limit", "Upper Rate Limit", "Atrial Amplitude", "Atrial Pulse Width", "ARP"],
            'VOO': ["Lower Rate Limit", "Upper Rate Limit", "Ventricular Amplitude", "Ventricular Pulse Width"],
            'VVI': ["Lower Rate Limit", "Upper Rate Limit", "Ventricular Amplitude", "Ventricular Pulse Width", "VRP"]}

        self.default_params_store = {}
        self.units = {}

        for row in range(table.rowCount()):
            key = table.verticalHeaderItem(row).text()
            self.default_params_store[key] = table.item(row, 0).text()
            self.units[key] = table.item(row, 1).text()

        try:
            with open(PARAMETERS_FILE_PATH, mode='r') as f:
                self.params_store = json.load(f)
                self.update_params_gui()
        except (FileNotFoundError, JSONDecodeError):
            self.params_store = self.default_params_store

    def confirm(self) -> None:
        self.params_store = {self.table.verticalHeaderItem(row).text(): self.table.item(row, 0).text() for row in
                             range(self.table.rowCount())}
        self.update_params_file()

    def reset(self) -> None:
        qm = QMessageBox()
        ret = QMessageBox.question(qm, "Parameters", "Are you sure you want to reset all the values?",
                                   QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if ret == QMessageBox.Yes:
            self.params_store = self.default_params_store
            self.update_params_file()
            self.update_params_gui()

    def update_params_file(self) -> None:
        with open(PARAMETERS_FILE_PATH, mode='w+') as f:
            json.dump(self.params_store, f)

    def update_params_gui(self) -> None:
        for row in range(self.table.rowCount()):
            self.table.item(row, 0).setText(self.params_store[self.table.verticalHeaderItem(row).text()])

    def filter_params(self, pacing_mode: str) -> Dict[str, str]:
        ret_params = {key: f"{self.params_store[key]}{self.units[key]}" for key in self.params_per_mode[pacing_mode]}
        ret_params["Pacing Mode"] = pacing_mode
        return ret_params
