from PyQt5.QtCore import Qt
from PyQt5.QtGui import QColor, QPalette
from PyQt5.QtWidgets import QApplication, QDialog, QMainWindow, QWidget

from handlers.auth import AuthHandler
from py_ui_files import dcm, login, register, welcomescreen


def show_dcm(dcm):  # Replace this with lambda: dcm_gui.show()
    dcm.show()


def main():
    auth = AuthHandler()

    app = QApplication([])
    app.setStyle('Fusion')

    palette = QPalette()
    palette.setColor(QPalette.Window, QColor(53, 53, 53))
    palette.setColor(QPalette.WindowText, Qt.white)
    app.setPalette(palette)

    welcome_gui = QWidget()
    welcome_ui = welcomescreen.Ui_WelcomeScreen()
    welcome_ui.setupUi(welcome_gui)

    register_gui = QDialog()
    register_ui = register.Ui_RegisterScreen()
    register_ui.setupUi(register_gui)

    login_gui = QDialog()
    login_ui = login.Ui_LoginScreen()
    login_ui.setupUi(login_gui)

    dcm_gui = QMainWindow()
    dcm_ui = dcm.Ui_MainWindow()
    dcm_ui.setupUi(dcm_gui)

    welcome_ui.registerButton.clicked.connect(lambda: register_gui.show())
    welcome_ui.loginButton.clicked.connect(lambda: login_gui.show())

    register_ui.pushButton.clicked.connect(
        lambda: auth.register(register_ui.userTextEdit.toPlainText(), register_ui.passTextEdit.toPlainText()))

    login_ui.pushButton.clicked.connect(
        lambda: auth.login(login_ui.userTextEdit.toPlainText(), login_ui.passTextEdit.toPlainText()))

    welcome_gui.show()
    app.exec_()


if __name__ == '__main__':
    main()
