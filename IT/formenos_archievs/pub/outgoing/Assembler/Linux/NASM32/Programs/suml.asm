%include "io.asm"

section .text

global _start
_start:
	getn ecx
	mov edx, 0

	jecxz exit_loop
main_loop:
	getn eax
	add edx, eax
	loop main_loop
exit_loop:

	putn edx
	newln

	exit 0
