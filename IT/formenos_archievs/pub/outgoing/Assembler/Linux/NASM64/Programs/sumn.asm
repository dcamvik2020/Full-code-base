%include "io.asm"

section .bss

num	resq 1

section .text

global _start
_start:
	getn [num]
	mov rdx, 0

	mov rdi, 0
main_cycle:
	cmp rdi, [num]
	jae exit_cycle
	getn rax
	add rdx, rax
	inc rdi
	jmp main_cycle
exit_cycle:

	putn rdx
	newln

	exit 0
