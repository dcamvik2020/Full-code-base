@REM Example: build hw

..\nasm -f obj %1.asm
..\alink -oPE -subsys console %1.obj win32.lib