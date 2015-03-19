@echo off
for %%* in (.) do set ProjectName=%%~n*
echo %ProjectName%
make
pause