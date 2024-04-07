@echo off
Echo %~dp0
Echo %~d0

if exist %~dp0Updates\cossacks_qt.exe (
	del /f /s /q %~dp0debug\cossacks_qt.exe
	move /y %~dp0Updates\cossacks_qt.exe %~dp0debug\cossacks_qt.exe 
	start %~dp0debug\cossacks_qt.exe
)