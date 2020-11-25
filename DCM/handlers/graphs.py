import numpy as np
from numpy import ndarray
from pyqtgraph import PlotDataItem, PlotWidget


# This class handles the graphs for the DCM and extends the QThread class to allow for multithreading
class GraphsHandler:
    atri_data: ndarray
    vent_data: ndarray
    atri_plot: PlotDataItem
    vent_plot: PlotDataItem

    def __init__(self, atri_plot: PlotWidget, vent_plot: PlotWidget, data_size: int):
        print("Graphs handler init")

        # Initialize graphs to 0
        self.atri_data = np.zeros(data_size)
        self.vent_data = np.zeros(data_size)

        # Create new sense and pace plots for the atrial and ventricular graphs, pace plots are red, sense are blue
        self.atri_plot = atri_plot.plot(pen=(0, 229, 255))
        self.vent_plot = vent_plot.plot(pen=(0, 229, 255))

        self._plot_data()

    # Update and plot new received data
    def update_data(self, atri_data, vent_data):
        size = len(atri_data)
        self.atri_data[:-size] = self.atri_data[size:]
        self.atri_data[-size:] = atri_data

        size = len(vent_data)
        self.vent_data[:-size] = self.vent_data[size:]
        self.vent_data[-size:] = vent_data

        self._plot_data()

    # Plot the pace and sense data on the graphs
    def _plot_data(self) -> None:
        self.atri_plot.setData(self.atri_data)
        self.vent_plot.setData(self.vent_data)

    # Show/hide the atrial data on the graphs
    def atri_vis(self, show: bool) -> None:
        self.atri_plot.show() if show else self.atri_plot.hide()

    # Show/hide the ventricular data on the graphs
    def vent_vis(self, show: bool) -> None:
        self.vent_plot.show() if show else self.vent_plot.hide()
