%include "io.asm"

section .text

global _start
_start:
	getn rcx
	mov rdx, 0

	jrcxz exit_loop
main_loop:
	getn rax
	add rdx, rax
	loop main_loop
exit_loop:

	putn rdx
	newln

	exit 0
