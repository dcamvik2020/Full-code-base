section .bss

buf	resb 10
max	equ $ - buf
len	resq 1

section .text

global _start
_start:
	; ssize_t read(int fd, void *buf, size_t count);
	mov rax, 0		; read
	mov rdi, 0		; stdin
	mov rsi, buf
	mov rdx, max
	syscall
	mov [len], rax

	; ssize_t write(int fd, const void *buf, size_t count);
	mov rax, 1		; write
	mov rdi, 1		; stdout
;	mov rsi, buf
	mov rdx, [len]
	syscall

	; void _exit(int status);
	mov rax, 60		; _exit
	mov rdi, 0
	syscall
