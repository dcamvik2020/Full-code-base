section .data

Message	db "Hell, Word!",0xA
Length	equ $ - Message

section .text

extern write
extern _exit

global _start
_start:
	; write(1, Message, Length);
	push Length
	push Message
	push 1
	call write
	add esp, 12

	; _exit(0);
	push 0
	call _exit
;	add esp, 4
