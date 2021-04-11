section .data

Message	db "Hell, Word!",0

section .text

extern puts
extern exit

global _start
_start:
	; puts(Message);
	mov rdi, Message
	call puts

	; exit(0);
	mov rdi, 0
	call exit
