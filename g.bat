@echo off
if not exist "%~dpn1.cpp" echo File not found^! && exit /b
cls
title Compiling %~n1...
echo Compiling %~n1...
g++ -O2 -optl-static "%~dpn1.cpp" -o "%~dpn1.exe"
title %COMSPEC%
::if errorlevel 1 pause>nul
exit /b
:usage
echo Please input file
exit /b
