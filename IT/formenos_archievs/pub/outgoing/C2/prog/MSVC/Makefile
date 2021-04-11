CFLAGS=/nologo
LFLAGS=/nologo

prog.exe: prog.obj unit.obj
	link $(LFLAGS) prog.obj unit.obj

prog.obj: prog.c header.h
	cl $(CFLAGS) /c prog.c

unit.obj: unit.c header.h
	cl $(CFLAGS) /c unit.c

clean:
	del *.obj *.exe
