from PyQt5.QtCore import Qt
from PyQt5.QtGui import QColor, QPalette
from PyQt5.QtWidgets import QApplication, QMessageBox, QPushButton, QVBoxLayout, QWidget


def on_button_clicked():
    alert = QMessageBox()
    alert.setText('You clicked the button!')
    alert.exec_()


def main():
    app = QApplication([])
    app.setStyle('Fusion')

    palette = QPalette()
    palette.setColor(QPalette.Window, QColor(53, 53, 53))
    palette.setColor(QPalette.WindowText, Qt.white)
    app.setPalette(palette)

    button = QPushButton('Click')
    window = QWidget()
    layout = QVBoxLayout()

    button.clicked.connect(on_button_clicked)
    layout.addWidget(QPushButton('Top'))
    layout.addWidget(QPushButton('Bottom'))
    layout.addWidget(button)
    window.setLayout(layout)

    window.show()
    app.exec_()


if __name__ == '__main__':
    main()
