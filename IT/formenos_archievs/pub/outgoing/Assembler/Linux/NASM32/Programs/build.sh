#! /bin/sh

# Example: ./build.sh hw

nasm -f elf $1.asm
nasm -f elf ioproc.asm
ld -m elf_i386 $1.o ioproc.o -o $1
