@echo off
g++ ..\src\test_lib\catch_amalgamated.cpp ..\src\list.cpp ..\src\task.cpp ..\src\test_main.cpp -o ..\exec\test.exe
..\exec\test.exe