#! /bin/sh

# *** Preprocessor ***
gcc -E -P prog.c -o prog1.c
# *** Compiler ***
gcc -S prog1.c
# *** Assembler ***
as prog1.s -o prog1.o

# *** Preprocessor ***
gcc -E -P unit.c -o unit1.c
# *** Compiler ***
gcc -S unit1.c
# *** Assembler ***
as unit1.s -o unit1.o

# *** Linker ***
gcc prog1.o unit1.o -o prog
