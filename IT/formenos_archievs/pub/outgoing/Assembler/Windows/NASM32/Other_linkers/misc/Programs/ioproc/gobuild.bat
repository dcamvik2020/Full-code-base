@REM Example: build hw

..\nasm -f win32 %1.asm
..\nasm -f win32 ioproc.asm
..\GoLink /console /entry _start %1.obj ioproc.obj kernel32.dll