@REM Example: build hw

..\nasm -f win32 %1.asm
..\GoLink /console %1.obj kernel32.dll