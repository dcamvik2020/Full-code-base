; Standard Input/Output library, version 3.2E1.2015.04.06
; Written by Andrey Tretyakov, 28.03.2013, 12.03.2015, 24.03.2015

section .bss

; for input
index	resd 1
MAXBUF	equ 15
buffer	resb MAXBUF + 1


section .text


; ==================== INPUT (buffered) ====================


; return: EAX = the number of read bytes
fillbuf:
	push ebx
	push ecx
	push edx

	; ssize_t read(int fd, void *buf, size_t count);
	mov eax, 3		; syscall = read
	mov ebx, 0		; fd = stdin
	mov ecx, buffer		; buf = buffer
	mov edx, MAXBUF		; count = MAXBUF
	int 0x80

	mov dword [index], 0
	mov byte [buffer+eax], 0 ; buffer[len] = '\0';

	pop edx
	pop ecx
	pop ebx
	ret


global getchr

; return: AL = character
getchr:
	push eax
	mov eax, [index]
	cmp byte [buffer+eax], 0 ; if (buffer[index] == '\0')
	jne get_char
	call fillbuf
	cmp eax, 0		;	if (fillbuf() == 0)
	jne get_char
	mov [esp], al
	pop eax
	ret			;		return '\0';
get_char:
	mov eax, [index]
	mov al, [buffer+eax]	; return buffer[index++];
	inc dword [index]
	mov [esp], al		; hack to save high bytes of eax
	pop eax
	ret


global getstr

; parameters: EAX = address of buffer; ECX = size of buffer
; return: EAX = old value on success, EAX = 0 on error or EOF
getstr:
	pushad
	mov edx, eax
	mov al, 0		; al = '\0';
	mov edi, 0		; edi = 0
	cmp ecx, 0
	je skip_parsing
	dec ecx

read_cycle:			; for (...)
	cmp edi, ecx		; edi < ecx - 1 &&
	jae exit_read_cycle
	call getchr		; al = getchr()
	cmp al, 10		; al != '\n' &&
	je exit_read_cycle
	cmp al, 0		; al != '\0'
	je exit_read_cycle
	mov [edx+edi], al	;	edx[edi] = al;
	inc edi			; edi++
	jmp read_cycle
exit_read_cycle:

	inc ecx
	cmp edi, 0		; if (edi > 0 &&
	jbe skip_parsing
	cmp byte [edx+edi-1], 13	; edx[edi-1] == '\r')
	jne skip_parsing
	dec edi			;	edi--;
skip_parsing:

	mov byte [edx+edi], 0	; edx[edi] = '\0';
	cmp edi, 0		; if (edi == 0 &&
	jne exit_getstr
	cmp al, 0		;     al == '\0')
	jne exit_getstr
	popad
	mov eax, 0		;	return NULL;
	ret
exit_getstr:
	popad			; return eax;
	ret


global getnum

; return: EAX = signed dword
getnum:
whitespace_cycle:		; while (...)
	call getchr		; al = getchr();
	cmp al, ' '		; al == ' ' ||
	je whitespace_cycle
	cmp al, 9		; al == '\t' ||
	je whitespace_cycle
	cmp al, 13		; al == '\r' ||
	je whitespace_cycle
	cmp al, 10		; al == '\n'
	je whitespace_cycle

	cmp al, 0		; if (al == '\0')
	jne check_sign
	mov eax, 0		;	return 0;
	ret

check_sign:
	push ecx
	push edx
	mov ch, 1		; ch = 1; //sign
	cmp al, '-'		; if (al == '-')
	jne positive_str
	mov ch, -1		;	ch = -1;
	jmp exit_sign
positive_str:			; else
	dec dword [index]	;	index--;
exit_sign:

	mov eax, 0		; eax = 0;

next_characher:			; while (...)

	push eax
	call getchr		; cl = getchr()
	mov cl, al
	pop eax

	sub cl, '0'
	cmp cl, 9		; cl - '0' >= 0 && cl - '0' <= 9 &&
	ja exit_parse_cycle
	cmp eax, 429496729	; if won'n be overflow
	ja exit_parse_cycle
	mov edx, 10
	mul edx			; {	eax *= 10;				//eax * edx = edx:eax
	movzx edx, cl
	add eax, edx		;	eax += cl - '0';
	jmp next_characher	; }
exit_parse_cycle:

	dec dword [index]	; index--;
	cmp ch, -1		; if (ch == -1)
	jne exit_getnum
	neg eax			;	eax = -eax;
exit_getnum:
	pop edx
	pop ecx
	ret			; return eax;


; ==================== OUTPUT (non-buffered) ====================


; parameters: EAX = address of string, ECX = length of the string
flushbuf:
	pushad

	; ssize_t write(int fd, const void *buf, size_t count);
	mov edx, ecx		; count = ecx
	mov ecx, eax		; buf = eax
	mov ebx, 1		; fd = stdout
	mov eax, 4		; syscall = write
	int 0x80

	popad
	ret


; global strlen

; parameters: EAX = address of string
; return: EAX = length of the string
strlen:
	push ecx
	push edi
	mov edi, eax
	mov ecx, 0xFFFFFFFF
	cld
	mov al, 0

repne	scasb			; for (ecx; ecx > 0 && [edi++] != al; ecx--);

	mov eax, 0xFFFFFFFE
	sub eax, ecx
	pop edi
	pop ecx
	ret


global putstr

; parameters: EAX = address of string
putstr:
	push ecx
	push eax
	call strlen		; ecx = strlen(eax);
	mov ecx, eax
	pop eax
	call flushbuf
	pop ecx
	ret


global putchr

; parameters: AL = character
putchr:
	push ecx
	push eax
	mov ecx, 1
	mov eax, esp
	call flushbuf
	pop eax
	pop ecx
	ret


global newline

newline:
	push ecx
	push eax
	push 0x0A		; reverse \n\0\0\0
	mov ecx, 1
	mov eax, esp
	call flushbuf
	pop eax
	pop eax
	pop ecx
	ret


; global utostr

; parameters: EAX = unsigned dword; ECX = address of buffer
utostr:
	pushad
	mov ebx, ecx
	mov edi, ecx
	mov ecx, 10

next_digit:			; do {
	mov edx, 0
	div ecx			;	edx = eax % 10; eax /= 10;		// edx:eax / ecx = eax + edx / ecx
	add dl, '0'
	mov [edi], dl		;	[edi++] = dl + '0';
	inc edi
	cmp eax, 0
	ja next_digit		; } while (eax != 0);

	mov byte [edi], 0
	dec edi
reverse:			; do {
	mov dl, [ebx]
	xchg dl, [edi]		;	swap([ebx++], [edi--]);
	mov [ebx], dl
	inc ebx
	dec edi
	cmp ebx, edi
	jl reverse		; } while (ebx < edx);

	popad
	ret


; global itostr

; parameters: EAX = signed dword; ECX = address of buffer
itostr:
	push eax
	push ecx
	cmp eax, 0		; if (eax < 0) {
	jge positive_num
	mov byte [ecx], '-'	;	[ecx++] = '-';
	inc ecx
	neg eax			;	eax = -eax; }
positive_num:
	call utostr
	pop ecx
	pop eax
	ret


global putdword

; parameters: EAX = unsigned dword
putdword:
	push eax
	push ecx
	sub esp, 12		; buffer for number
	mov ecx, esp
	call utostr
	mov eax, esp
	call putstr
	add esp, 12
	pop ecx
	pop eax
	ret


global putnum

; parameters: EAX = signed dword
putnum:
	push eax
	push ecx
	sub esp, 12		; buffer for number
	mov ecx, esp
	call itostr
	mov eax, esp
	call putstr
	add esp, 12
	pop ecx
	pop eax
	ret
