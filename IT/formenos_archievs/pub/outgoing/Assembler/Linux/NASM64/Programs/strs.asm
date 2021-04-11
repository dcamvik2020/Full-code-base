%include "io.asm"

section .bss

len	resq 1
buf	resb 16
max	equ $ - buf
buf1	resb 16

section .text



; parameters: rsi = address of source string; rdi = address of dest. string; rcx = length of string
strncpy:
	cld

rep	movsb			; for (rcx; rcx > 0; rcx--) [rdi++] = [rsi++];

	mov byte [rdi], 0
	ret



; parameters: al = char to fill; rdi = address of string; rcx = length of string
strnset:
	cld

rep	stosb			; for (rcx; rcx > 0; rcx--) [rdi++] = al;

	ret



; parameters: rsi = address of first string; rdi = address of second string; rcx = length of string
; return: rax = 1 if equal; rax = 0 if not equal
strncmp:
	mov rax, 0
	cld

repe	cmpsb			; for (rcx; rcx > 0 && [rdi++] == [rsi++]; rcx--);

	jne not_equal
	mov rax, 1
not_equal:
	ret



; parameters: al = char to find; rdi = address of string; rcx = length of string
; return: rdi = first position (address) of char in the string
strnchr:
	cld

repne	scasb			; for (rcx; rcx > 0 && [rdi++] != al; rcx--);

	je char_found
	mov rdi, 1		; not found
char_found:
	dec rdi
	ret



; parameters: rdi = address of string
; return: rax = length of the string
strlen:
	mov rdx, rdi
	mov rcx, -1
	cld
	mov al, 0

repne	scasb			; for (rcx; rcx > 0 && [rdi++] != al; rcx--);

	dec rdi			; or:	mov rax, -2
	mov rax, rdi		;	sub rax, rcx
	sub rax, rdx
	ret



global _start
_start:
	gets buf, max

	mov rdi, buf
	call strlen
	mov [len], rax
	putn rax
	newln

	mov rsi, buf
	mov rdi, buf1
	mov rcx, [len]
	call strncpy
	puts buf1
	newln

	mov rsi, buf
	mov rdi, buf1
	mov rcx, [len]
	call strncmp
	cmp rax, 0
	je skip_print
	putc '='
	newln
skip_print:

	mov al, '0'
	mov rdi, buf1
	mov rcx, [len]
	call strnset

	getc al

	mov rdi, buf
	mov rcx, [len]
	call strnchr
	cmp rdi, 0
	je skip_print3
	puts rdi
	newln
skip_print3:

	exit 0
