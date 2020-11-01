from PyQt5.QtCore import QPropertyAnimation, QSequentialAnimationGroup, pyqtProperty
from PyQt5.QtGui import QColor, QPalette
from PyQt5.QtWidgets import (QApplication, QStatusBar)

from handlers.connection import PacemakerState


# This class extends the status bar widget to allow for animations
class AnimatedStatusBar(QStatusBar):
    no_conn_anim: QSequentialAnimationGroup
    conn_anim: QSequentialAnimationGroup

    def __init__(self, parent=None):
        QStatusBar.__init__(self, parent)
        self.setAutoFillBackground(True)  # set the widget background to be filled automatically

        # Define colours to use in animations
        red = QColor(255, 0, 0)
        red_transparent = QColor(255, 0, 0, alpha=0)
        green = QColor(0, 255, 0)
        green_transparent = QColor(0, 255, 0, alpha=0)

        # Setup fade out animation for red
        fade_out = QPropertyAnimation(self, b"back_color")
        fade_out.setStartValue(red)
        fade_out.setEndValue(red_transparent)
        fade_out.setDuration(2000)

        # Setup fade in animation for red
        fade_in = QPropertyAnimation(self, b"back_color")
        fade_in.setStartValue(red_transparent)
        fade_in.setEndValue(red)
        fade_in.setDuration(2000)

        # Setup stay animation for red
        stay_red = QPropertyAnimation(self, b"back_color")
        stay_red.setStartValue(red)
        stay_red.setEndValue(red)
        stay_red.setDuration(1000)

        # Setup animation group for no connection
        self.no_conn_anim = QSequentialAnimationGroup()
        self.no_conn_anim.addAnimation(fade_out)
        self.no_conn_anim.addAnimation(fade_in)
        self.no_conn_anim.addAnimation(stay_red)
        self.no_conn_anim.setLoopCount(-1)  # loop infinitely

        # Setup fade out animation for green
        fade_out = QPropertyAnimation(self, b"back_color")
        fade_out.setStartValue(green)
        fade_out.setEndValue(green_transparent)
        fade_out.setDuration(2000)

        # Setup fade in animation for green
        fade_in = QPropertyAnimation(self, b"back_color")
        fade_in.setStartValue(green_transparent)
        fade_in.setEndValue(green)
        fade_in.setDuration(2000)

        # Setup stay animation for green
        stay_green = QPropertyAnimation(self, b"back_color")
        stay_green.setStartValue(green)
        stay_green.setEndValue(green)
        stay_green.setDuration(1000)

        # Setup animation group for a connection
        self.conn_anim = QSequentialAnimationGroup()
        self.conn_anim.addAnimation(fade_out)
        self.conn_anim.addAnimation(fade_in)
        self.conn_anim.addAnimation(stay_green)
        self.conn_anim.setLoopCount(-1)

    # Depending on the pacemaker connection state, display the corresponding animation/colour and the passed in
    # message on the status bar
    def handle_conn_anim(self, conn_state: PacemakerState, msg: str) -> None:
        if conn_state == PacemakerState.NOT_CONNECTED:
            self.no_conn_anim.start()
            self.conn_anim.stop()
            self.showMessage(f"Not connected to pacemaker {msg}")
        elif conn_state == PacemakerState.CONNECTED:
            self.no_conn_anim.stop()
            self.conn_anim.start()
            self.showMessage(f"Connected to pacemaker {msg}")
        elif conn_state == PacemakerState.REGISTERED:
            self.no_conn_anim.stop()
            self.conn_anim.stop()
            self.pal.setColor(self.backgroundRole(), QColor("green"))
            self.setPalette(self.pal)
            self.showMessage(f"Registered pacemaker {msg}")

    # Return the current background color of the status bar
    def get_back_color(self) -> QColor:
        return self.palette().color(self.backgroundRole())

    # Set the background color of the status bar
    def set_back_color(self, color: QColor) -> None:
        self.pal.setColor(self.backgroundRole(), color)
        self.setPalette(self.pal)

    # Define properties of the status bar, used in animations
    pal: QPalette = QPalette()
    back_color: pyqtProperty = pyqtProperty(QColor, get_back_color, set_back_color)


if __name__ == "__main__":
    import sys

    app = QApplication(sys.argv)
    status_bar = AnimatedStatusBar()
    status_bar.show()
    status_bar.start_no_conn_anim()

    app.exec_()
