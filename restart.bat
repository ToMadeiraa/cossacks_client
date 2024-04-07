@echo off
Echo %~dp0
Echo %~d0

if exist %~dp0Updates\cossacks_qt.exe (
	taskkill /f /im cossacks_qt.exe
	start %~dp0debug\cossacks_qt.exe
)