..\nasm -f obj ioproc.asm && ..\nasm -g -f obj -D_start=..start t.asm && ..\tlink32 -x -v t.obj ioproc.obj import32.lib