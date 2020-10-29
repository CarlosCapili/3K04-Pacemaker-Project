import numpy as np
import pyqtgraph as pg


class GraphsHandler:
    def __init__(self):
        print("Graphs handler init")

    def plot(self, data):
        self.graphWidget.plot(data)
