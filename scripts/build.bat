@echo off
REM build.bat - Script to configure and build the project on Windows
REM Usage:
REM   build.bat         - Build the project (creates build\ if needed)
REM   build.bat clean   - Clean and rebuild the project

set BUILD_DIR=build

REM Check if first argument is "clean"
if /I "%1"=="clean" (
    echo Performing clean rebuild...
    rmdir /S /Q %BUILD_DIR%
)

REM Create the build directory if it doesn't exist
if not exist %BUILD_DIR% (
    echo Creating build directory...
    mkdir %BUILD_DIR%
)

REM Change to the build directory
pushd %BUILD_DIR%

echo Configuring project with CMake...
cmake ..

echo Building the project...
cmake --build . --config Release

popd
echo Build complete.
pause
