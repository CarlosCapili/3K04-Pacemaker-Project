from PyQt5.QtCore import Qt
from PyQt5.QtGui import QColor, QPalette
from PyQt5.QtWidgets import (QApplication, QDialog, QMainWindow, QStackedWidget)

from animated_status_bar import AnimatedStatusBar
from handlers.auth import AuthHandler
from handlers.connection import ConnectionHandler
from handlers.parameters import ParametersHandler
from py_ui_files import (about, dcm, parameters, reports, setclock, welcomescreen)  # auto-generated files


class MainController:
    def __init__(self):
        # Initialize separate handlers for authentication and pacemaker connection
        self.auth = AuthHandler(self.show_dcm)
        self.conn = ConnectionHandler()

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
        self.dcm_ui.statusbar = AnimatedStatusBar()
        self.dcm_gui.setStatusBar(self.dcm_ui.statusbar)
        self.dcm_ui.statusbar.showMessage("Not connected")
        self.dcm_ui.statusbar.start_no_conn()

        # Setup about screen UI from auto-generated file
        self.about_gui = QDialog()
        self.about_ui = about.Ui_aboutWindow()
        self.about_ui.setupUi(self.about_gui)

        # Setup parameter screen UI from auto-generated file
        self.params_gui = QDialog()
        self.params_ui = parameters.Ui_parametersWindow()
        self.params_ui.setupUi(self.params_gui)

        # Initialize handler for parameters
        self.params = ParametersHandler(self.params_ui.tableWidget)

        # Setup reports screen UI from auto-generated file
        self.reports_gui = QDialog()
        self.reports_ui = reports.Ui_ReportsWindow()
        self.reports_ui.setupUi(self.reports_gui)

        # Setup set-clock screen UI from auto-generated file
        self.set_clock_gui = QDialog()
        self.set_clock_ui = setclock.Ui_Dialog()
        self.set_clock_ui.setupUi(self.set_clock_gui)

        # Link buttons to actions
        self.link_welcome_buttons()
        self.link_dcm_buttons()

        # Show welcome screen GUI
        self.welcome_gui.show()

    def link_welcome_buttons(self):
        # Welcome screen
        # show register and login screens when those buttons are pressed, respectively
        self.welcome_ui.register.clicked.connect(lambda: self.welcome_gui.setCurrentIndex(1))
        self.welcome_ui.login.clicked.connect(lambda: self.welcome_gui.setCurrentIndex(2))

        # Register screen
        # register user and go back to welcome screen when those buttons are pressed, respectively
        self.welcome_ui.reg_submit.clicked.connect(
            lambda: self.auth.register(self.welcome_ui.reg_user.text(), self.welcome_ui.reg_pass.text()))
        self.welcome_ui.reg_back.clicked.connect(lambda: self.welcome_gui.setCurrentIndex(0))

        # Login screen
        # login user and go back to welcome screen when those buttons are pressed, respectively
        self.welcome_ui.log_submit.clicked.connect(
            lambda: self.auth.login(self.welcome_ui.log_user.text(), self.welcome_ui.log_pass.text()))
        self.welcome_ui.log_back.clicked.connect(lambda: self.welcome_gui.setCurrentIndex(0))

    def link_dcm_buttons(self):
        self.dcm_ui.quit_button.clicked.connect(self.dcm_gui.close)  # close dcm and quit program when quit is pressed
        self.dcm_ui.about_button.clicked.connect(self.about_gui.show)  # show about screen when about is pressed
        self.dcm_ui.parameters_button.clicked.connect(self.params_gui.show)  # show params screen when params is pressed
        self.dcm_ui.reports_button.clicked.connect(self.reports_gui.show)  # show reports screen when reports is pressed
        self.dcm_ui.set_clock_button.clicked.connect(self.set_clock_gui.show)  # show clock screen when clock is pressed

    # Upon successful registration or login, close the welcome screen and show the dcm
    def show_dcm(self):
        self.welcome_gui.close()
        self.dcm_gui.show()


if __name__ == '__main__':
    # Initialize PyQt5 application
    app = QApplication([])
    main_controller = MainController()
    # app.setStyle('Fusion')
    app.setPalette(main_controller.palette)
    app.exec_()  # run event loop
