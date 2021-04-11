%include "io.asm"

section .data

Message	db "Hell, Word!",0

section .text

global _start
_start:
	puts Message
	newln
	exit 0
