%include "io.asm"

section .bss

buf	resb 10
max	equ $ - buf

section .text

global _start
_start:
	gets buf, max
	puts buf
	newln
	exit 0
