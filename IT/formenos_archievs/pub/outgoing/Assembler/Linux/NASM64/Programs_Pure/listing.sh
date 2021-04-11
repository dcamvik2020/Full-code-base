#! /bin/sh

nasm -f elf64 $1.asm -l $1.lst
