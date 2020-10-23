from PyQt5.QtCore import Qt
from PyQt5.QtGui import QColor, QPalette
from PyQt5.QtWidgets import (QApplication, QMainWindow, QStackedWidget)

from handlers.auth import AuthHandler
from py_ui_files import (dcm, stackedwelcomescreen)


class MainController:
    def __init__(self):
        self.auth = AuthHandler(self.show_dcm)

        self.palette = QPalette()
        self.palette.setColor(QPalette.Window, QColor(53, 53, 53))
        self.palette.setColor(QPalette.WindowText, Qt.white)

        self.welcome_gui = QStackedWidget()
        self.welcome_ui = stackedwelcomescreen.Ui_Welcome()
        self.welcome_ui.setupUi(self.welcome_gui)

        self.dcm_gui = QMainWindow()
        self.dcm_ui = dcm.Ui_MainWindow()
        self.dcm_ui.setupUi(self.dcm_gui)

        self.welcome_ui.registerButton.clicked.connect(lambda: self.welcome_gui.setCurrentIndex(1))
        self.welcome_ui.loginButton.clicked.connect(lambda: self.welcome_gui.setCurrentIndex(2))

        self.welcome_ui.pushButton.clicked.connect(
            lambda: self.auth.register(self.welcome_ui.userTextEdit.toPlainText(),
                                       self.welcome_ui.passTextEdit.toPlainText()))
        self.welcome_ui.returnButton.clicked.connect(lambda: self.welcome_gui.setCurrentIndex(0))

        self.welcome_ui.pushButton_2.clicked.connect(
            lambda: self.auth.login(self.welcome_ui.userTextEdit_2.toPlainText(),
                                    self.welcome_ui.passTextEdit_2.toPlainText()))
        self.welcome_ui.returnButton_2.clicked.connect(lambda: self.welcome_gui.setCurrentIndex(0))

        self.welcome_gui.show()

    def show_dcm(self):
        self.welcome_gui.close()
        self.dcm_gui.show()


if __name__ == '__main__':
    app = QApplication([])
    main_controller = MainController()
    app.setStyle('Fusion')
    app.setPalette(main_controller.palette)
    app.exec_()
