from typing import Dict

from PyQt5.QtGui import QFont
from PyQt5.QtWidgets import QMessageBox, QTableWidget


class ReportsHandler:
    def __init__(self, table: QTableWidget):
        print("Reports handler init")

        header = {table.verticalHeaderItem(row).text(): table.item(row, 0).text() for row in range(table.rowCount())}
        self.header = self.format_params(header)

    def generate_egram(self, params: Dict[str, str]):
        print("generating egram report")
        print(params["Pacing Mode"])

    def generate_brady(self, params: Dict[str, str]):
        print("generating brady report")
        report = "{0}{1}".format(self.header, self.format_params(params))
        self.show_report(report)

    def generate_temp(self, params: Dict[str, str]):
        print("generating temp report")
        report = "{0}{1}".format(self.header, self.format_params(params))
        print(report)
        self.show_report(report)

    @staticmethod
    def format_params(params: Dict[str, str]):
        return "".join([f'{key:>25}: {value:<25}\n' for key, value in params.items()])

    @staticmethod
    def show_report(report: str):
        qm = QMessageBox(text=report)
        qm.setWindowTitle("Reports")
        qm.setFont(QFont("Consolas", 11))
        qm.exec_()
