include io.asm
.386
.model flat

.data

c	db 0
buf	db 255 dup(0)
max	equ $ - buf

.code



; parameters: al = char to find; edi = address of string
; return: edi = first position (address) of char in the string
strchr proc

begin_cycle:
	cmp byte ptr [edi], 0
	je exit_cycle
	cmp [edi], al
	je char_found
	inc edi
	jmp begin_cycle

exit_cycle:
	mov edi, 0		; not found

char_found:
	ret
strchr endp



; parameters: al = char to find; edi = address of string; ecx = length of string
; return: edi = first position (address) of char in the string
strnchr proc
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
strnchr endp



; parameters: al = char to find; edi = address of string; ecx = length of string
; return: edi = first position (address) of char in the string
strnchr_pro proc
	cld

repne	scasb			; for (ecx; ecx > 0 && es:[edi++] != al; ecx--)

	je char_found_pro
	mov edi, 1		; not found
char_found_pro:
	dec edi
	ret
strnchr_pro endp



Entry:
	gets max, offset buf
	getc c

	mov al, c
	mov edi, offset buf
	call strchr
	cmp edi, 0
	je skip_print1
	puts edi
	newln
skip_print1:

	mov al, c
	mov edi, offset buf
	mov ecx, max
	call strnchr
	cmp edi, 0
	je skip_print2
	puts edi
	newln
skip_print2:

	mov al, c
	mov edi, offset buf
	mov ecx, max
	call strnchr_pro
	cmp edi, 0
	je skip_print3
	puts edi
	newln
skip_print3:

	exit 0
end Entry
