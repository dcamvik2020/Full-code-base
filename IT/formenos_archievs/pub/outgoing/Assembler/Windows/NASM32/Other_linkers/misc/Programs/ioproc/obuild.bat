@REM Example: build hw

..\nasm -f obj %1.asm
..\nasm -f obj ioproc.asm
..\alink -oPE -subsys console -entry _start %1.obj ioproc.obj win32.lib