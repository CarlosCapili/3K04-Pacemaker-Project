cd .

if "%1"=="" ("D:\school\bin\win64\gmake"  -f Assignment1.mk all) else ("D:\school\bin\win64\gmake"  -f Assignment1.mk %1)
@if errorlevel 1 goto error_exit

exit 0

:error_exit
echo The make command returned an error of %errorlevel%
exit 1
