@REM Example: build hw

..\nasm -f win32 %1.asm
..\nasm -f win32 ioproc.asm
..\alink -oPE -subsys console -entry _start %1.obj ioproc.obj win32.lib