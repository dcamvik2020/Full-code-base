include io.asm
.386
.model flat

.data

len	dd 0
buf	db 16 dup(0)
max	equ $ - buf
buf1	db 16 dup(0)

.code



; parameters: esi = address of source string; edi = address of dest. string; ecx = length of string
strncpy proc
	cld

rep	movsb			; for (ecx; ecx > 0; ecx--) es:[edi++] = ds:[esi++];

	mov byte ptr [edi], 0
	ret
strncpy endp



; parameters: al = char to fill; edi = address of string; ecx = length of string
strnset proc
	cld

rep	stosb			; for (ecx; ecx > 0; ecx--) es:[edi++] = al;

	ret
strnset endp



; parameters: esi = address of first string; edi = address of second string; ecx = length of string
; return: eax = 1 if equal; eax = 0 if not equal
strncmp proc
	mov eax, 0
	cld

repe	cmpsb			; for (ecx; ecx > 0 && es:[edi++] == ds:[esi++]; ecx--);

	jne not_equal
	mov eax, 1
not_equal:
	ret
strncmp endp



; parameters: al = char to find; edi = address of string; ecx = length of string
; return: edi = first position (address) of char in the string
strnchr proc
	cld

repne	scasb			; for (ecx; ecx > 0 && es:[edi++] != al; ecx--);

	je char_found
	mov edi, 1		; not found
char_found:
	dec edi
	ret
strnchr endp



; parameters: edi = address of string
; return: eax = length of the string
strlen proc
	mov edx, edi
	mov ecx, 0FFFFFFFFh
	cld
	mov al, 0

repne	scasb			; for (ecx; ecx > 0 && es:[edi++] != al; ecx--);

	dec edi			; or:	mov eax, 0xFFFFFFFE
	mov eax, edi		;	sub eax, ecx
	sub eax, edx
	ret
strlen endp



Entry:
	gets max, offset buf

	mov edi, offset buf
	call strlen
	mov len, eax
	putn eax
	newln

	mov esi, offset buf
	mov edi, offset buf1
	mov ecx, len
	call strncpy
	puts offset buf1
	newln

	mov esi, offset buf
	mov edi, offset buf1
	mov ecx, len
	call strncmp
	cmp eax, 0
	je skip_print
	putc '='
	newln
skip_print:

	mov al, '0'
	mov edi, offset buf1
	mov ecx, len
	call strnset

	getc al

	mov edi, offset buf
	mov ecx, len
	call strnchr
	cmp edi, 0
	je skip_print3
	puts edi
	newln
skip_print3:

	exit 0
end Entry
