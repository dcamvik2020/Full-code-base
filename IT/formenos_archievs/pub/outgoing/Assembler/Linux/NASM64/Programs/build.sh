#! /bin/sh

# Example: ./build.sh hw

nasm -f elf64 $1.asm
nasm -f elf64 ioproc.asm
ld $1.o ioproc.o -o $1
