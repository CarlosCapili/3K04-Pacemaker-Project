from typing import Dict

from PyQt5.QtCore import Qt
from PyQt5.QtGui import QColor, QPalette
from PyQt5.QtWidgets import (QApplication, QDialog, QMainWindow, QMessageBox, QStackedWidget, QTableWidget)

from handlers.auth import AuthHandler
from handlers.connection import ConnectionHandler, PacemakerState
from handlers.graphs import GraphsHandler
from handlers.parameters import ParametersHandler
from handlers.reports import ReportsHandler
from py_ui_files import (about, dcm, parameters, reports, setclock, welcomescreen)  # auto-generated files
from py_ui_files.about import Ui_aboutWindow
from py_ui_files.dcm import Ui_MainWindow
from py_ui_files.parameters import Ui_parametersWindow
from py_ui_files.reports import Ui_ReportsWindow
from py_ui_files.setclock import Ui_Dialog
from py_ui_files.welcomescreen import Ui_Welcome


# This class handles all the linking between the frontend (GUI/UI) and the backend (handlers)
class MainController:
    palette: QPalette
    welcome_gui: QStackedWidget
    welcome_ui: Ui_Welcome
    dcm_gui: QMainWindow
    dcm_ui: Ui_MainWindow
    about_gui: QDialog
    about_ui: Ui_aboutWindow
    about_table: QTableWidget
    about_header: Dict[str, str]
    params_gui: QDialog
    params_ui: Ui_parametersWindow
    reports_gui: QDialog
    reports_ui: Ui_ReportsWindow
    set_clock_gui: QDialog
    set_clock_ui: Ui_Dialog
    auth: AuthHandler
    conn: ConnectionHandler
    params: ParametersHandler
    reports: ReportsHandler
    graphs: GraphsHandler

    def __init__(self):
        # Set theme to dark mode
        self.palette = QPalette()
        self.palette.setColor(QPalette.Window, QColor(53, 53, 53))
        self.palette.setColor(QPalette.WindowText, Qt.white)

        # Setup welcome screen UI from auto-generated file
        self.welcome_gui = QStackedWidget()
        self.welcome_ui = welcomescreen.Ui_Welcome()
        self.welcome_ui.setupUi(self.welcome_gui)

        # Setup dcm screen UI from auto-generated file
        self.dcm_gui = QMainWindow()
        self.dcm_ui = dcm.Ui_MainWindow()
        self.dcm_ui.setupUi(self.dcm_gui)
        self.dcm_ui.atrial_plots.setRange(xRange=[0, 50], yRange=[0, 5])
        self.dcm_ui.ventricular_plots.setRange(xRange=[0, 50], yRange=[0, 5])
        for i, button in enumerate(self.dcm_ui.pacing_mode_group.buttons()):
            self.dcm_ui.pacing_mode_group.setId(button, i)

        # Setup about screen UI from auto-generated file
        self.about_gui = QDialog()
        self.about_ui = about.Ui_aboutWindow()
        self.about_ui.setupUi(self.about_gui)
        self.about_table = self.about_ui.tableWidget
        self.about_header = {self.about_table.verticalHeaderItem(row).text(): self.about_table.item(row, 0).text() for
                             row in range(self.about_table.rowCount())}

        # Setup parameter screen UI from auto-generated file
        self.params_gui = QDialog()
        self.params_ui = parameters.Ui_parametersWindow()
        self.params_ui.setupUi(self.params_gui)

        # Setup reports screen UI from auto-generated file
        self.reports_gui = QDialog()
        self.reports_ui = reports.Ui_ReportsWindow()
        self.reports_ui.setupUi(self.reports_gui)

        # Setup set-clock screen UI from auto-generated file
        self.set_clock_gui = QDialog()
        self.set_clock_ui = setclock.Ui_Dialog()
        self.set_clock_ui.setupUi(self.set_clock_gui)

        # Initialize separate handlers for authentication, pacemaker connection, parameters, reports and graphs
        self.auth = AuthHandler(self.show_dcm)
        self.conn = ConnectionHandler()
        self.params = ParametersHandler(self.params_ui.tableWidget)
        self.reports = ReportsHandler()
        self.graphs = GraphsHandler(self.dcm_ui.atrial_plots, self.dcm_ui.ventricular_plots)

        # Link elements to actions
        self.link_welcome_buttons()
        self.link_dcm_elements()
        self.link_reports_buttons()
        self.link_params_buttons()

        # Start connection thread
        self.conn.connect_status_change.connect(self.handle_pace_conn)
        self.conn.serial.ecg_data_update.connect(self.graphs.update_data)
        self.conn.serial.diff_params_received.connect(self._show_alert)
        self.conn.start()

        # Update params GUI table to show default pacing mode params
        self.params.update_row_visibility(self.dcm_ui.pacing_mode_group.checkedButton().text())

        # Show welcome screen GUI
        self.welcome_gui.show()

    # Link welcome screen ui elements to their respective functions
    def link_welcome_buttons(self) -> None:
        # Welcome screen
        # show register and login screens when those buttons are pressed, respectively
        self.welcome_ui.reg_btn.clicked.connect(lambda: self.welcome_gui.setCurrentIndex(1))
        self.welcome_ui.log_btn.clicked.connect(lambda: self.welcome_gui.setCurrentIndex(2))

        # Register screen
        # register user and go back to welcome screen when those buttons are pressed, respectively
        self.welcome_ui.reg_submit_btn.clicked.connect(
            lambda: self.auth.register(self.welcome_ui.reg_user.text(), self.welcome_ui.reg_pass.text()))
        self.welcome_ui.reg_back_btn.clicked.connect(lambda: self.welcome_gui.setCurrentIndex(0))

        # Login screen
        # login user and go back to welcome screen when those buttons are pressed, respectively
        self.welcome_ui.log_submit_btn.clicked.connect(
            lambda: self.auth.login(self.welcome_ui.log_user.text(), self.welcome_ui.log_pass.text()))
        self.welcome_ui.log_back_btn.clicked.connect(lambda: self.welcome_gui.setCurrentIndex(0))

    # Link dcm ui elements to their respective functions
    def link_dcm_elements(self) -> None:
        # Buttons
        self.dcm_ui.quit_btn.clicked.connect(self.dcm_gui.close)  # close dcm and quit program when quit is pressed
        self.dcm_ui.about_btn.clicked.connect(self.about_gui.exec_)  # show about screen when about is pressed
        self.dcm_ui.parameters_btn.clicked.connect(self.params_gui.exec_)  # show params screen when params is pressed
        self.dcm_ui.reports_btn.clicked.connect(self.reports_gui.exec_)  # show reports screen when reports is pressed
        self.dcm_ui.set_clock_btn.clicked.connect(self.set_clock_gui.exec_)  # show clock screen when clock is pressed
        self.dcm_ui.new_patient_btn.clicked.connect(self.conn.register_device)  # register pacemaker when btn is pressed
        # write serial data when btn is pressed
        self.dcm_ui.pace_btn.clicked.connect(
            lambda: self.conn.send_data_to_pacemaker(self.params.get_params(self.get_current_pace_index())))
        # update the params GUI table to only show the params for the current pacing mode
        self.dcm_ui.pacing_mode_group.buttonClicked.connect(
            lambda: self.params.update_row_visibility(self.get_current_pace_mode()))

        # Checkboxes
        # show or hide the plots, depending on whether or not the checkbox is checked, when it changes state
        self.dcm_ui.pace_box.stateChanged.connect(lambda: self.graphs.pace_vis(self.dcm_ui.pace_box.isChecked()))
        self.dcm_ui.sense_box.stateChanged.connect(lambda: self.graphs.sense_vis(self.dcm_ui.sense_box.isChecked()))
        self.dcm_ui.atrial_box.stateChanged.connect(lambda: self.graphs.atri_vis(self.dcm_ui.atrial_box.isChecked()))
        self.dcm_ui.vent_box.stateChanged.connect(lambda: self.graphs.vent_vis(self.dcm_ui.vent_box.isChecked()))

    # Link reports ui elements to their respective functions
    def link_reports_buttons(self) -> None:
        # Get the params based on the pacing mode, and then generate the respective report based on the pressed btn
        self.reports_ui.egram_btn.clicked.connect(lambda: self.reports.generate_egram(self.get_pace_mode_params()))
        self.reports_ui.brady_btn.clicked.connect(
            lambda: self.reports.generate_brady(self.about_header, self.get_pace_mode_params()))

    # Link parameters ui elements to their respective functions
    def link_params_buttons(self) -> None:
        self.params_ui.confirm_btn.clicked.connect(self.params.confirm)  # update stored params and write them to a file
        self.params_ui.reset_btn.clicked.connect(self.params.reset)  # reset stored and shown params to GUI defaults

    # Upon successful user registration or login, close the welcome screen, show the dcm and load params for user
    def show_dcm(self, username: str) -> None:
        self.welcome_gui.close()
        self.dcm_gui.show()
        self.params.update_params_on_user_auth(username)

    # Upon successful pacemaker connection, update the status bar animation and the About window table
    def handle_pace_conn(self, conn_state: PacemakerState, msg: str) -> None:
        self.dcm_ui.statusbar.handle_conn_anim(conn_state, msg)
        self.about_header["Serial number"] = msg if conn_state != PacemakerState.NOT_CONNECTED else "None"
        for row in range(self.about_table.rowCount()):
            self.about_table.item(row, 0).setText(self.about_header[self.about_table.verticalHeaderItem(row).text()])

    # Get only the parameters required for the current pacing mode
    def get_pace_mode_params(self) -> Dict[str, str]:
        return self.params.filter_params(self.get_current_pace_mode())

    # Get current pacing mode index in button group
    def get_current_pace_index(self) -> int:
        return self.dcm_ui.pacing_mode_group.checkedId()

    # Get current pacing mode name
    def get_current_pace_mode(self) -> str:
        return self.dcm_ui.pacing_mode_group.checkedButton().text()

    @staticmethod
    def _show_alert(msg: str) -> None:
        """
        Displays an error message with the specified text

        :param msg: the text to show
        """
        qm = QMessageBox()
        QMessageBox.critical(qm, "Connection", msg, QMessageBox.Ok, QMessageBox.Ok)

    # Stop threads spawned by handlers
    def stop_threads(self):
        self.conn.stop()


if __name__ == '__main__':
    # Initialize PyQt5 application
    QApplication.setAttribute(Qt.HighDpiScaleFactorRoundingPolicy.PassThrough)
    app = QApplication([])
    main_controller = MainController()
    app.setStyle('Fusion')
    app.setPalette(main_controller.palette)
    app.aboutToQuit.connect(main_controller.stop_threads)
    app.exec_()  # run event loop
