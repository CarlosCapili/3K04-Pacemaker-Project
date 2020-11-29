import datetime
from typing import Dict

from PyQt5.QtGui import QFont
from PyQt5.QtWidgets import QMessageBox

from py_ui_files.egram_report import Ui_Dialog


# This class handles generating and displaying all the reports for the DCM
class ReportsHandler:
    def __init__(self, egram_report_ui: Ui_Dialog):
        print("Reports handler init")
        self._egram_report_ui = egram_report_ui

    # Handles the generation and presentation of the electrogram report, not implemented yet
    def generate_egram(self, header: Dict[str, str], atri_snap, vent_snap) -> None:
        header["Report name"] = "Electrogram"
        header["Date and Time"] = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
        # self._egram_report_ui.header_label_left.setText(self._format_params(header.))
        self._egram_report_ui.atri_label.setPixmap(atri_snap)
        self._egram_report_ui.vent_label.setPixmap(vent_snap)

    # Handles the generation and presentation of the bradycardia report
    def generate_brady(self, header: Dict[str, str], params: Dict[str, str]) -> None:
        header["Report name"] = "Bradycardia"
        header["Date and Time"] = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
        report = "{0}{1}".format(self._format_params(header), self._format_params(params))
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
