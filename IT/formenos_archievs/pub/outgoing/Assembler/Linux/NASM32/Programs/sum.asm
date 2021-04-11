%include "io.asm"

section .bss

num	resd 1

section .text

global _start
_start:
	getn [num]
	getn eax
	add eax, [num]
	putn eax
	newln
	exit 0
