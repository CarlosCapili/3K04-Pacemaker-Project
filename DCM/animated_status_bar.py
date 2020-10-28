from PyQt5.QtCore import QPropertyAnimation, QSequentialAnimationGroup, pyqtProperty
from PyQt5.QtGui import QColor, QPalette
from PyQt5.QtWidgets import (QApplication, QStatusBar)


class AnimatedStatusBar(QStatusBar):
    def __init__(self, parent=None):
        QStatusBar.__init__(self, parent)

        red = QColor(255, 0, 0)
        transparent = QColor(255, 0, 0, alpha=0)

        self.color_anim_1 = QPropertyAnimation(self, b"zcolor")
        self.color_anim_1.setStartValue(red)
        self.color_anim_1.setEndValue(transparent)
        self.color_anim_1.setDuration(2000)

        self.color_anim_2 = QPropertyAnimation(self, b"zcolor")
        self.color_anim_2.setStartValue(transparent)
        self.color_anim_2.setEndValue(red)
        self.color_anim_2.setDuration(2000)

        self.color_anim_3 = QPropertyAnimation(self, b"zcolor")
        self.color_anim_3.setStartValue(red)
        self.color_anim_3.setEndValue(red)
        self.color_anim_3.setDuration(1000)

        self.color_anim_ok = QSequentialAnimationGroup()
        self.color_anim_ok.addAnimation(self.color_anim_1)
        self.color_anim_ok.addAnimation(self.color_anim_2)
        self.color_anim_ok.addAnimation(self.color_anim_3)
        self.color_anim_ok.setLoopCount(-1)

    def start_no_conn(self):
        self.color_anim_ok.start()

    def get_back_color(self):
        return self.palette().color(QPalette.Window)

    def set_back_color(self, color: QColor):
        # get = self.get_back_color()
        # print("set ", color.red(), color.green(), color.blue(), color.alpha(), " get ", get.red(), get.green(),
        #       get.blue(), get.alpha())
        self.pal.setColor(QPalette.Window, color)
        self.pal.setColor(QPalette.Base, color)
        self.pal.setColor(QPalette.WindowText, color)
        self.pal.setColor(QPalette.AlternateBase, color)
        self.pal.setColor(QPalette.PlaceholderText, color)
        self.pal.setColor(QPalette.Text, color)
        self.pal.setColor(QPalette.BrightText, color)
        self.setPalette(self.pal)

    pal = QPalette()
    zcolor = pyqtProperty(QColor, get_back_color, set_back_color)


if __name__ == "__main__":
    import sys

    app = QApplication(sys.argv)
    status_bar = AnimatedStatusBar()
    status_bar.show()
    status_bar.start_no_conn()

    app.exec_()
