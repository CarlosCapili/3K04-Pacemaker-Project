from PyQt5.QtCore import Qt
from PyQt5.QtGui import QColor, QPalette
from PyQt5.QtWidgets import (QApplication, QDialog, QMainWindow, QStackedWidget)

from handlers.auth import AuthHandler
from handlers.connection import ConnectionHandler
from handlers.graphs import GraphsHandler
from handlers.parameters import ParametersHandler
from handlers.reports import ReportsHandler
from py_ui_files import (about, dcm, parameters, reports, setclock, welcomescreen)  # auto-generated files


class MainController:
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

        # Setup about screen UI from auto-generated file
        self.about_gui = QDialog()
        self.about_ui = about.Ui_aboutWindow()
        self.about_ui.setupUi(self.about_gui)

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

        # Initialize separate handlers for authentication, pacemaker connection, parameters and reports
        self.auth = AuthHandler(self.show_dcm)
        self.conn = ConnectionHandler()
        self.params = ParametersHandler(self.params_ui.tableWidget)
        self.reports = ReportsHandler(self.about_ui.tableWidget)
        self.graphs = GraphsHandler(self.dcm_ui.atrialPlots, self.dcm_ui.ventricularPlots)

        # Link buttons to actions
        self.link_welcome_buttons()
        self.link_dcm_buttons()
        self.link_reports_buttons()
        self.link_params_buttons()

        # Start connection thread
        self.conn.start()

        # Show welcome screen GUI
        self.welcome_gui.show()

    def link_welcome_buttons(self):
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

    def link_dcm_buttons(self):
        self.dcm_ui.quit_btn.clicked.connect(self.dcm_gui.close)  # close dcm and quit program when quit is pressed
        self.dcm_ui.about_btn.clicked.connect(self.about_gui.exec_)  # show about screen when about is pressed
        self.dcm_ui.parameters_btn.clicked.connect(self.params_gui.exec_)  # show params screen when params is pressed
        self.dcm_ui.reports_btn.clicked.connect(self.reports_gui.exec_)  # show reports screen when reports is pressed
        self.dcm_ui.set_clock_btn.clicked.connect(self.set_clock_gui.exec_)  # show clock screen when clock is pressed

    def link_reports_buttons(self):
        self.reports_ui.egram_btn.clicked.connect(lambda: self.reports.generate_egram(self.get_pace_mode_params()))
        self.reports_ui.brady_btn.clicked.connect(lambda: self.reports.generate_brady(self.get_pace_mode_params()))
        self.reports_ui.temp_btn.clicked.connect(lambda: self.reports.generate_temp(self.get_pace_mode_params()))

    def link_params_buttons(self):
        self.params_ui.confirm_btn.clicked.connect(self.params.confirm)  # update stored params and write them to a file
        self.params_ui.reset_btn.clicked.connect(self.params.reset)  # reset stored and shown params to GUI defaults

    # Upon successful registration or login, close the welcome screen and show the dcm
    def show_dcm(self):
        self.welcome_gui.close()
        self.dcm_ui.statusbar.start_no_conn_anim()
        self.dcm_gui.show()
        self.graphs.plot()

    # Get only the parameters required for the current pacing mode
    def get_pace_mode_params(self):
        return self.params.filter_params(self.dcm_ui.pacing_mode_group.checkedButton().text())


if __name__ == '__main__':
    # Initialize PyQt5 application
    app = QApplication([])
    main_controller = MainController()
    app.setStyle('Fusion')
    app.setPalette(main_controller.palette)
    app.aboutToQuit.connect(main_controller.conn.stop)
    app.exec_()  # run event loop
