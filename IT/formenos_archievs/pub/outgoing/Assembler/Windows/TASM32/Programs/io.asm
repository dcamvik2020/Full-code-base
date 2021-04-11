; Standard Input/Output library, version 3.2E1.2015.04.06
; Written by Andrey Tretyakov, 28.03.2013, 12.03.2015, 24.03.2015

; includelib ioproc.obj


; ==================== INPUT (buffered) ====================


extrn getchr: near

; doesn't save AL
getc macro c		; size c = 1 byte
	call getchr
	mov c, al
endm


extrn getstr: near

; doesn't save EAX, return 0 if EOF
gets macro n, s1, s2	; size n = 4 bytes (max size of buffer), size s = 4 bytes (address of buffer)
	push ecx
	mov eax, s1 s2
	mov ecx, n
	call getstr
	pop ecx
endm


extrn getnum: near

; doesn't save EAX
getn macro n		; size n = 4 bytes
	call getnum
	mov n, eax
endm


; ==================== OUTPUT (non-buffered) ====================


extrn putstr: near

puts macro s1, s2	; size s = 4 bytes (address of buffer)
	push eax
	mov eax, s1 s2
	call putstr
	pop eax
endm


extrn putchr: near

putc macro c		; size c = 1 byte
	push eax
	mov al, c
	call putchr
	pop eax
endm


extrn newline: near

newln macro
	call newline
;	putc 13		; CR = '\r'
;	putc 10		; LF = '\n'
endm


extrn putdword: near

putu macro u		; size u = 4 bytes
	push eax
	mov eax, u
	call putdword
	pop eax
endm


extrn putnum: near

putn macro n		; size n = 4 bytes
	push eax
	mov eax, n
	call putnum
	pop eax
endm


extrn ExitProcess: near

exit macro c		; size c = 4 bytes
	; void __stdcall ExitProcess(unsigned uExitCode);
	push c
	call ExitProcess
endm
