%include "io.asm"

section .bss

c	resb 1
buf	resb 255
max	equ $ - buf

section .text



; parameters: al = char to find; rdi = address of string
; return: rdi = first position (address) of char in the string
strchr:				; begin_cycle:
	cmp byte [rdi], 0
	je exit_cycle
	cmp [rdi], al
	je char_found
	inc rdi
	jmp strchr

exit_cycle:
	mov rdi, 0		; not found

char_found:
	ret



; parameters: al = char to find; rdi = address of string; rcx = length of string
; return: rdi = first position (address) of char in the string
strnchr:
	jrcxz end_loop
begin_loop:
	cmp [rdi], al
	je char_found_n
	inc rdi
	loop begin_loop
end_loop:

	mov rdi, 0		; not found

char_found_n:
	ret



; parameters: al = char to find; rdi = address of string; rcx = length of string
; return: rdi = first position (address) of char in the string
strnchr_pro:
	cld

repne	scasb			; for (rcx; rcx > 0 && [rdi++] != al; rcx--)

	je char_found_pro
	mov rdi, 1		; not found
char_found_pro:
	dec rdi
	ret



global _start
_start:
	gets buf, max
	getc [c]

	mov al, [c]
	mov rdi, buf
	call strchr
	cmp rdi, 0
	je skip_print1
	puts rdi
	newln
skip_print1:

	mov al, [c]
	mov rdi, buf
	mov rcx, max
	call strnchr
	cmp rdi, 0
	je skip_print2
	puts rdi
	newln
skip_print2:

	mov al, [c]
	mov rdi, buf
	mov rcx, max
	call strnchr_pro
	cmp rdi, 0
	je skip_print3
	puts rdi
	newln
skip_print3:

	exit 0
