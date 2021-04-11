%include "io.asm"

section .bss use32 class=BSS

num	resd 1

section .text use32 class=CODE

global _start
_start:
	getn [num]
	getn eax
	add eax, [num]
	putn eax
	newln
	exit 0
