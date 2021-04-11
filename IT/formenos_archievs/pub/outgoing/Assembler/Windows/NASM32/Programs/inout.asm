%include "io.asm"

section .bss use32 class=BSS

buf	resb 10
max	equ $ - buf

section .text use32 class=CODE

global _start
_start:
	gets buf, max
	puts buf
	newln
	exit 0
