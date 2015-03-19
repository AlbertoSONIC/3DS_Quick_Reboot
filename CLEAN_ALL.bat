@echo off
for %%* in (.) do set ProjectName=%%~n*
echo %ProjectName%
make clean
rm -fr %ProjectName%.3ds %ProjectName%.cia
pause