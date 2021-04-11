; Standard Input/Output library, version 6.4E1.2015.04.06
; Written by Andrey Tretyakov, 28.03.2013, 12.03.2015, 24.03.2015, 30.03.2015

section .bss

; for input
index	resq 1
MAXBUF	equ 15
buffer	resb MAXBUF + 1


section .text


; ==================== INPUT (buffered) ====================


; return: RAX = the number of read bytes
fillbuf:
	push rcx
	push rdx
	push rsi
	push rdi
	push r11

	; ssize_t read(int fd, void *buf, size_t count);
	mov rax, 0		; syscall = read
	mov rdi, 0		; fd = stdin
	mov rsi, buffer		; buf = buffer
	mov rdx, MAXBUF		; count = MAXBUF
	syscall

	mov qword [index], 0
	mov byte [buffer+rax], 0 ; buffer[len] = '\0';

	pop r11
	pop rdi
	pop rsi
	pop rdx
	pop rcx
	ret


global getchr

; return: AL = character
getchr:
	push rax
	mov rax, [index]
	cmp byte [buffer+rax], 0 ; if (buffer[index] == '\0')
	jne get_char
	call fillbuf
	cmp rax, 0		;	if (fillbuf() == 0)
	jne get_char
	mov [rsp], al
	pop rax
	ret			;		return '\0';
get_char:
	mov rax, [index]
	mov al, [buffer+rax]	; return buffer[index++];
	inc qword [index]
	mov [rsp], al		; hack to save high bytes of eax
	pop rax
	ret


global getstr

; parameters: RAX = address of buffer; RCX = size of buffer
; return: RAX = old value on success, RAX = 0 on error or EOF
getstr:
	push rdi
	push rdx
	push rcx
	push rax

	mov rdx, rax
	mov al, 0		; al = '\0';
	mov rdi, 0		; rdi = 0
	cmp rcx, 0
	je skip_parsing
	dec rcx

read_cycle:			; for (...)
	cmp rdi, rcx		; rdi < rcx - 1 &&
	jae exit_read_cycle
	call getchr		; al = getchr()
	cmp al, 10		; al != '\n' &&
	je exit_read_cycle
	cmp al, 0		; al != '\0'
	je exit_read_cycle
	mov [rdx+rdi], al	;	rdx[rdi] = al;
	inc rdi			; rdi++
	jmp read_cycle
exit_read_cycle:

	inc rcx
	cmp rdi, 0		; if (rdi > 0 &&
	jbe skip_parsing
	cmp byte [rdx+rdi-1], 13	; rdx[rdi-1] == '\r')
	jne skip_parsing
	dec rdi			;	rdi--;
skip_parsing:

	mov byte [rdx+rdi], 0	; rdx[rdi] = '\0';
	cmp rdi, 0		; if (rdi == 0 &&
	jne exit_getstr
	cmp al, 0		;     al == '\0')
	jne exit_getstr
	pop rax
	mov rax, 0		;	return NULL;
	jmp exit_getstr2

exit_getstr:
	pop rax			; return rax;
exit_getstr2:
	pop rcx
	pop rdx
	pop rdi
	ret


global getnum

; return: RAX = signed dword
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
	mov rax, 0		;	return 0;
	ret

check_sign:
	push rcx
	push rdx
	mov ch, 1		; ch = 1; //sign
	cmp al, '-'		; if (al == '-')
	jne positive_str
	mov ch, -1		;	ch = -1;
	jmp exit_sign
positive_str:			; else
	dec qword [index]	;	index--;
exit_sign:

	mov rax, 0		; rax = 0;

next_characher:			; while (...)

	push rax
	call getchr		; cl = getchr()
	mov cl, al
	pop rax

	sub cl, '0'
	cmp cl, 9		; cl - '0' >= 0 && cl - '0' <= 9 &&
	ja exit_parse_cycle
;	cmp rax, 0xCCCCCCCCCCCCCCC ; if won'n be overflow
;	ja exit_parse_cycle
	mov rdx, 10
	mul rdx			; {	rax *= 10;				//rax * rdx = rdx:rax
	movzx rdx, cl
	add rax, rdx		;	rax += cl - '0';
	jmp next_characher	; }
exit_parse_cycle:

	dec qword [index]	; index--;
	cmp ch, -1		; if (ch == -1)
	jne exit_getnum
	neg rax			;	rax = -rax;
exit_getnum:
	pop rdx
	pop rcx
	ret			; return rax;


; ==================== OUTPUT (non-buffered) ====================


; parameters: RAX = address of string, RCX = length of the string
flushbuf:
	push rax
	push rcx
	push rdx
	push rsi
	push rdi
	push r11

	; ssize_t write(int fd, const void *buf, size_t count);
	mov rdx, rcx		; count = rcx
	mov rsi, rax		; buf = rax
	mov rdi, 1		; fd = stdout
	mov rax, 1		; syscall = write
	syscall

	pop r11
	pop rdi
	pop rsi
	pop rdx
	pop rcx
	pop rax
	ret


; global strlen

; parameters: RAX = address of string
; return: RAX = length of the string
strlen:
	push rcx
	push rdi
	mov rdi, rax
	mov rcx, 0xFFFFFFFFFFFFFFFF
	cld
	mov al, 0

repne	scasb			; for (rcx; rcx > 0 && [rdi++] != al; rcx--);

	mov rax, 0xFFFFFFFFFFFFFFFE
	sub rax, rcx
	pop rdi
	pop rcx
	ret


global putstr

; parameters: RAX = address of string
putstr:
	push rcx
	push rax
	call strlen		; rcx = strlen(rax);
	mov rcx, rax
	pop rax
	call flushbuf
	pop rcx
	ret


global putchr

; parameters: AL = character
putchr:
	push rcx
	push rax
	mov rcx, 1
	mov rax, rsp
	call flushbuf
	pop rax
	pop rcx
	ret


global newline

newline:
	push rcx
	push rax
	push 0x0A		; reverse \n\0\0\0\0\0\0\0
	mov rcx, 1
	mov rax, rsp
	call flushbuf
	pop rax
	pop rax
	pop rcx
	ret


; global utostr

; parameters: RAX = unsigned qword; RCX = address of buffer
utostr:
	push rax
	push rbx
	push rcx
	push rdx
	push rdi

	mov rbx, rcx
	mov rdi, rcx
	mov rcx, 10

next_digit:			; do {
	mov rdx, 0
	div rcx			;	rdx = rax % 10; rax /= 10;		// rdx:rax / rcx = rax + rdx / rcx
	add dl, '0'
	mov [rdi], dl		;	[rdi++] = dl + '0';
	inc rdi
	cmp rax, 0
	ja next_digit		; } while (rax != 0);

	mov byte [rdi], 0
	dec rdi
reverse:			; do {
	mov dl, [rbx]
	xchg dl, [rdi]		;	swap([rbx++], [rdi--]);
	mov [rbx], dl
	inc rbx
	dec rdi
	cmp rbx, rdi
	jl reverse		; } while (rbx < rdx);

	pop rdi
	pop rdx
	pop rcx
	pop rbx
	pop rax
	ret


; global itostr

; parameters: RAX = signed qword; RCX = address of buffer
itostr:
	push rax
	push rcx
	cmp rax, 0		; if (rax < 0) {
	jge positive_num
	mov byte [rcx], '-'	;	[rcx++] = '-';
	inc rcx
	neg rax			;	rax = -rax; }
positive_num:
	call utostr
	pop rcx
	pop rax
	ret


global putqword

; parameters: RAX = unsigned qword
putqword:
	push rax
	push rcx
	sub rsp, 24		; buffer for number (21 is sufficient)
	mov rcx, rsp
	call utostr
	mov rax, rsp
	call putstr
	add rsp, 24
	pop rcx
	pop rax
	ret


global putnum

; parameters: RAX = signed qword
putnum:
	push rax
	push rcx
	sub rsp, 24		; buffer for number (21 is sufficient)
	mov rcx, rsp
	call itostr
	mov rax, rsp
	call putstr
	add rsp, 24
	pop rcx
	pop rax
	ret
