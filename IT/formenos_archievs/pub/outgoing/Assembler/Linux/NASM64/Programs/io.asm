; Standard Input/Output library, version 6.4E1.2015.04.06
; Written by Andrey Tretyakov, 28.03.2013, 12.03.2015, 24.03.2015, 30.03.2015

section .text


; ==================== INPUT (buffered) ====================


extern getchr

; doesn't save AL
%macro getc 1		; getc c	; size c = 1 byte
	call getchr
	mov %1, al
%endmacro


extern getstr

; doesn't save RAX, return 0 if EOF
%macro gets 2		; gets s, n	; size s = 8 bytes (address of buffer), size n = 8 bytes (max size of buffer)
	push rcx
	mov rax, %1
	mov rcx, %2
	call getstr
	pop rcx
%endmacro


extern getnum

; doesn't save RAX
%macro getn 1		; getn n	; size n = 8 bytes
	call getnum
	mov %1, rax
%endmacro


; ==================== OUTPUT (non-buffered) ====================


extern putstr

%macro puts 1		; puts s	; size s = 8 bytes (address of buffer)
	push rax
	mov rax, %1
	call putstr
	pop rax
%endmacro


extern putchr

%macro putc 1		; putc c	; size c = 1 byte
	push rax
	mov al, %1
	call putchr
	pop rax
%endmacro


extern newline

%define newln	call newline

; %macro newln 0
;	putc 13		; CR = '\r'
;	putc 10		; LF = '\n'
; %endmacro


extern putqword

%macro putu 1		; putu u	; size u = 8 bytes
	push rax
	mov rax, %1
	call putqword
	pop rax
%endmacro


extern putnum

%macro putn 1		; putn n	; size n = 8 bytes
	push rax
	mov rax, %1
	call putnum
	pop rax
%endmacro


%macro exit 1		; exit c	; size c = 8 bytes
	; void _exit(int status);
	mov rax, 60
	mov rdi, %1
	syscall
%endmacro
