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

        self.atri_plot = atri_plot
        self.vent_plot = vent_plot

    def plot(self):
        self.atri_plot.plot(self.atri_data_pace, pen=(252, 93, 93))
        self.atri_plot.plot(self.atri_data_sense, pen=(0, 229, 255))
        self.vent_plot.plot(self.vent_data_pace, pen=(252, 93, 93))
        self.vent_plot.plot(self.vent_data_sense, pen=(0, 229, 255))
