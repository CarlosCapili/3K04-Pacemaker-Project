import glob
import inspect
import os
from pathlib import Path


class StyleHandler:
    def __init__(self):
        print("Style handler init")

        self.styles = {}

        for f_name in glob.glob(os.path.join("stylesheets", '*.css')):  # get all css files in stylesheets dir
            with open(f_name) as f:
                key = Path(f_name).stem  # get name of file without extension
                self.styles[key] = f.read()

    def no_conn_status_bar(self):
        return self.styles[inspect.currentframe().f_code.co_name]
