@echo off

cd %~dp0..\build
msbuild -property:Configuration=Debug ALL_BUILD.vcxproj

pause