"""
https://stackoverflow.com/questions/16660292/qt-using-custom-qitemdelegate-for-qtableview
https://stackoverflow.com/questions/17615997/pyqt-how-to-set-qcombobox-in-a-table-view-using-qitemdelegate
https://doc.qt.io/qtforpython/overviews/qtwidgets-itemviews-spinboxdelegate-example.html
"""
from typing import List

from PyQt5.QtCore import QAbstractItemModel, QModelIndex, Qt
from PyQt5.QtGui import QPalette
from PyQt5.QtWidgets import QComboBox, QDoubleSpinBox, QSpinBox, QStyleOptionViewItem, QStyledItemDelegate, QWidget


class SpinBoxDelegate(QStyledItemDelegate):
    def __init__(self, nominal: int, min_val: int, max_val: int, step: int, unit: str, parent=None):
        QStyledItemDelegate.__init__(self, parent)
        self.nominal = nominal
        self.min = min_val
        self.max = max_val
        self.step = step
        self.unit = " " + unit

    def createEditor(self, parent: QWidget, option: 'QStyleOptionViewItem', index: QModelIndex) -> QWidget:
        if index.column() == 0:
            q = QSpinBox(parent)
            q.setFrame(False)
            q.lineEdit().setReadOnly(True)
            q.setValue(self.nominal)
            q.setRange(self.min, self.max)
            q.setSingleStep(self.step)
            q.setSuffix(self.unit)
            return q
        else:
            return super(SpinBoxDelegate, self).createEditor(parent, option, index)

    def setEditorData(self, editor: QWidget, index: QModelIndex) -> None:
        if index.column() == 0:
            value = int(index.model().data(index, Qt.EditRole))
            editor.setValue(value)
        else:
            return super(SpinBoxDelegate, self).setEditorData(editor, index)

    def setModelData(self, editor: QWidget, model: QAbstractItemModel, index: QModelIndex) -> None:
        if index.column() == 0:
            editor.interpretText()
            model.setData(index, editor.value(), Qt.EditRole)
        else:
            return super(SpinBoxDelegate, self).setModelData(editor, model, index)

    def updateEditorGeometry(self, editor: QWidget, option: 'QStyleOptionViewItem', index: QModelIndex) -> None:
        if index.column() == 0:
            editor.setGeometry(option.rect)
        else:
            return super(SpinBoxDelegate, self).updateEditorGeometry(editor, option, index)


class DoubleSpinBoxDelegate(QStyledItemDelegate):
    def __init__(self, nominal: float, min_val: float, max_val: float, step: float, unit: str, parent=None):
        QStyledItemDelegate.__init__(self, parent)
        self.nominal = nominal
        self.min = min_val
        self.max = max_val
        self.step = step
        self.unit = " " + unit

    def createEditor(self, parent: QWidget, option: 'QStyleOptionViewItem', index: QModelIndex) -> QWidget:
        if index.column() == 0:
            q = QDoubleSpinBox(parent)
            q.setFrame(False)
            q.setDecimals(1)
            q.setValue(self.nominal)
            q.setRange(self.min, self.max)
            q.setSingleStep(self.step)
            q.setSuffix(self.unit)
            return q
        else:
            return super(DoubleSpinBoxDelegate, self).createEditor(parent, option, index)

    def setEditorData(self, editor: QWidget, index: QModelIndex) -> None:
        if index.column() == 0:
            value = float(index.model().data(index, Qt.EditRole))
            editor.setValue(value)
        else:
            return super(DoubleSpinBoxDelegate, self).setEditorData(editor, index)

    def setModelData(self, editor: QWidget, model: QAbstractItemModel, index: QModelIndex) -> None:
        if index.column() == 0:
            editor.interpretText()
            model.setData(index, editor.value(), Qt.EditRole)
        else:
            return super(DoubleSpinBoxDelegate, self).setModelData(editor, model, index)

    def updateEditorGeometry(self, editor: QWidget, option: 'QStyleOptionViewItem', index: QModelIndex) -> None:
        if index.column() == 0:
            editor.setGeometry(option.rect)
        else:
            return super(DoubleSpinBoxDelegate, self).updateEditorGeometry(editor, option, index)


class ComboBoxDelegate(QStyledItemDelegate):
    def __init__(self, nominal_index: int, values: List[str], parent=None):
        QStyledItemDelegate.__init__(self, parent)
        self.nominal_index = nominal_index
        self.values = values
        self.palette = QPalette()
        self.palette.setColor(QPalette.Text, Qt.white)

    def createEditor(self, parent: QWidget, option: 'QStyleOptionViewItem', index: QModelIndex) -> QWidget:
        if index.column() == 0:
            q = QComboBox(parent)
            q.setPalette(self.palette)
            q.setFrame(False)
            q.setEditable(False)
            q.setMaxCount(len(self.values))
            q.addItems(self.values)
            q.setCurrentIndex(self.nominal_index)
            return q
        else:
            return super(ComboBoxDelegate, self).createEditor(parent, option, index)

    def setEditorData(self, editor: QWidget, index: QModelIndex) -> None:
        if index.column() == 0:
            editor.setCurrentIndex(int(index.model().data(index)))
        else:
            return super(ComboBoxDelegate, self).setEditorData(editor, index)

    def setModelData(self, editor: QWidget, model: QAbstractItemModel, index: QModelIndex) -> None:
        if index.column() == 0:
            model.setData(index, editor.currentIndex())
        else:
            return super(ComboBoxDelegate, self).setModelData(editor, model, index)

    def updateEditorGeometry(self, editor: QWidget, option: 'QStyleOptionViewItem', index: QModelIndex) -> None:
        if index.column() == 0:
            editor.setGeometry(option.rect)
        else:
            return super(ComboBoxDelegate, self).updateEditorGeometry(editor, option, index)
