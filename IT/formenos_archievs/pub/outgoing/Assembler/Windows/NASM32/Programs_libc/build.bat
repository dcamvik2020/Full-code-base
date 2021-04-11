@REM Example: build hw

..\nasm -g -f obj -D_start=..start %1.asm
..\tlink32 -x -v %1.obj import32.lib msvcrt.lib