#! /bin/sh

# Example: ./build.sh hw

nasm -f elf64 $1.asm
ld -dynamic-linker /lib/ld-linux-x86-64.so.2 -lc $1.o -o $1
