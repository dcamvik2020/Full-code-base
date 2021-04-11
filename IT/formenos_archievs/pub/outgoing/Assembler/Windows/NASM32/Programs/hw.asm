%include "io.asm"

section .data use32 class=DATA

Message	db "Hell, Word!",0

section .text use32 class=CODE

global _start
_start:
	puts Message
	newln
	exit 0
