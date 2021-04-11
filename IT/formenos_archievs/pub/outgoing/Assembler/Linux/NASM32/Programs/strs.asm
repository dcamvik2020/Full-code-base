%include "io.asm"

section .bss

len	resd 1
buf	resb 16
max	equ $ - buf
buf1	resb 16

section .text



; parameters: esi = address of source string; edi = address of dest. string; ecx = length of string
strncpy:
	cld

rep	movsb			; for (ecx; ecx > 0; ecx--) es:[edi++] = ds:[esi++];

	mov byte [edi], 0
	ret



; parameters: al = char to fill; edi = address of string; ecx = length of string
strnset:
	cld

rep	stosb			; for (ecx; ecx > 0; ecx--) es:[edi++] = al;

	ret



; parameters: esi = address of first string; edi = address of second string; ecx = length of string
; return: eax = 1 if equal; eax = 0 if not equal
strncmp:
	mov eax, 0
	cld

repe	cmpsb			; for (ecx; ecx > 0 && es:[edi++] == ds:[esi++]; ecx--);

	jne not_equal
	mov eax, 1
not_equal:
	ret



; parameters: al = char to find; edi = address of string; ecx = length of string
; return: edi = first position (address) of char in the string
strnchr:
	cld

repne	scasb			; for (ecx; ecx > 0 && es:[edi++] != al; ecx--);

	je char_found
	mov edi, 1		; not found
char_found:
	dec edi
	ret



; parameters: edi = address of string
; return: eax = length of the string
strlen:
	mov edx, edi
	mov ecx, 0xFFFFFFFF
	cld
	mov al, 0

repne	scasb			; for (ecx; ecx > 0 && es:[edi++] != al; ecx--);

	dec edi			; or:	mov eax, 0xFFFFFFFE
	mov eax, edi		;	sub eax, ecx
	sub eax, edx
	ret



global _start
_start:
	gets buf, max

	mov edi, buf
	call strlen
	mov [len], eax
	putn eax
	newln

	mov esi, buf
	mov edi, buf1
	mov ecx, [len]
	call strncpy
	puts buf1
	newln

	mov esi, buf
	mov edi, buf1
	mov ecx, [len]
	call strncmp
	cmp eax, 0
	je skip_print
	putc '='
	newln
skip_print:

	mov al, '0'
	mov edi, buf1
	mov ecx, [len]
	call strnset

	getc al

	mov edi, buf
	mov ecx, [len]
	call strnchr
	cmp edi, 0
	je skip_print3
	puts edi
	newln
skip_print3:

	exit 0
