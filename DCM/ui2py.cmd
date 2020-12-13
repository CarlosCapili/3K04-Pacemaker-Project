@ECHO OFF
setlocal enabledelayedexpansion

for %%f in (ui_files\*.ui) do (
    echo "name: %%~nf"
    pyuic5 -x -o py_ui_files/%%~nf.py %%f
)
