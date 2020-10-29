import numpy as np
import pyqtgraph as pg
import pyqtgraph.examples
from pyqtgraph.Qt import QtCore, QtGui

pyqtgraph.examples.run()
app = QtGui.QApplication([])
win = pg.GraphicsLayoutWidget(show=True)
win.setWindowTitle('pyqtgraph example: Plotting')
p1 = win.addPlot(title="test graph")
data = np.random.normal(size=100)
c1 = p1.plot(data)
ptr = 0


def update():
    global data
    data[:-1] = data[1:]
    data[-1] = np.random.normal()
    c1.setData(data)


timer = pg.QtCore.QTimer()
timer.timeout.connect(update)
timer.start(500)

if __name__ == '__main__':
    import sys
    if (sys.flags.interactive != 1) or not hasattr(QtCore, 'PYQT_VERSION'):
        QtGui.QApplication.instance().exec_()
