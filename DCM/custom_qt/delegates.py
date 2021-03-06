from typing import List

from PyQt5.QtCore import QAbstractItemModel, QModelIndex, Qt
from PyQt5.QtGui import QPalette
from PyQt5.QtWidgets import QComboBox, QDoubleSpinBox, QSpinBox, QStyleOptionViewItem, QStyledItemDelegate, QWidget

"""
https://stackoverflow.com/questions/16660292/qt-using-custom-qitemdelegate-for-qtableview
https://stackoverflow.com/questions/17615997/pyqt-how-to-set-qcombobox-in-a-table-view-using-qitemdelegate
https://doc.qt.io/qtforpython/overviews/qtwidgets-itemviews-spinboxdelegate-example.html
"""


# This class handles the UI/GUI for integer params only in column 0 in the table. All the methods override the ones
# in the superclass.
class SpinBoxDelegate(QStyledItemDelegate):
    min: int
    max: int
    step: int
    unit: str

    def __init__(self, min_val: int, max_val: int, step: int, unit: str, parent=None):
        QStyledItemDelegate.__init__(self, parent)
        self.min = min_val
        self.max = max_val
        self.step = step
        self.unit = " " + unit

    # Returns an editor widget, in this case a spin box that restricts values from the model to integers
    def createEditor(self, parent: QWidget, option: 'QStyleOptionViewItem', index: QModelIndex) -> QWidget:
        if index.column() == 0:
            q = QSpinBox(parent)
            q.setFrame(False)
            q.lineEdit().setReadOnly(True)
            q.setRange(self.min, self.max)
            q.setSingleStep(self.step)
            q.setSuffix(self.unit)
            return q
        else:
            return super(SpinBoxDelegate, self).createEditor(parent, option, index)

    # Reads data from the model, converts it to an integer value, and writes it to the editor widget
    def setEditorData(self, editor: QWidget, index: QModelIndex) -> None:
        if index.column() == 0:
            editor.setValue(int(index.model().data(index, Qt.EditRole)))
        else:
            return super(SpinBoxDelegate, self).setEditorData(editor, index)

    # Reads the contents of the spin box, and writes it to the model
    def setModelData(self, editor: QWidget, model: QAbstractItemModel, index: QModelIndex) -> None:
        if index.column() == 0:
            editor.interpretText()
            model.setData(index, editor.value(), Qt.EditRole)
        else:
            return super(SpinBoxDelegate, self).setModelData(editor, model, index)

    # Updates the editor widget’s geometry using the information supplied in the style option
    def updateEditorGeometry(self, editor: QWidget, option: 'QStyleOptionViewItem', index: QModelIndex) -> None:
        if index.column() == 0:
            editor.setGeometry(option.rect)
        else:
            return super(SpinBoxDelegate, self).updateEditorGeometry(editor, option, index)


# This class handles the UI/GUI for float params only in column 0 in the table. All the methods override the ones
# in the superclass.
class DoubleSpinBoxDelegate(QStyledItemDelegate):
    min: float
    max: float
    step: float
    unit: str

    def __init__(self, min_val: float, max_val: float, step: float, unit: str, parent=None):
        QStyledItemDelegate.__init__(self, parent)
        self.min = min_val
        self.max = max_val
        self.step = step
        self.unit = " " + unit

    # Returns an editor widget, in this case a double spin box that restricts values from the model to floats
    def createEditor(self, parent: QWidget, option: 'QStyleOptionViewItem', index: QModelIndex) -> QWidget:
        if index.column() == 0:
            q = QDoubleSpinBox(parent)
            q.setFrame(False)
            q.setDecimals(1)
            q.setRange(self.min, self.max)
            q.setSingleStep(self.step)
            q.setSuffix(self.unit)
            return q
        else:
            return super(DoubleSpinBoxDelegate, self).createEditor(parent, option, index)

    # Reads data from the model, converts it to a float value, and writes it to the editor widget
    def setEditorData(self, editor: QWidget, index: QModelIndex) -> None:
        if index.column() == 0:
            editor.setValue(float(index.model().data(index, Qt.EditRole)))
        else:
            return super(DoubleSpinBoxDelegate, self).setEditorData(editor, index)

    # Reads the contents of the double spin box, and writes it to the model
    def setModelData(self, editor: QWidget, model: QAbstractItemModel, index: QModelIndex) -> None:
        if index.column() == 0:
            editor.interpretText()
            model.setData(index, editor.value(), Qt.EditRole)
        else:
            return super(DoubleSpinBoxDelegate, self).setModelData(editor, model, index)

    # Updates the editor widget’s geometry using the information supplied in the style option
    def updateEditorGeometry(self, editor: QWidget, option: 'QStyleOptionViewItem', index: QModelIndex) -> None:
        if index.column() == 0:
            editor.setGeometry(option.rect)
        else:
            return super(DoubleSpinBoxDelegate, self).updateEditorGeometry(editor, option, index)


# This class handles the UI/GUI for string/list params only in column 0 in the table. All the methods override the ones
# in the superclass.
class ComboBoxDelegate(QStyledItemDelegate):
    values: List[str]
    palette: QPalette

    def __init__(self, values: List[str], parent=None):
        QStyledItemDelegate.__init__(self, parent)
        self.values = values
        self.palette = QPalette()
        self.palette.setColor(QPalette.Text, Qt.white)

    # Returns an editor widget, in this case a combo box that restricts values from the model one from the list
    def createEditor(self, parent: QWidget, option: 'QStyleOptionViewItem', index: QModelIndex) -> QWidget:
        if index.column() == 0:
            q = QComboBox(parent)
            q.setPalette(self.palette)
            q.setFrame(False)
            q.setMaxCount(len(self.values))
            q.addItems(self.values)
            q.setEditable(False)
            return q
        else:
            return super(ComboBoxDelegate, self).createEditor(parent, option, index)

    # Reads data from the model, converts it to an string value, and writes it to the editor widget
    def setEditorData(self, editor: QComboBox, index: QModelIndex) -> None:
        if index.column() == 0:
            editor.setCurrentText(index.model().data(index, Qt.EditRole))
        else:
            return super(ComboBoxDelegate, self).setEditorData(editor, index)

    # Reads the contents of the combo box, and writes it to the model
    def setModelData(self, editor: QComboBox, model: QAbstractItemModel, index: QModelIndex) -> None:
        if index.column() == 0:
            model.setData(index, editor.currentText())
        else:
            return super(ComboBoxDelegate, self).setModelData(editor, model, index)

    # Updates the editor widget’s geometry using the information supplied in the style option
    def updateEditorGeometry(self, editor: QWidget, option: 'QStyleOptionViewItem', index: QModelIndex) -> None:
        if index.column() == 0:
            editor.setGeometry(option.rect)
        else:
            return super(ComboBoxDelegate, self).updateEditorGeometry(editor, option, index)
