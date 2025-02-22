@echo off
REM build.bat - Script to configure and build the TemperatureMonitor project on Windows
REM Usage:
REM   build.bat        - Normal build
REM   build.bat clean  - Clean (remove build folder) then rebuild

set PROJECT_ROOT=%~dp0..
set BUILD_DIR=%PROJECT_ROOT%\build

if /I "%1"=="clean" (
    echo Performing clean rebuild...
    rmdir /S /Q "%BUILD_DIR%"
)

if not exist "%BUILD_DIR%" (
    echo Creating build directory...
    mkdir "%BUILD_DIR%"
)

pushd "%BUILD_DIR%"
echo Configuring project with CMake...
cmake "%PROJECT_ROOT%"

echo Building the project...
cmake --build .

popd
echo Build complete.
pause
