@PATH=%PATH%;C:\Qt\Tools\mingw482_32\bin

@REM *** Preprocessor ***
gcc -E -P prog.c -o prog1.c
@REM *** Compiler ***
gcc -S prog1.c
@REM *** Assembler ***
as prog1.s -o prog1.o

@REM *** Preprocessor ***
gcc -E -P unit.c -o unit1.c
@REM *** Compiler ***
gcc -S unit1.c
@REM *** Assembler ***
as unit1.s -o unit1.o

@REM *** Linker ***
gcc prog1.o unit1.o -o prog.exe
