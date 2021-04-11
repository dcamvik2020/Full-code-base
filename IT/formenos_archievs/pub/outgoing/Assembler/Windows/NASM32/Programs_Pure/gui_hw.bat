..\nasm -f obj -D_start=..start gui_hw.asm
..\tlink32 -aa -x gui_hw.obj import32.lib