cd .

if "%1"=="" ("D:\school\bin\win64\gmake"  -f light_with_sence.mk all) else ("D:\school\bin\win64\gmake"  -f light_with_sence.mk %1)
@if errorlevel 1 goto error_exit

exit 0

:error_exit
echo The make command returned an error of %errorlevel%
exit 1
