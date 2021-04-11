; Standard Input/Output library, version 3.2E1.2015.04.06
; Written by Andrey Tretyakov, 28.03.2013, 12.03.2015, 24.03.2015

section .text


; ==================== INPUT (buffered) ====================


extern getchr

; doesn't save AL
%macro getc 1		; getc c	; size c = 1 byte
	call getchr
	mov %1, al
%endmacro


extern getstr

; doesn't save EAX, return 0 if EOF
%macro gets 2		; gets s, n	; size s = 4 bytes (address of buffer), size n = 4 bytes (max size of buffer)
	push ecx
	mov eax, %1
	mov ecx, %2
	call getstr
	pop ecx
%endmacro


extern getnum

; doesn't save EAX
%macro getn 1		; getn n	; size n = 4 bytes
	call getnum
	mov %1, eax
%endmacro


; ==================== OUTPUT (non-buffered) ====================


extern putstr

%macro puts 1		; puts s	; size s = 4 bytes (address of buffer)
	push eax
	mov eax, %1
	call putstr
	pop eax
%endmacro


extern putchr

%macro putc 1		; putc c	; size c = 1 byte
	push eax
	mov al, %1
	call putchr
	pop eax
%endmacro


extern newline

%define newln	call newline

; %macro newln 0
;	putc 13		; CR = '\r'
;	putc 10		; LF = '\n'
; %endmacro


extern putdword

%macro putu 1		; putu u	; size u = 4 bytes
	push eax
	mov eax, %1
	call putdword
	pop eax
%endmacro


extern putnum

%macro putn 1		; putn n	; size n = 4 bytes
	push eax
	mov eax, %1
	call putnum
	pop eax
%endmacro


%macro exit 1		; exit c	; size c = 4 bytes
	; void _exit(int status);
	mov eax, 1
	mov ebx, %1
	int 0x80
%endmacro
