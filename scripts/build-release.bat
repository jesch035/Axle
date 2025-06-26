@echo off

cd %~dp0..\build
msbuild -property:Configuration=Release ALL_BUILD.vcxproj

pause