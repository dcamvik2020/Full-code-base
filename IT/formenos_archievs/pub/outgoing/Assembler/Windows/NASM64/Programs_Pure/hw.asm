section .data

Message	db "Hell, Word!",0xD,0xA
Length	equ $ - Message
stdout	dq 0
nWritten dq 0

section .text

extern GetStdHandle
extern WriteFile
extern ExitProcess

global _start
_start:
	; HANDLE GetStdHandle(unsigned long nStdHandle);
	mov rcx, -11		; STD_OUTPUT_HANDLE = (unsigned long)(-11)
	sub rsp, 40		; "shadow space" + alignment
	call GetStdHandle
	add rsp, 40
	mov [stdout], rax	; save result to stdout variable

	; bool WriteFile(HANDLE hFile, const void *lpBuffer, unsigned long nNumberOfBytesToWrite,
	;                          unsigned long *lpNumberOfBytesWritten, OVERLAPPED *lpOverlapped);
	push 0			; lpOverlapped = NULL
	mov r9, nWritten	; lpNumberOfBytesWritten = &nWritten
	mov r8, Length		; nNumberOfBytesToWrite
	mov rdx, Message	; lpBuffer = &Message
	mov rcx, [stdout]	; hFile = stdout
	sub rsp, 32		; "shadow space"
	call WriteFile
	add rsp, 40

	; void ExitProcess(unsigned uExitCode);
	mov rcx, 0
	sub rsp, 40		; "shadow space" + alignment
	call ExitProcess
;	add rsp, 40
;	mov rax, 0
;	ret
