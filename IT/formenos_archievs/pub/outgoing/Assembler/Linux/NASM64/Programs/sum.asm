%include "io.asm"

section .bss

num	resq 1

section .text

global _start
_start:
	getn [num]
	getn rax
	add rax, [num]
	putn rax
	newln
	exit 0
