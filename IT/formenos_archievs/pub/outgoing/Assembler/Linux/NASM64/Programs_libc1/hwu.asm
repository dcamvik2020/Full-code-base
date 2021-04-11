section .data

Message	db "Hell, Word!",0xA
Length	equ $ - Message

section .text

extern write

global main
main:
	; write(1, Message, Length);
	mov rdx, Length
	mov rsi, Message
	mov rdi, 1
	call write

	; return 0;
	mov rax, 0
	ret
