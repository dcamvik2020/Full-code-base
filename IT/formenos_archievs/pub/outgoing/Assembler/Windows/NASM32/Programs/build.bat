@REM Example: build hw

..\nasm -g -f obj -D_start=..start %1.asm
..\nasm -f obj ioproc.asm
..\tlink32 -x -v %1.obj ioproc.obj import32.lib