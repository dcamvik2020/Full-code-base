@REM Example: build hw

..\nasm -g -f obj %1.asm
..\tlink32 -x -v %1.obj import32.lib