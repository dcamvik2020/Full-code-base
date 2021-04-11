#! /bin/sh

# Example: ./build.sh hw

as -msyntax=intel -mmnemonic=intel -mnaked-reg $1.s -o $1.o
ld $1.o -o $1
