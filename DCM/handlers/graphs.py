import numpy as np
from numpy import ndarray
from pyqtgraph import PlotDataItem, PlotWidget


# This class handles the graphs for the DCM
class GraphsHandler:
    _atri_data: ndarray
    _vent_data: ndarray
    _atri_plot: PlotDataItem
    _vent_plot: PlotDataItem

    def __init__(self, atri_plot: PlotWidget, vent_plot: PlotWidget, data_size: int):
        print("Graphs handler init")

        # noinspection PyArgumentList
        atri_plot.setRange(xRange=[-1, data_size], yRange=[-0.5, 5.5], padding=0)
        atri_plot.setLimits(xMin=-1, xMax=data_size, maxXRange=data_size + 1, yMin=-0.5, yMax=5.5)
        atri_plot.setMouseEnabled(x=True, y=False)
        atri_plot.enableAutoRange(x=False, y=True)
        atri_plot.setAutoVisible(x=False, y=True)
        atri_plot.showGrid(x=True, y=True)
        atri_plot.hideButtons()
        atri_plot.setMenuEnabled(False)
        atri_plot.setLabel('left', "Amplitude", units='V', **{'color': '#FFF', 'font-size': '10pt'})
        atri_plot.setLabel('bottom', "Time", units='s', **{'color': '#FFF', 'font-size': '10pt'})
        atri_plot.getAxis('bottom').setHeight(30)
        # noinspection PyArgumentList
        vent_plot.setRange(xRange=[-1, data_size], yRange=[-0.5, 5.5], padding=0)
        vent_plot.setLimits(xMin=-1, xMax=data_size, maxXRange=data_size + 1, yMin=-0.5, yMax=5.5)
        vent_plot.setMouseEnabled(x=True, y=False)
        vent_plot.enableAutoRange(x=False, y=True)
        vent_plot.setAutoVisible(x=False, y=True)
        vent_plot.showGrid(x=True, y=True)
        vent_plot.hideButtons()
        vent_plot.setMenuEnabled(False)
        vent_plot.setLabel('left', "Amplitude", units='V', **{'color': '#FFF', 'font-size': '10pt'})
        vent_plot.setLabel('bottom', "Time", units='s', **{'color': '#FFF', 'font-size': '10pt'})
        vent_plot.getAxis('bottom').setHeight(30)

        # Initialize graphs to 0
        self._atri_data = np.zeros(data_size)
        self._vent_data = np.zeros(data_size)

        # Create new sense plots for the atrial and ventricular graphs, in blue
        self._atri_plot = atri_plot.plot(pen=(0, 229, 255))
        self._vent_plot = vent_plot.plot(pen=(0, 229, 255))

        self._plot_data()

    # Plot the sense data on the graphs
    def _plot_data(self) -> None:
        self._atri_plot.setData(self._atri_data)
        self._vent_plot.setData(self._vent_data)

    # Update and plot new received data
    def update_data(self, atri_data: tuple, vent_data: tuple):
        size = len(atri_data)
        self._atri_data[:-size] = self._atri_data[size:]
        self._atri_data[-size:] = atri_data

        size = len(vent_data)
        self._vent_data[:-size] = self._vent_data[size:]
        self._vent_data[-size:] = vent_data

        self._plot_data()

    # Show/hide the atrial data on the graphs
    def atri_vis(self, show: bool) -> None:
        self._atri_plot.show() if show else self._atri_plot.hide()

    # Show/hide the ventricular data on the graphs
    def vent_vis(self, show: bool) -> None:
        self._vent_plot.show() if show else self._vent_plot.hide()
