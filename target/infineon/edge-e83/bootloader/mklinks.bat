@echo off
cd /d "%~dp0"
@echo on
mklink /D libraries ..\libraries
mklink /D libs ..\libs
mklink /D tools ..\tools