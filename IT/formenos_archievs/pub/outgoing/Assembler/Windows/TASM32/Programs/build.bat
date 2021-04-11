@REM Example: build hw

..\tasm32 /mx /zi %1.asm
..\tasm32 /mx ioproc.asm
..\tlink32 -x -v %1.obj ioproc.obj import32.lib