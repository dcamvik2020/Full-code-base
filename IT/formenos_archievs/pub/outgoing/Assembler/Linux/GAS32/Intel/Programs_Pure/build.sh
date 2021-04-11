#! /bin/sh

# Example: ./build.sh hw

as --32 -msyntax=intel -mmnemonic=intel -mnaked-reg $1.s -o $1.o
ld -m elf_i386 $1.o -o $1
