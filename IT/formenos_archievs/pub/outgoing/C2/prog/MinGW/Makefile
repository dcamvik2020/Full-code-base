prog.exe: prog.o unit.o
	gcc prog.o unit.o -o prog.exe

prog.o: prog.c header.h
	gcc -c prog.c

unit.o: unit.c header.h
	gcc -c unit.c

clean:
	del *.o *.exe
