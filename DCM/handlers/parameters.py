import json
from json import JSONDecodeError
from typing import Dict, List

from PyQt5.QtWidgets import QMessageBox, QTableWidget

PARAMETERS_FILE_PATH = "parameters.json"


# This class handles the parameters for the DCM
class ParametersHandler:
    table: QTableWidget
    params_per_mode: Dict[str, List[str]]
    default_params_store: Dict[str, str]
    units: Dict[str, str]
    params_store: Dict[str, str]

    def __init__(self, table: QTableWidget):
        print("Parameters handler init")
        self.table = table

        # Create dictionary of parameters per pacing mode
        self.params_per_mode = {
            'AOO': ["Lower Rate Limit", "Upper Rate Limit", "Atrial Amplitude", "Atrial Pulse Width"],
            'AAI': ["Lower Rate Limit", "Upper Rate Limit", "Atrial Amplitude", "Atrial Pulse Width",
                    "Atrial Sensitivity", "ARP", "PVARP"],
            'VOO': ["Lower Rate Limit", "Upper Rate Limit", "Ventricular Amplitude", "Ventricular Pulse Width"],
            'VVI': ["Lower Rate Limit", "Upper Rate Limit", "Ventricular Amplitude", "Ventricular Pulse Width",
                    "Ventricular Sensitivity", "VRP"],
            'DOO': ["Lower Rate Limit", "Upper Rate Limit", "Fixed AV Delay", "Atrial Amplitude", "Atrial Pulse Width",
                    "Ventricular Amplitude", "Ventricular Pulse Width"],
            'AOOR': ["Lower Rate Limit", "Upper Rate Limit", "Maximum Sensor Rate", "Atrial Amplitude",
                     "Atrial Pulse Width", "Activity Threshold", "Reaction Time", "Response Factor",
                     "Recovery Time"],
            'AAIR': ["Lower Rate Limit", "Upper Rate Limit", "Maximum Sensor Rate", "Atrial Amplitude",
                     "Atrial Pulse Width", "Atrial Sensitivity", "ARP", "PVARP", "Activity Threshold", "Reaction Time",
                     "Response Factor", "Recovery Time"],
            'VOOR': ["Lower Rate Limit", "Upper Rate Limit", "Maximum Sensor Rate", "Ventricular Amplitude",
                     "Ventricular Pulse Width", "Activity Threshold", "Reaction Time", "Response Factor",
                     "Recovery Time"],
            'VVIR': ["Lower Rate Limit", "Upper Rate Limit", "Maximum Sensor Rate", "Ventricular Amplitude",
                     "Ventricular Pulse Width", "Ventricular Sensitivity", "VRP", "Activity Threshold", "Reaction Time",
                     "Response Factor", "Recovery Time"],
            'DOOR': ["Lower Rate Limit", "Upper Rate Limit", "Maximum Sensor Rate", "Fixed AV Delay",
                     "Atrial Amplitude", "Atrial Pulse Width", "Ventricular Amplitude", "Ventricular Pulse Width",
                     "Activity Threshold", "Reaction Time", "Response Factor", "Recovery Time"]}

        # Keys are the parameter name, values are the param value or param units respectively
        self.default_params_store = {}
        self.units = {}

        # Get GUI default param values from table, so that we're not hard-coding values multiple times. Param values
        # in column 0, units in column 1.
        for row in range(table.rowCount()):
            key = table.verticalHeaderItem(row).text()
            self.default_params_store[key] = table.item(row, 0).text()
            self.units[key] = table.item(row, 1).text()

        # Try and optionally load existing parameters from file and update GUI with those saved values
        try:
            with open(PARAMETERS_FILE_PATH, mode='r') as f:
                self.params_store = json.load(f)
                self._update_params_gui()
        except (FileNotFoundError, JSONDecodeError):
            self.params_store = self.default_params_store

    # When confirm is clicked, update param store and write the values to file
    def confirm(self) -> None:
        self.params_store = {self.table.verticalHeaderItem(row).text(): self.table.item(row, 0).text() for row in
                             range(self.table.rowCount())}
        self._update_params_file()

    # When reset is clicked, prompt user if they're sure, and optionally load GUI defaults and update file and GUI
    def reset(self) -> None:
        qm = QMessageBox()
        response = QMessageBox.question(qm, "Parameters", "Are you sure you want to reset all the values?",
                                        QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if response == QMessageBox.Yes:
            self.params_store = self.default_params_store
            self._update_params_file()
            self._update_params_gui()

    # Write params store to file, creating a new one if it doesn't exist
    def _update_params_file(self) -> None:
        with open(PARAMETERS_FILE_PATH, mode='w+') as f:
            json.dump(self.params_store, f)

    # Update the parameters GUI table with the values from the params store
    def _update_params_gui(self) -> None:
        for row in range(self.table.rowCount()):
            self.table.item(row, 0).setText(self.params_store[self.table.verticalHeaderItem(row).text()])

    # Return a pacing mode dependent dict of parameters with the names as keys, and param values with units as values
    def filter_params(self, pacing_mode: str) -> Dict[str, str]:
        mode_params = {key: f"{self.params_store[key]}{self.units[key]}" for key in self.params_per_mode[pacing_mode]}
        mode_params["Pacing Mode"] = pacing_mode
        return mode_params
