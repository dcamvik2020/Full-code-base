; Standard Input/Output library, version 3.2E1.2015.04.06
; Written by Andrey Tretyakov, 28.03.2013, 12.03.2015, 24.03.2015

; includelib import32.lib
.386
.model flat

.data

stdin	dd 0
stdout	dd 0

; for input
index	dd 0
MAXBUF	equ 15
buffer	db MAXBUF + 1 dup(0)


.code


; ==================== INPUT (buffered) ====================


extrn GetStdHandle: near
extrn ReadFile: near

; return: EAX = the number of read bytes
fillbuf proc
	push ecx
	push edx
	sub esp, 4		; dword [esp] is numBytes

	cmp stdin, 0		; if (stdin == NULL)
	jne short has_input_handle

	; HANDLE __stdcall GetStdHandle(unsigned long nStdHandle);
	push -10		; STD_INPUT_HANDLE = (unsigned long)(-10)
	call GetStdHandle
	mov stdin, eax		; save result to stdin variable

has_input_handle:
	mov edx, esp
	; bool __stdcall ReadFile(HANDLE hFile, void *lpBuffer, unsigned long nNumberOfBytesToRead,
	;                         unsigned long *lpNumberOfBytesRead, OVERLAPPED *lpOverlapped);
	push 0			; lpOverlapped = NULL
	push edx		; lpNumberOfBytesRead = &numBytes
	push MAXBUF		; nNumberOfBytesToRead = MAXBUF
	push offset buffer	; lpBuffer = &buffer
	push stdin		; hFile = stdin
	call ReadFile

	mov index, 0
	mov eax, [esp]
	mov buffer[eax], 0	; buffer[numBytes] = '\0';

	add esp, 4
	pop edx
	pop ecx
	ret
fillbuf endp


public getchr

; return: AL = character
getchr proc
	push eax
	mov eax, index
	cmp buffer[eax], 0	; if (buffer[index] == '\0')
	jne short get_char
	call fillbuf
	cmp eax, 0		;	if (fillbuf() == 0)
	jne short get_char
	mov [esp], al
	pop eax
	ret			;		return '\0';
get_char:
	mov eax, index
	mov al, buffer[eax]	; return buffer[index++];
	inc index
	mov [esp], al		; hack to save high bytes of eax
	pop eax
	ret
getchr endp


public getstr

; parameters: EAX = address of buffer; ECX = size of buffer
; return: EAX = old value on success, EAX = 0 on error or EOF
getstr proc
	pushad
	mov edx, eax
	mov al, 0		; al = '\0';
	mov edi, 0		; edi = 0
	cmp ecx, 0
	je short skip_parsing
	dec ecx

read_cycle:			; for (...)
	cmp edi, ecx		; edi < ecx - 1 &&
	jae short exit_read_cycle
	call getchr		; al = getchr()
	cmp al, 10		; al != '\n' &&
	je short exit_read_cycle
	cmp al, 0		; al != '\0'
	je short exit_read_cycle
	mov [edx+edi], al	;	edx[edi] = al;
	inc edi			; edi++
	jmp short read_cycle
exit_read_cycle:

	inc ecx
	cmp edi, 0		; if (edi > 0 &&
	jbe short skip_parsing
	cmp byte ptr [edx+edi-1], 13	; edx[edi-1] == '\r')
	jne short skip_parsing
	dec edi			;	edi--;
skip_parsing:

	mov byte ptr [edx+edi], 0 ; edx[edi] = '\0';
	cmp edi, 0		; if (edi == 0 &&
	jne short exit_getstr
	cmp al, 0		;     al == '\0')
	jne short exit_getstr
	popad
	mov eax, 0		;	return NULL;
	ret
exit_getstr:
	popad			; return eax;
	ret
getstr endp


public getnum

; return: EAX = signed dword
getnum proc
whitespace_cycle:		; while (...)
	call getchr		; al = getchr();
	cmp al, ' '		; al == ' ' ||
	je short whitespace_cycle
	cmp al, 9		; al == '\t' ||
	je short whitespace_cycle
	cmp al, 13		; al == '\r' ||
	je short whitespace_cycle
	cmp al, 10		; al == '\n'
	je short whitespace_cycle

	cmp al, 0		; if (al == '\0')
	jne short check_sign
	mov eax, 0		;	return 0;
	ret

check_sign:
	push ecx
	push edx
	mov ch, 1		; ch = 1; //sign
	cmp al, '-'		; if (al == '-')
	jne short positive_str
	mov ch, -1		;	ch = -1;
	jmp short exit_sign
positive_str:			; else
	dec index		;	index--;
exit_sign:

	mov eax, 0		; eax = 0;

next_characher:			; while (...)

	push eax
	call getchr		; cl = getchr()
	mov cl, al
	pop eax

	sub cl, '0'
	cmp cl, 9		; cl - '0' >= 0 && cl - '0' <= 9 &&
	ja short exit_parse_cycle
	cmp eax, 429496729	; if won'n be overflow
	ja short exit_parse_cycle
	mov edx, 10
	mul edx			; {	eax *= 10;				//eax * edx = edx:eax
	movzx edx, cl
	add eax, edx		;	eax += cl - '0';
	jmp short next_characher ; }
exit_parse_cycle:

	dec index		; index--;
	cmp ch, -1		; if (ch == -1)
	jne short exit_getnum
	neg eax			;	eax = -eax;
exit_getnum:
	pop edx
	pop ecx
	ret			; return eax;
getnum endp


; ==================== OUTPUT (non-buffered) ====================


extrn WriteFile: near

; parameters: EAX = address of string, ECX = length of the string
flushbuf proc
	push eax
	push ecx
	push edx
	sub esp, 4		; dword [esp] is numBytes

	cmp stdout, 0		; if (stdout == NULL)
	jne short has_output_handle

	; HANDLE __stdcall GetStdHandle(unsigned long nStdHandle);
	push -11		; STD_OUTPUT_HANDLE = (unsigned long)(-11)
	call GetStdHandle
	mov stdout, eax		; save result to stdout variable
	mov eax, [esp+12]
	mov ecx, [esp+8]

has_output_handle:
	mov edx, esp
	; bool __stdcall WriteFile(HANDLE hFile, const void *lpBuffer, unsigned long nNumberOfBytesToWrite,
	;                          unsigned long *lpNumberOfBytesWritten, OVERLAPPED *lpOverlapped);
	push 0			; lpOverlapped = NULL
	push edx		; lpNumberOfBytesWritten = &numBytes
	push ecx		; nNumberOfBytesToWrite = ecx
	push eax		; lpBuffer = eax
	push stdout		; hFile = stdout
	call WriteFile

	add esp, 4
	pop edx
	pop ecx
	pop eax
	ret
flushbuf endp


; public strlen

; parameters: EAX = address of string
; return: EAX = length of the string
strlen proc
	push ecx
	push edi
	mov edi, eax
	mov ecx, 0FFFFFFFFh
	cld
	mov al, 0

repne	scasb			; for (ecx; ecx > 0 && [edi++] != al; ecx--);

	mov eax, 0FFFFFFFEh
	sub eax, ecx
	pop edi
	pop ecx
	ret
strlen endp


public putstr

; parameters: EAX = address of string
putstr proc
	push ecx
	push eax
	call strlen		; ecx = strlen(eax);
	mov ecx, eax
	pop eax
	call flushbuf
	pop ecx
	ret
putstr endp


public putchr

; parameters: AL = character
putchr proc
	push ecx
	push eax
	mov ecx, 1
	mov eax, esp
	call flushbuf
	pop eax
	pop ecx
	ret
putchr endp


public newline

newline proc
	push ecx
	push eax
	push 0A0Dh		; reverse \r\n\0\0
	mov ecx, 2
	mov eax, esp
	call flushbuf
	pop eax
	pop eax
	pop ecx
	ret
newline endp


; public utostr

; parameters: EAX = unsigned dword; ECX = address of buffer
utostr proc
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
	ja short next_digit	; } while (eax != 0);

	mov byte ptr [edi], 0
	dec edi
reverse:			; do {
	mov dl, [ebx]
	xchg dl, [edi]		;	swap([ebx++], [edi--]);
	mov [ebx], dl
	inc ebx
	dec edi
	cmp ebx, edi
	jl short reverse	; } while (ebx < edx);

	popad
	ret
utostr endp


; public itostr

; parameters: EAX = signed dword; ECX = address of buffer
itostr proc
	push eax
	push ecx
	cmp eax, 0		; if (eax < 0) {
	jge short positive_num
	mov byte ptr [ecx], '-'	;	[ecx++] = '-';
	inc ecx
	neg eax			;	eax = -eax; }
positive_num:
	call utostr
	pop ecx
	pop eax
	ret
itostr endp


public putdword

; parameters: EAX = unsigned dword
putdword proc
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
putdword endp


public putnum

; parameters: EAX = signed dword
putnum proc
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
putnum endp


end
