import itertools
from datetime import datetime
from typing import Dict

from PyQt5.QtCore import QFileInfo
from PyQt5.QtGui import QFont, QPainter
from PyQt5.QtPrintSupport import QPrinter
from PyQt5.QtWidgets import QDialog, QFileDialog, QMessageBox

from py_ui_files.egram_report import Ui_Dialog


# This class handles generating and displaying all the reports for the DCM
class ReportsHandler:
    _egram_report_ui: Ui_Dialog
    _report_gen_time: str

    def __init__(self, egram_report_ui: Ui_Dialog):
        print("Reports handler init")
        self._egram_report_ui = egram_report_ui
        self._report_gen_time = datetime.now().strftime('%Y-%m-%d %H:%M:%S')  # used for egram report pdf file name

    # Handles the generation and presentation of the electrogram report
    def generate_egram(self, header: Dict[str, str], atri_snap, vent_snap) -> None:
        header["Report name"] = "Electrogram"
        now = datetime.now()
        header["Date and Time"] = now.strftime('%Y-%m-%d %H:%M:%S')
        self._report_gen_time = now.strftime("%Y_%m_%d-%H_%M_%S")

        i = iter(header.items())
        # right label always has less than or equal the number of elements of the left label
        right, left = dict(itertools.islice(i, len(header) // 2)), dict(i)

        self._egram_report_ui.header_label_left.setText(self._plain_format_params(left))
        self._egram_report_ui.header_label_right.setText(self._plain_format_params(right))

        self._egram_report_ui.atri_label.setPixmap(atri_snap)
        self._egram_report_ui.vent_label.setPixmap(vent_snap)

    # Export the egram report as a pdf, for printing
    def export_pdf(self, widget: QDialog):
        # Get user-specified file path
        file_path, _ = QFileDialog.getSaveFileName(widget, "Export Egram Report",
                                                   f"egram_report_{self._report_gen_time}.pdf",
                                                   "PDF files (.pdf);;All Files ()")

        # If the user specified a file path
        if file_path:
            # Add .pdf suffix if it doesn't exist
            if QFileInfo(file_path).suffix() == "":
                file_path += ".pdf"

            # Set up printer and painter to create pdf file
            printer = QPrinter(QPrinter.ScreenResolution)
            printer.setOrientation(QPrinter.Landscape)
            printer.setOutputFormat(QPrinter.PdfFormat)
            printer.setOutputFileName(file_path)
            printer.setPageMargins(0, 0, 0, 0, QPrinter.Point)
            painter = QPainter(printer)

            # Scale widget
            x_scale = printer.pageRect().width() * 1.0 / widget.width()
            y_scale = printer.pageRect().height() * 1.0 / widget.height()
            scale = min(x_scale, y_scale)
            painter.translate(printer.paperRect().center())
            painter.scale(scale, scale)
            painter.translate(-widget.width() / 2, -widget.height() / 2)

            # Dump the contents of the egram report widget to the pdf, and write it to disk
            widget.render(painter)
            painter.end()

    # Handles the generation and presentation of the bradycardia report
    def generate_brady(self, header: Dict[str, str], params: Dict[str, str]) -> None:
        header["Report name"] = "Bradycardia"
        now = datetime.now()
        header["Date and Time"] = now.strftime('%Y-%m-%d %H:%M:%S')
        self._report_gen_time = now.strftime("%Y_%m_%d-%H_%M_%S")
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
    def _plain_format_params(params: Dict[str, str]) -> str:
        """
        Formats the dictionary of parameters as a string, with each parameter name/value on a new line.

        :param params: dict of params, with param names as keys and param values as values
        :return: string of parameters separated by a colon, with each param on a new line
        """
        return "".join([f"{key}: {value}\n" for key, value in params.items()])

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
