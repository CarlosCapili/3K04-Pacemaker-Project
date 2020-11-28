# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'ui_files\egram_report.ui'
#
# Created by: PyQt5 UI code generator 5.15.1
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_Dialog(object):
    def setupUi(self, Dialog):
        Dialog.setObjectName("Dialog")
        Dialog.resize(920, 617)
        self.verticalLayout = QtWidgets.QVBoxLayout(Dialog)
        self.verticalLayout.setObjectName("verticalLayout")
        self.header_label = QtWidgets.QLabel(Dialog)
        self.header_label.setMinimumSize(QtCore.QSize(0, 70))
        self.header_label.setMaximumSize(QtCore.QSize(16777215, 70))
        self.header_label.setAlignment(QtCore.Qt.AlignCenter)
        self.header_label.setObjectName("header_label")
        self.verticalLayout.addWidget(self.header_label)
        self.gridLayout = QtWidgets.QGridLayout()
        self.gridLayout.setObjectName("gridLayout")
        self.label = QtWidgets.QLabel(Dialog)
        self.label.setMinimumSize(QtCore.QSize(0, 26))
        font = QtGui.QFont()
        font.setPointSize(14)
        self.label.setFont(font)
        self.label.setAlignment(QtCore.Qt.AlignCenter)
        self.label.setObjectName("label")
        self.gridLayout.addWidget(self.label, 2, 0, 1, 1)
        self.label_2 = QtWidgets.QLabel(Dialog)
        self.label_2.setMinimumSize(QtCore.QSize(0, 26))
        font = QtGui.QFont()
        font.setPointSize(14)
        self.label_2.setFont(font)
        self.label_2.setAlignment(QtCore.Qt.AlignCenter)
        self.label_2.setObjectName("label_2")
        self.gridLayout.addWidget(self.label_2, 4, 0, 1, 1)
        self.vent_report_plot = QtWidgets.QGraphicsView(Dialog)
        self.vent_report_plot.setObjectName("vent_report_plot")
        self.gridLayout.addWidget(self.vent_report_plot, 5, 0, 1, 1)
        self.atrial_report_plot = QtWidgets.QGraphicsView(Dialog)
        self.atrial_report_plot.setObjectName("atrial_report_plot")
        self.gridLayout.addWidget(self.atrial_report_plot, 3, 0, 1, 1)
        self.export_btn = QtWidgets.QPushButton(Dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.export_btn.setFont(font)
        self.export_btn.setObjectName("export_btn")
        self.gridLayout.addWidget(self.export_btn, 6, 0, 1, 1)
        self.verticalLayout.addLayout(self.gridLayout)

        self.retranslateUi(Dialog)
        QtCore.QMetaObject.connectSlotsByName(Dialog)

    def retranslateUi(self, Dialog):
        _translate = QtCore.QCoreApplication.translate
        Dialog.setWindowTitle(_translate("Dialog", "Dialog"))
        self.header_label.setText(_translate("Dialog", "Header info"))
        self.label.setText(_translate("Dialog", "Atrial Plot"))
        self.label_2.setText(_translate("Dialog", "Ventricular Data"))
        self.export_btn.setText(_translate("Dialog", "Export"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    Dialog = QtWidgets.QDialog()
    ui = Ui_Dialog()
    ui.setupUi(Dialog)
    Dialog.show()
    sys.exit(app.exec_())
