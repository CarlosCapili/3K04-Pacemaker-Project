import numpy as np
from PyQt5.QtCore import QThread


class GraphsHandler(QThread):
    def __init__(self, atri_plot, vent_plot):
        super().__init__()
        print("Graphs handler init")

        self.atri_data = np.random.normal(size=300)
        self.vent_data = np.random.normal(size=300)

        self.atri_plot = atri_plot
        self.vent_plot = vent_plot

    def plot(self):
        self.atri_plot.plot(self.atri_data)
        self.vent_plot.plot(self.vent_data)
