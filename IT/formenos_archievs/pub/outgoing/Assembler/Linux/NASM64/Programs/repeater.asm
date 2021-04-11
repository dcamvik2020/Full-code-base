%include "io.asm"

section .bss

buf	resb 256
max	equ $ - buf

section .text

global _start
_start:				; while (gets(buf, max))
	gets buf, max
	cmp rax, 0
	je exit_file_cycle
	puts buf		;	puts(buf);
	newln
	jmp _start
exit_file_cycle:
	exit 0
