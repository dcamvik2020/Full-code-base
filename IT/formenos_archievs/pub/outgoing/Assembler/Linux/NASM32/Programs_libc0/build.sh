#! /bin/sh

# Example: ./build.sh hw

nasm -f elf $1.asm
ld -m elf_i386 -dynamic-linker /lib/ld-linux.so.2 -lc $1.o -o $1
