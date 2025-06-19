@echo off
setlocal

REM === Settings ===
set SOURCE_DIR=%~dp0
set BUILD_DIR=%SOURCE_DIR%build

REM === Create build directory if it doesn't exist ===
if not exist "%BUILD_DIR%" (
    echo Creating build directory...
    mkdir "%BUILD_DIR%"
)

REM === Run CMake to generate solution ===
echo Running CMake...
cd /d "%BUILD_DIR%"
cmake .. -A x64
if errorlevel 1 (
    echo CMake configuration failed!
    pause
    exit /b 1
)

echo CMake generation complete.
pause
endlocal