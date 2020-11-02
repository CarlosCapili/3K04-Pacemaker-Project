from typing import Dict

from PyQt5.QtGui import QFont
from PyQt5.QtWidgets import QMessageBox, QTableWidget


# This class handles generating and displaying all the reports for the DCM
class ReportsHandler:
    header: str

    def __init__(self, table: QTableWidget):
        print("Reports handler init")

        # Get report header data from the About section, so that we're not hard-coding values multiple times
        header = {table.verticalHeaderItem(row).text(): table.item(row, 0).text() for row in range(table.rowCount())}
        self.header = self._format_params(header)

    # Handles the generation and presentation of the electrogram report, not implemented yet
    def generate_egram(self, params: Dict[str, str]) -> None:
        print("generating egram report")
        print(params["Pacing Mode"])

    # Handles the generation and presentation of the bradycardia report
    def generate_brady(self, params: Dict[str, str]) -> None:
        print("generating brady report")
        report = "{0}{1}".format(self.header, self._format_params(params))
        self._show_report(report)

    # Handles the generation and presentation of the bradycardia report, may get removed
    def generate_temp(self, params: Dict[str, str]) -> None:
        print("generating temp report")
        report = "{0}{1}".format(self.header, self._format_params(params))
        print(report)
        self._show_report(report)

    @staticmethod
    def _format_params(params: Dict[str, str]) -> str:
        """
        Formats the dictionary of parameters as a string, aligned to the colon, with each parameter name/value on a
        new line. No param name is greater than 23 characters so we do left and right alignments in a 25 character long
        block for even spacing.

        :param params: dict of params, with param names as keys and param values as values
        :return: string of evenly spaced parameters separated by a colon, with each param on a new line
        """
        return "".join([f"{key:>25}: {value:<25}\n" for key, value in params.items()])

    @staticmethod
    def _show_report(report: str) -> None:
        """
        Shows a customized message box with the specified text. The font is set to "Consolas" because it is a
        monospaced font.

        :param report: the report text to show
        """
        qm = QMessageBox(text=report)
        qm.setWindowTitle("Reports")
        qm.setFont(QFont("Consolas", 11))
        qm.exec_()
