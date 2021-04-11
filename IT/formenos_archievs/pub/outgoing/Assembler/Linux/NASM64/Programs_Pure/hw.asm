section .data

Message	db "Hell, Word!",0xA
Length	equ $ - Message

section .text

global _start
_start:
	; ssize_t write(int fd, const void *buf, size_t count);
	mov rax, 1		; write
	mov rdi, 1		; stdout
	mov rsi, Message
	mov rdx, Length
	syscall

	; void _exit(int status);
	mov rax, 60		; _exit
	mov rdi, 0
	syscall
