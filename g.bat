@echo off
for %%f in ("%~1") do set basename=%%~nf
for %%f in ("%~1") do set extension=%%~xf
::if "%extension%"=="" set extension=.cpp
set parentdir=%~dp1
set file=%parentdir%%basename%%extension%
if "%file%"=="%extension%" goto end
if not exist "%file%" goto nofile
cls
g++ "%file%" -O2 -o "%parentdir%%basename%"
exit /b
:end
echo Please input file
exit /b
:nofile
echo File not found^!
exit /b