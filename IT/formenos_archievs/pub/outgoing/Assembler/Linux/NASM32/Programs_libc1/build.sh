#! /bin/sh

# Example: ./build.sh hw

nasm -f elf $1.asm
gcc -m32 $1.o -o $1
