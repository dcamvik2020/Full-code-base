@REM Example: build hw

..\tasm32 /mx /zi %1.asm
..\tlink32 -x -v %1.obj import32.lib