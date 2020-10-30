import numpy as np
from PyQt5.QtCore import QThread
from pyqtgraph import PlotWidget


class GraphsHandler(QThread):
    def __init__(self, atri_plot: PlotWidget, vent_plot: PlotWidget):
        super().__init__()
        print("Graphs handler init")

        self.atri_data_pace = np.random.normal(size=100)
        self.vent_data_pace = np.random.normal(size=100)
        self.atri_data_sense = np.random.normal(size=100)
        self.vent_data_sense = np.random.normal(size=100)

        self.atri_pace_plot = atri_plot.plot(pen=(252, 93, 93))
        self.atri_sense_plot = atri_plot.plot(pen=(0, 229, 255))

        self.vent_pace_plot = vent_plot.plot(pen=(252, 93, 93))
        self.vent_sense_plot = vent_plot.plot(pen=(0, 229, 255))

    def pace_plot(self):
        self.atri_pace_plot.setData(self.atri_data_pace)
        self.vent_pace_plot.setData(self.vent_data_pace)

    def sense_plot(self):
        self.atri_sense_plot.setData(self.vent_data_sense)
        self.vent_sense_plot.setData(self.atri_data_sense)

    def pace_show(self):
        self.atri_pace_plot.show()
        self.vent_pace_plot.show()

    def sense_show(self):
        self.atri_sense_plot.show()
        self.vent_sense_plot.show()

    def pace_hide(self):
        self.atri_pace_plot.hide()
        self.vent_pace_plot.hide()

    def sense_hide(self):
        self.atri_sense_plot.hide()
        self.vent_sense_plot.hide()
