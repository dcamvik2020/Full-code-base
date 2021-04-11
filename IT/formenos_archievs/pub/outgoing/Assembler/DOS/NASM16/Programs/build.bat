@REM Example: build hw

..\nasm -g -f obj %1.asm
..\tlink /x /v %1.obj