section .data

Message	db "Hell, Word!",0xA
Length	equ $ - Message

section .text

extern write
extern _exit

global _start
_start:
	; write(1, Message, Length);
	mov rdx, Length
	mov rsi, Message
	mov rdi, 1
	call write

	; _exit(0);
	mov rdi, 0
	call _exit
