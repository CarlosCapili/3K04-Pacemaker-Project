from PyQt5.QtCore import Qt
from PyQt5.QtGui import QColor, QPalette
from PyQt5.QtWidgets import (QApplication, QDialog, QMainWindow, QStackedWidget)

from handlers.auth import AuthHandler
from handlers.connection import ConnectionHandler
from handlers.stylesheet import StyleHandler
from py_ui_files import (about, dcm, welcomescreen)  # auto-generated files


class MainController:
    def __init__(self):
        # Initialize separate handlers for authentication, styles, and pacemaker connection
        self.auth = AuthHandler(self.show_dcm)
        self.style = StyleHandler()
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
        self.dcm_ui.statusbar.setStyleSheet(self.style.no_conn_status_bar())
        self.dcm_ui.statusbar.showMessage("Not connected")

        # Setup about screen UI from auto-generated file
        self.about_gui = QDialog()
        self.about_ui = about.Ui_aboutWindow()
        self.about_ui.setupUi(self.about_gui)

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
        self.dcm_ui.quitButton.clicked.connect(self.dcm_gui.close)  # close dcm and quit program when quit is pressed
        self.dcm_ui.aboutButton.clicked.connect(self.about_gui.show)  # show about screen when about is pressed

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
