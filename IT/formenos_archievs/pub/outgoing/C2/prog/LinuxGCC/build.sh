#! /bin/sh

# *** Compiler ***
gcc -c prog.c
gcc -c unit.c

# *** Linker ***
gcc prog.o unit.o -o prog
