@echo off

set SOURCE_DIR=%~dp0..\
set BUILD_DIR=%SOURCE_DIR%build

if not exist "%BUILD_DIR%" (
    echo Creating build directory...
    mkdir "%BUILD_DIR%"
)

echo Running CMake...

cd /d "%BUILD_DIR%"
cmake .. -A x64

echo CMake generation complete.
pause