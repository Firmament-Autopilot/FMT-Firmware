@echo off
cd /d "%~dp0"
@echo on
mklink /D rt-thread ..\..\..\..\rtos\rt-thread
mklink /D libraries ..\libraries
mklink /D libs ..\libs
mklink /D tools ..\tools