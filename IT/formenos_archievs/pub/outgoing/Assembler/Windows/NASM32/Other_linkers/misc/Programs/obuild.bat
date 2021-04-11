@REM Example: build hw

..\nasm -f obj %1.asm
..\alink -oPE -subsys console -entry _start %1.obj win32.lib