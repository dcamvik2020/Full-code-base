@PATH=%PATH%;C:\Qt\Tools\mingw482_32\bin

@REM *** Compiler ***
gcc -c prog.c
gcc -c unit.c

@REM *** Linker ***
gcc prog.o unit.o -o prog.exe
