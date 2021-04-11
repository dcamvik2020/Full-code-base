%include "io.asm"

section .bss

num	resd 1

section .text

global _start
_start:
	getn [num]
	mov edx, 0

	mov edi, 0
main_cycle:
	cmp edi, [num]
	jae exit_cycle
	getn eax
	add edx, eax
	inc edi
	jmp main_cycle
exit_cycle:

	putn edx
	newln

	exit 0
