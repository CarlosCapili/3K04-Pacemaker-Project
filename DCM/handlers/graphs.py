import numpy as np
from PyQt5.QtCore import QThread


class GraphsHandler(QThread):
    def __init__(self, atri_plot, vent_plot):
        super().__init__()
        print("Graphs handler init")

        self.atri_data_pace = np.random.normal(size=100)
        self.vent_data_pace = np.random.normal(size=100)
        self.atri_data_sense = np.random.normal(size=100)
        self.vent_data_sense = np.random.normal(size=100)

        self.atri_pace_plot = atri_plot.plot()
        self.atri_sense_plot = atri_plot.plot()

        self.vent_pace_plot = vent_plot.plot()
        self.vent_sense_plot = vent_plot.plot()

    def pace_plot(self):
        self.atri_pace_plot.setData(self.atri_data_pace, pen=(252, 93, 93))
        self.vent_pace_plot.setData(self.vent_data_pace, pen=(252, 93, 93))

    def sense_plot(self):
        self.atri_sense_plot.setData(self.vent_data_sense, pen=(0, 229, 255))
        self.vent_sense_plot.setData(self.atri_data_sense, pen=(0, 229, 255))

    def pace_clear(self):
        self.atri_pace_plot.clear()
        self.vent_pace_plot.clear()

    def sense_clear(self):
        self.atri_sense_plot.clear()
        self.vent_sense_plot.clear()
