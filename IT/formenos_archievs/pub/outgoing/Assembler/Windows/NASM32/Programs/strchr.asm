%include "io.asm"

section .bss use32 class=BSS

c	resb 1
buf	resb 255
max	equ $ - buf

section .text use32 class=CODE



; parameters: al = char to find; edi = address of string
; return: edi = first position (address) of char in the string
strchr:				; begin_cycle:
	cmp byte [edi], 0
	je exit_cycle
	cmp [edi], al
	je char_found
	inc edi
	jmp strchr

exit_cycle:
	mov edi, 0		; not found

char_found:
	ret



; parameters: al = char to find; edi = address of string; ecx = length of string
; return: edi = first position (address) of char in the string
strnchr:
	jecxz end_loop
begin_loop:
	cmp [edi], al
	je char_found_n
	inc edi
	loop begin_loop
end_loop:

	mov edi, 0		; not found

char_found_n:
	ret



; parameters: al = char to find; edi = address of string; ecx = length of string
; return: edi = first position (address) of char in the string
strnchr_pro:
	cld

repne	scasb			; for (ecx; ecx > 0 && es:[edi++] != al; ecx--)

	je char_found_pro
	mov edi, 1		; not found
char_found_pro:
	dec edi
	ret



global _start
_start:
	gets buf, max
	getc [c]

	mov al, [c]
	mov edi, buf
	call strchr
	cmp edi, 0
	je skip_print1
	puts edi
	newln
skip_print1:

	mov al, [c]
	mov edi, buf
	mov ecx, max
	call strnchr
	cmp edi, 0
	je skip_print2
	puts edi
	newln
skip_print2:

	mov al, [c]
	mov edi, buf
	mov ecx, max
	call strnchr_pro
	cmp edi, 0
	je skip_print3
	puts edi
	newln
skip_print3:

	exit 0
