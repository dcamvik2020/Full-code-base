%include "io.asm"

section .bss use32 class=BSS

buf	resb 256
max	equ $ - buf

section .text use32 class=CODE

global _start
_start:				; while (gets(buf, max))
	gets buf, max
	cmp eax, 0
	je exit_file_cycle
	puts buf		;	puts(buf);
	newln
	jmp _start
exit_file_cycle:
	exit 0
