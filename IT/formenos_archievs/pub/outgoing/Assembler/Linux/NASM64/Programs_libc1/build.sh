#! /bin/sh

# Example: ./build.sh hw

nasm -f elf64 $1.asm
gcc $1.o -o $1
