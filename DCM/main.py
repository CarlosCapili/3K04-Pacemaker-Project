from typing import Dict

from PyQt5.QtCore import Qt
from PyQt5.QtGui import QColor, QPalette
from PyQt5.QtWidgets import (QApplication, QDialog, QMainWindow, QMessageBox, QStackedWidget, QTableWidget)

from handlers.auth import AuthHandler
from handlers.connection import ConnectionHandler, PacemakerState
from handlers.graphs import GraphsHandler
from handlers.parameters import ParametersHandler
from handlers.reports import ReportsHandler
from py_ui_files import (about, dcm, egram_report, parameters, reports, welcomescreen)  # auto-generated files
from py_ui_files.about import Ui_aboutWindow
from py_ui_files.dcm import Ui_MainWindow
from py_ui_files.egram_report import Ui_Dialog
from py_ui_files.parameters import Ui_parametersWindow
from py_ui_files.reports import Ui_ReportsWindow
from py_ui_files.welcomescreen import Ui_Welcome


# This class handles all the linking between the frontend (GUI/UI) and the backend (handlers)
class MainController:
    palette: QPalette
    _welcome_gui: QStackedWidget
    _welcome_ui: Ui_Welcome
    _dcm_gui: QMainWindow
    _dcm_ui: Ui_MainWindow
    _about_gui: QDialog
    _about_ui: Ui_aboutWindow
    _about_table: QTableWidget
    _about_header: Dict[str, str]
    _params_gui: QDialog
    _params_ui: Ui_parametersWindow
    _reports_gui: QDialog
    _reports_ui: Ui_ReportsWindow
    _egram_report_gui: QDialog
    _egram_report_ui: Ui_Dialog
    _auth: AuthHandler
    _conn: ConnectionHandler
    _params: ParametersHandler
    _reports: ReportsHandler
    _graphs: GraphsHandler

    def __init__(self):
        # Set theme to dark mode
        self.palette = QPalette()
        self.palette.setColor(QPalette.Window, QColor(53, 53, 53))
        self.palette.setColor(QPalette.WindowText, Qt.white)

        # Setup welcome screen UI from auto-generated file
        self._welcome_gui = QStackedWidget()
        self._welcome_ui = welcomescreen.Ui_Welcome()
        self._welcome_ui.setupUi(self._welcome_gui)

        # Setup dcm screen UI from auto-generated file
        self._dcm_gui = QMainWindow()
        self._dcm_ui = dcm.Ui_MainWindow()
        self._dcm_ui.setupUi(self._dcm_gui)
        for i, button in enumerate(self._dcm_ui.pacing_mode_group.buttons()):
            self._dcm_ui.pacing_mode_group.setId(button, i)

        # Setup about screen UI from auto-generated file
        self._about_gui = QDialog()
        self._about_ui = about.Ui_aboutWindow()
        self._about_ui.setupUi(self._about_gui)
        self._about_table = self._about_ui.tableWidget
        self._about_header = {self._about_table.verticalHeaderItem(row).text(): self._about_table.item(row, 0).text()
                              for row in range(self._about_table.rowCount())}

        # Setup parameter screen UI from auto-generated file
        self._params_gui = QDialog()
        self._params_ui = parameters.Ui_parametersWindow()
        self._params_ui.setupUi(self._params_gui)

        # Setup reports screen UI from auto-generated file
        self._reports_gui = QDialog()
        self._reports_ui = reports.Ui_ReportsWindow()
        self._reports_ui.setupUi(self._reports_gui)

        # Setup egram screen UI from auto-generated file
        self._egram_report_gui = QDialog()
        self._egram_report_ui = egram_report.Ui_Dialog()
        self._egram_report_ui.setupUi(self._egram_report_gui)

        # Initialize separate handlers for authentication, pacemaker connection, parameters, reports and graphs
        self._auth = AuthHandler(self.show_dcm)
        self._conn = ConnectionHandler()
        self._params = ParametersHandler(self._params_ui.tableWidget)
        self._reports = ReportsHandler(self._egram_report_ui)
        self._graphs = GraphsHandler(self._dcm_ui.atrial_plots, self._dcm_ui.vent_plots, data_size=2001)

        # Link elements to actions
        self.link_welcome_buttons()
        self.link_dcm_elements()
        self.link_reports_buttons()
        self.link_params_buttons()

        # Start connection thread
        self._conn.connect_status_change.connect(self.handle_pace_conn)
        self._conn.serial.ecg_data_update.connect(self._graphs.update_data)
        self._conn.serial.params_received.connect(self._show_alert)
        self._conn.start()

        # Update params GUI table to show default pacing mode params
        self._params.update_row_visibility(self._dcm_ui.pacing_mode_group.checkedButton().text())

        # Show welcome screen GUI
        self._welcome_gui.show()

    # Link welcome screen ui elements to their respective functions
    def link_welcome_buttons(self) -> None:
        # Welcome screen
        # show register and login screens when those buttons are pressed, respectively
        self._welcome_ui.reg_btn.clicked.connect(lambda: self._welcome_gui.setCurrentIndex(1))
        self._welcome_ui.log_btn.clicked.connect(lambda: self._welcome_gui.setCurrentIndex(2))

        # Register screen
        # register user and go back to welcome screen when those buttons are pressed, respectively
        self._welcome_ui.reg_submit_btn.clicked.connect(
            lambda: self._auth.register(self._welcome_ui.reg_user.text(), self._welcome_ui.reg_pass.text()))
        self._welcome_ui.reg_back_btn.clicked.connect(lambda: self._welcome_gui.setCurrentIndex(0))

        # Login screen
        # login user and go back to welcome screen when those buttons are pressed, respectively
        self._welcome_ui.log_submit_btn.clicked.connect(
            lambda: self._auth.login(self._welcome_ui.log_user.text(), self._welcome_ui.log_pass.text()))
        self._welcome_ui.log_back_btn.clicked.connect(lambda: self._welcome_gui.setCurrentIndex(0))

    # Link dcm ui elements to their respective functions
    def link_dcm_elements(self) -> None:
        # Buttons
        self._dcm_ui.quit_btn.clicked.connect(self._dcm_gui.close)  # close dcm and quit program when quit is pressed
        self._dcm_ui.about_btn.clicked.connect(self._about_gui.exec_)  # show about screen when about is pressed
        self._dcm_ui.parameters_btn.clicked.connect(self._params_gui.exec_)  # show params screen when params is pressed
        self._dcm_ui.reports_btn.clicked.connect(self._reports_gui.exec_)  # show reports screen when reports is pressed
        self._dcm_ui.new_patient_btn.clicked.connect(self._conn.register_device)  # register pacemaker on btn press
        # write serial data when btn is pressed
        self._dcm_ui.pace_btn.clicked.connect(
            lambda: self._conn.send_data_to_pacemaker(self._params.get_params(self.get_current_pace_index())))
        # update the params GUI table to only show the params for the current pacing mode
        self._dcm_ui.pacing_mode_group.buttonClicked.connect(
            lambda: self._params.update_row_visibility(self.get_current_pace_mode()))

        # Checkboxes
        # show or hide the plots, depending on whether or not the checkbox is checked, when it changes state
        self._dcm_ui.atrial_box.stateChanged.connect(lambda: self._graphs.atri_vis(self._dcm_ui.atrial_box.isChecked()))
        self._dcm_ui.vent_box.stateChanged.connect(lambda: self._graphs.vent_vis(self._dcm_ui.vent_box.isChecked()))

    # Link reports ui elements to their respective functions
    def link_reports_buttons(self) -> None:
        # Get the params based on the pacing mode, and then generate the respective report based on the pressed btn
        self._reports_ui.egram_btn.clicked.connect(self.show_egram_report)
        self._reports_ui.brady_btn.clicked.connect(
            lambda: self._reports.generate_brady(self._about_header, self.get_pace_mode_params()))

        # Get the params based on the pacing mode, and then generate the respective report based on the pressed btn
        self._egram_report_ui.export_btn.clicked.connect(lambda: self._reports.export_pdf(self._egram_report_gui))

    # Link parameters ui elements to their respective functions
    def link_params_buttons(self) -> None:
        self._params_ui.confirm_btn.clicked.connect(self._params.confirm)  # update stored params and write them to disk
        self._params_ui.reset_btn.clicked.connect(self._params.reset)  # reset stored and shown params to GUI defaults

    # Upon successful user registration or login, close the welcome screen, show the dcm and load params for user
    def show_dcm(self, username: str) -> None:
        self._welcome_gui.close()
        self._dcm_gui.show()
        self._params.update_params_on_user_auth(username)

    # Upon successful user registration or login, close the welcome screen, show the dcm and load params for user
    def show_egram_report(self) -> None:
        self._reports.generate_egram(self._about_header, self._dcm_ui.atrial_plots.grab(),
                                     self._dcm_ui.vent_plots.grab())
        self._egram_report_gui.exec_()

    # Upon successful pacemaker connection, update the status bar animation and the About window table
    def handle_pace_conn(self, conn_state: PacemakerState, msg: str) -> None:
        self._dcm_ui.statusbar.handle_conn_anim(conn_state, msg)
        self._about_header["Device serial number"] = msg if conn_state != PacemakerState.NOT_CONNECTED else "None"
        for row in range(self._about_table.rowCount()):
            self._about_table.item(row, 0).setText(self._about_header[self._about_table.verticalHeaderItem(row).text()])

    # Get only the parameters required for the current pacing mode
    def get_pace_mode_params(self) -> Dict[str, str]:
        return self._params.filter_params(self.get_current_pace_mode())

    # Get current pacing mode index in button group
    def get_current_pace_index(self) -> int:
        return self._dcm_ui.pacing_mode_group.checkedId()

    # Get current pacing mode name
    def get_current_pace_mode(self) -> str:
        return self._dcm_ui.pacing_mode_group.checkedButton().text()

    @staticmethod
    def _show_alert(success: bool, msg: str) -> None:
        """
        Displays an error message with the specified text

        :param msg: the text to show
        """
        qm = QMessageBox()
        if success:
            QMessageBox.information(qm, "Connection", msg, QMessageBox.Ok, QMessageBox.Ok)
        else:
            QMessageBox.critical(qm, "Connection", msg, QMessageBox.Ok, QMessageBox.Ok)

    # Stop threads spawned by handlers
    def stop_threads(self):
        self._conn.stop()


if __name__ == '__main__':
    # Initialize PyQt5 application
    QApplication.setAttribute(Qt.HighDpiScaleFactorRoundingPolicy.PassThrough)
    app = QApplication([])
    main_controller = MainController()
    app.setStyle('Fusion')
    app.setPalette(main_controller.palette)
    app.aboutToQuit.connect(main_controller.stop_threads)
    app.exec_()  # run event loop
