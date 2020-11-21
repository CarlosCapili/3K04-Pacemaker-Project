import numpy as np
from numpy import ndarray
from pyqtgraph import PlotDataItem, PlotWidget

from handlers.connection import ECGData


# This class handles the graphs for the DCM and extends the QThread class to allow for multithreading
class GraphsHandler:
    atri_data_pace: ndarray
    vent_data_pace: ndarray
    atri_data_sense: ndarray
    vent_data_sense: ndarray
    atri_pace_plot: PlotDataItem
    vent_pace_plot: PlotDataItem
    atri_sense_plot: PlotDataItem
    vent_sense_plot: PlotDataItem

    def __init__(self, atri_plot: PlotWidget, vent_plot: PlotWidget):
        print("Graphs handler init")

        # For right now, generate random sample data to plot
        self.atri_data_pace = np.random.normal(size=50)
        self.vent_data_pace = np.random.normal(size=50)
        self.atri_data_sense = np.random.normal(size=50)
        self.vent_data_sense = np.random.normal(size=50)

        # Create new sense and pace plots for the atrial and ventricular graphs, pace plots are red, sense are blue
        self.atri_pace_plot = atri_plot.plot(pen=(252, 93, 93))
        self.vent_pace_plot = vent_plot.plot(pen=(252, 93, 93))
        self.atri_sense_plot = atri_plot.plot(pen=(0, 229, 255))
        self.vent_sense_plot = vent_plot.plot(pen=(0, 229, 255))

        self._plot_data()

    # Update and plot new received data
    def update_data(self, ecg_data: ECGData):
        self.atri_data_pace[:-1] = self.atri_data_pace[1:]
        self.atri_data_pace[-1] = ecg_data.atri_pace

        self.vent_data_pace[:-1] = self.vent_data_pace[1:]
        self.vent_data_pace[-1] = ecg_data.vent_pace

        self.atri_data_sense[:-1] = self.atri_data_sense[1:]
        self.atri_data_sense[-1] = ecg_data.atri_sense

        self.vent_data_sense[:-1] = self.vent_data_sense[1:]
        self.vent_data_sense[-1] = ecg_data.vent_sense

        self._plot_data()

    # Plot the pace and sense data on the graphs
    def _plot_data(self) -> None:
        self.atri_pace_plot.setData(self.atri_data_pace)
        self.vent_pace_plot.setData(self.vent_data_pace)
        self.atri_sense_plot.setData(self.atri_data_sense)
        self.vent_sense_plot.setData(self.vent_data_sense)

    # Show the pace data on the graphs
    def pace_show(self) -> None:
        self.atri_pace_plot.show()
        self.vent_pace_plot.show()

    # Show the sense data on the graphs
    def sense_show(self) -> None:
        self.atri_sense_plot.show()
        self.vent_sense_plot.show()

    # Hide the pace data on the graphs
    def pace_hide(self) -> None:
        self.atri_pace_plot.hide()
        self.vent_pace_plot.hide()

    # Hide the sense data on the graphs
    def sense_hide(self) -> None:
        self.atri_sense_plot.hide()
        self.vent_sense_plot.hide()
