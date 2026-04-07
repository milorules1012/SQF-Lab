@echo off
setlocal

set "TOOLS_DIR=%~dp0"
set "LINT_PS1=%TOOLS_DIR%HEMTT_light.ps1"

echo Running HEMTT lint check...
powershell -NoProfile -ExecutionPolicy Bypass -File "%LINT_PS1%"
exit /b %errorlevel%
