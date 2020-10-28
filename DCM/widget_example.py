from PyQt5.QtCore import QDateTime, QTimer, Qt
from PyQt5.QtWidgets import (QApplication, QCheckBox, QComboBox, QDateTimeEdit, QDial, QDialog, QGridLayout, QGroupBox,
                             QHBoxLayout, QLabel, QLineEdit, QProgressBar, QPushButton, QRadioButton, QScrollBar,
                             QSizePolicy, QSlider, QSpinBox, QStyleFactory, QTabWidget, QTableWidget, QTextEdit,
                             QVBoxLayout, QWidget)


class WidgetGallery(QDialog):
    def __init__(self, parent=None):
        super(WidgetGallery, self).__init__(parent)

        self.originalPalette = QApplication.palette()

        style_combo_box = QComboBox()
        style_combo_box.addItems(QStyleFactory.keys())

        style_label = QLabel("&Style:")
        style_label.setBuddy(style_combo_box)

        self.useStylePaletteCheckBox = QCheckBox("&Use style's standard palette")
        self.useStylePaletteCheckBox.setChecked(True)

        disable_widgets_check_box = QCheckBox("&Disable widgets")

        self.create_top_left_group_box()
        self.create_top_right_group_box()
        self.create_bottom_left_tab_widget()
        self.create_bottom_right_group_box()
        self.create_progress_bar()

        style_combo_box.activated[str].connect(self.change_style)
        self.useStylePaletteCheckBox.toggled.connect(self.change_palette)
        disable_widgets_check_box.toggled.connect(self.topLeftGroupBox.setDisabled)
        disable_widgets_check_box.toggled.connect(self.topRightGroupBox.setDisabled)
        disable_widgets_check_box.toggled.connect(self.bottomLeftTabWidget.setDisabled)
        disable_widgets_check_box.toggled.connect(self.bottomRightGroupBox.setDisabled)

        top_layout = QHBoxLayout()
        top_layout.addWidget(style_label)
        top_layout.addWidget(style_combo_box)
        top_layout.addStretch(1)
        top_layout.addWidget(self.useStylePaletteCheckBox)
        top_layout.addWidget(disable_widgets_check_box)

        main_layout = QGridLayout()
        main_layout.addLayout(top_layout, 0, 0, 1, 2)
        main_layout.addWidget(self.topLeftGroupBox, 1, 0)
        main_layout.addWidget(self.topRightGroupBox, 1, 1)
        main_layout.addWidget(self.bottomLeftTabWidget, 2, 0)
        main_layout.addWidget(self.bottomRightGroupBox, 2, 1)
        main_layout.addWidget(self.progressBar, 3, 0, 1, 2)
        main_layout.setRowStretch(1, 1)
        main_layout.setRowStretch(2, 1)
        main_layout.setColumnStretch(0, 1)
        main_layout.setColumnStretch(1, 1)
        self.setLayout(main_layout)

        self.setWindowTitle("Styles")
        self.change_style('Fusion')

    def change_style(self, style_name):
        QApplication.setStyle(QStyleFactory.create(style_name))
        self.change_palette()

    def change_palette(self):
        if self.useStylePaletteCheckBox.isChecked():
            QApplication.setPalette(QApplication.style().standardPalette())
        else:
            QApplication.setPalette(self.originalPalette)

    def advance_progress_bar(self):
        cur_val = self.progressBar.value()
        max_val = self.progressBar.maximum()
        self.progressBar.setValue(cur_val + (max_val - cur_val) // 100 + 1)

    def create_top_left_group_box(self):
        self.topLeftGroupBox = QGroupBox("Group 1")

        radio_button1 = QRadioButton("Radio button 1")
        radio_button2 = QRadioButton("Radio button 2")
        radio_button3 = QRadioButton("Radio button 3")
        radio_button1.setChecked(True)

        check_box = QCheckBox("Tri-state check box")
        check_box.setTristate(True)
        check_box.setCheckState(Qt.PartiallyChecked)

        layout = QVBoxLayout()
        layout.addWidget(radio_button1)
        layout.addWidget(radio_button2)
        layout.addWidget(radio_button3)
        layout.addWidget(check_box)
        layout.addStretch(1)
        self.topLeftGroupBox.setLayout(layout)

    def create_top_right_group_box(self):
        self.topRightGroupBox = QGroupBox("Group 2")

        default_push_button = QPushButton("Default Push Button")
        default_push_button.setDefault(True)

        toggle_push_button = QPushButton("Toggle Push Button")
        toggle_push_button.setCheckable(True)
        toggle_push_button.setChecked(True)

        flat_push_button = QPushButton("Flat Push Button")
        flat_push_button.setFlat(True)

        layout = QVBoxLayout()
        layout.addWidget(default_push_button)
        layout.addWidget(toggle_push_button)
        layout.addWidget(flat_push_button)
        layout.addStretch(1)
        self.topRightGroupBox.setLayout(layout)

    def create_bottom_left_tab_widget(self):
        self.bottomLeftTabWidget = QTabWidget()
        self.bottomLeftTabWidget.setSizePolicy(QSizePolicy.Preferred, QSizePolicy.Ignored)

        tab1 = QWidget()
        table_widget = QTableWidget(10, 10)

        tab1hbox = QHBoxLayout()
        tab1hbox.setContentsMargins(5, 5, 5, 5)
        tab1hbox.addWidget(table_widget)
        tab1.setLayout(tab1hbox)

        tab2 = QWidget()
        text_edit = QTextEdit()

        text_edit.setPlainText("Twinkle, twinkle, little star,\n"
                               "How I wonder what you are.\n"
                               "Up above the world so high,\n"
                               "Like a diamond in the sky.\n"
                               "Twinkle, twinkle, little star,\n"
                               "How I wonder what you are!\n")

        tab2hbox = QHBoxLayout()
        tab2hbox.setContentsMargins(5, 5, 5, 5)
        tab2hbox.addWidget(text_edit)
        tab2.setLayout(tab2hbox)

        self.bottomLeftTabWidget.addTab(tab1, "&Table")
        self.bottomLeftTabWidget.addTab(tab2, "Text &Edit")

    def create_bottom_right_group_box(self):
        self.bottomRightGroupBox = QGroupBox("Group 3")
        self.bottomRightGroupBox.setCheckable(True)
        self.bottomRightGroupBox.setChecked(True)

        line_edit = QLineEdit('s3cRe7')
        line_edit.setEchoMode(QLineEdit.Password)

        spin_box = QSpinBox(self.bottomRightGroupBox)
        spin_box.setValue(50)

        date_time_edit = QDateTimeEdit(self.bottomRightGroupBox)
        date_time_edit.setDateTime(QDateTime.currentDateTime())

        slider = QSlider(Qt.Horizontal, self.bottomRightGroupBox)
        slider.setValue(40)

        scroll_bar = QScrollBar(Qt.Horizontal, self.bottomRightGroupBox)
        scroll_bar.setValue(60)

        dial = QDial(self.bottomRightGroupBox)
        dial.setValue(30)
        dial.setNotchesVisible(True)

        layout = QGridLayout()
        layout.addWidget(line_edit, 0, 0, 1, 2)
        layout.addWidget(spin_box, 1, 0, 1, 2)
        layout.addWidget(date_time_edit, 2, 0, 1, 2)
        layout.addWidget(slider, 3, 0)
        layout.addWidget(scroll_bar, 4, 0)
        layout.addWidget(dial, 3, 1, 2, 1)
        layout.setRowStretch(5, 1)
        self.bottomRightGroupBox.setLayout(layout)

    def create_progress_bar(self):
        self.progressBar = QProgressBar()
        self.progressBar.setRange(0, 10000)
        self.progressBar.setValue(0)

        timer = QTimer(self)
        timer.timeout.connect(self.advance_progress_bar)
        timer.start(50)


if __name__ == '__main__':
    import sys

    app = QApplication(sys.argv)
    gallery = WidgetGallery()
    gallery.show()
    sys.exit(app.exec_())
