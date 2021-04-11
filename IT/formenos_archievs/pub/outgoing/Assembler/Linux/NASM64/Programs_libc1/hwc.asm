section .data

Message	db "Hell, Word!",0

section .text

extern puts

global main
main:
	; puts(Message);
	mov rdi, Message
	call puts

	; return 0;
	mov rax, 0
	ret
