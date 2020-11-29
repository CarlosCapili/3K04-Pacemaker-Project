import json
from json import JSONDecodeError
from typing import Dict, List, Union

from PyQt5.QtWidgets import QMessageBox, QTableWidget

from custom_qt.delegates import ComboBoxDelegate, DoubleSpinBoxDelegate, SpinBoxDelegate


# This class handles the parameters for the DCM
class ParametersHandler:
    _table: QTableWidget
    _params_per_mode: Dict[str, List[str]]
    _object_per_param: Dict[str, Union[SpinBoxDelegate, DoubleSpinBoxDelegate, ComboBoxDelegate]]
    _default_params_store: Dict[str, str]
    _units: Dict[str, str]
    _user_params_store: Dict[str, str]
    _username: str
    _params_store: Dict[str, Dict[str, str]]

    _PARAMETERS_FILE_PATH = "parameters.json"

    def __init__(self, table: QTableWidget):
        print("Parameters handler init")
        self._table = table
        # self.table.verticalHeader().setSectionResizeMode(QHeaderView.Stretch)

        # Create dictionary of parameters per pacing mode
        self._params_per_mode = {
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

        # Create list of values for Activity Threshold
        self._act_thresh = ["V-Low", "Low", "Med-Low", "Med", "Med-High", "High", "V-High"]

        # Create dictionary of table delegate per parameter
        self._object_per_param = {
            "Lower Rate Limit": SpinBoxDelegate(30, 175, 5, "ppm", parent=table),
            "Upper Rate Limit": SpinBoxDelegate(50, 175, 5, "ppm", parent=table),
            "Maximum Sensor Rate": SpinBoxDelegate(50, 175, 5, "ppm", parent=table),
            "Fixed AV Delay": SpinBoxDelegate(70, 300, 10, "ms", parent=table),
            "Atrial Amplitude": DoubleSpinBoxDelegate(0, 5, 0.1, "V", parent=table),
            "Atrial Pulse Width": SpinBoxDelegate(1, 30, 1, "ms", parent=table),
            "Atrial Sensitivity": DoubleSpinBoxDelegate(0, 5, 0.1, "V", parent=table),
            "Ventricular Amplitude": DoubleSpinBoxDelegate(0, 5, 0.1, "V", parent=table),
            "Ventricular Pulse Width": SpinBoxDelegate(1, 30, 1, "ms", parent=table),
            "Ventricular Sensitivity": DoubleSpinBoxDelegate(0, 5, 0.1, "V", parent=table),
            "ARP": SpinBoxDelegate(150, 500, 10, "ms", parent=table),
            "VRP": SpinBoxDelegate(150, 500, 10, "ms", parent=table),
            "PVARP": SpinBoxDelegate(150, 500, 10, "ms", parent=table),
            "Activity Threshold": ComboBoxDelegate(self._act_thresh, parent=table),
            "Reaction Time": SpinBoxDelegate(10, 50, 10, "sec", parent=table),
            "Response Factor": SpinBoxDelegate(1, 16, 1, "", parent=table),
            "Recovery Time": SpinBoxDelegate(2, 16, 1, "min", parent=table)}

        # Keys are the parameter name, values are the param value or param units respectively
        self._default_params_store = {}
        self._units = {}

        # Dict that stores the parameters for a specific user (stored in username), keys are the parameter name,
        # values are the param value
        self._user_params_store = {}
        self._username = ""

        # Get GUI default param values from table, so that we're not hard-coding values multiple times. Param values
        # in column 0, units in column 1.
        for row in range(table.rowCount()):
            key = table.verticalHeaderItem(row).text()
            self._default_params_store[key] = table.item(row, 0).text()
            self._units[key] = self._object_per_param[key].unit if not isinstance(self._object_per_param[key],
                                                                                  ComboBoxDelegate) else ""
            table.setItemDelegateForRow(row, self._object_per_param[key])
            table.openPersistentEditor(table.item(row, 0))

        # Try and optionally load existing parameters from file and update GUI with those saved values
        self._params_store = {}
        try:
            with open(self._PARAMETERS_FILE_PATH, mode='r') as f:
                self._params_store.update(json.load(f))
        except (FileNotFoundError, JSONDecodeError):
            pass

    # Update the parameter values to the user-specific ones based on the user that is authenticated
    def update_params_on_user_auth(self, username: str):
        self._username = username
        self._user_params_store = self._params_store.get(username, self._default_params_store)
        self._update_params_gui()

    # When confirm is clicked, update param store and write the values to file
    def confirm(self) -> None:
        self._user_params_store = {self._table.verticalHeaderItem(row).text(): self._table.item(row, 0).text() for row
                                   in range(self._table.rowCount())}
        self._update_params_file()

    # When reset is clicked, prompt user if they're sure, and optionally load GUI defaults and update file and GUI
    def reset(self) -> None:
        qm = QMessageBox()
        response = QMessageBox.question(qm, "Parameters", "Are you sure you want to reset all the values?",
                                        QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if response == QMessageBox.Yes:
            self._user_params_store = self._default_params_store
            self._update_params_file()
            self._update_params_gui()

    # Update which rows/params are visible in the table GUI based on the pacing mode
    def update_row_visibility(self, pacing_mode: str) -> None:
        params_to_show = self._params_per_mode[pacing_mode]

        for row in range(self._table.rowCount()):
            if self._table.verticalHeaderItem(row).text() in params_to_show:
                self._table.showRow(row)
            else:
                self._table.hideRow(row)

    # Write params store to file, creating a new one if it doesn't exist
    def _update_params_file(self) -> None:
        with open(self._PARAMETERS_FILE_PATH, mode='w+') as f:
            self._params_store[self._username] = self._user_params_store
            json.dump(self._params_store, f)

    # Update the parameters GUI table with the values from the params store
    def _update_params_gui(self) -> None:
        for row in range(self._table.rowCount()):
            self._table.item(row, 0).setText(self._user_params_store[self._table.verticalHeaderItem(row).text()])

    # Return a pacing mode dependent dict of parameters with the names as keys, and param values with units as values
    def filter_params(self, pace_mode: str) -> Dict[str, str]:
        mode_params = {key: f"{self._user_params_store[key]}{self._units[key]}" for key in
                       self._params_per_mode[pace_mode]}
        mode_params["Pacing Mode"] = pace_mode
        return mode_params

    # Return all the parameters, casted to their respective data type
    def get_params(self, pace_mode: int) -> Dict[str, Union[int, float]]:
        typed_params = {"Pacing Mode": pace_mode}

        for key, value in self._user_params_store.items():
            if isinstance(self._object_per_param[key], SpinBoxDelegate):
                typed_params[key] = int(value)
            elif isinstance(self._object_per_param[key], DoubleSpinBoxDelegate):
                typed_params[key] = float(value)
            elif isinstance(self._object_per_param[key], ComboBoxDelegate):
                typed_params[key] = self._act_thresh.index(value)

        return typed_params
