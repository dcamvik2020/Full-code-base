#! /bin/sh

# Example: ./build.sh hw

nasm -f elf $1.asm
ld -m elf_i386 $1.o -o $1
