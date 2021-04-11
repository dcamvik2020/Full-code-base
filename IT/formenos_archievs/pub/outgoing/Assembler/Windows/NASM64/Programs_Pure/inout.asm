section .bss

buf	resb 10
max	equ $ - buf
len	resq 1
stdin	resq 1
stdout	resq 1

section .text

extern GetStdHandle
extern ReadFile
extern WriteFile
extern ExitProcess

global _start
_start:
	; HANDLE GetStdHandle(unsigned long nStdHandle);
	mov rcx, -10		; STD_INPUT_HANDLE = (unsigned long)(-10)
	sub rsp, 40		; "shadow space" + alignment
	call GetStdHandle
	add rsp, 40
	mov [stdin], rax	; save result to stdin variable

	mov rcx, -11		; STD_OUTPUT_HANDLE = (unsigned long)(-11)
	sub rsp, 40		; "shadow space" + alignment
	call GetStdHandle
	add rsp, 40
	mov [stdout], rax	; save result to stdout variable

	; bool ReadFile(HANDLE hFile, void *lpBuffer, unsigned long nNumberOfBytesToRead,
	;                         unsigned long *lpNumberOfBytesRead, OVERLAPPED *lpOverlapped);
	push 0			; lpOverlapped = NULL
	mov r9, len		; lpNumberOfBytesRead = &len
	mov r8, max		; nNumberOfBytesToRead = max
	mov rdx, buf		; lpBuffer = &buf
	mov rcx, [stdin]	; hFile = stdin
	sub rsp, 32		; "shadow space"
	call ReadFile
	add rsp, 40

	; bool WriteFile(HANDLE hFile, const void *lpBuffer, unsigned long nNumberOfBytesToWrite,
	;                          unsigned long *lpNumberOfBytesWritten, OVERLAPPED *lpOverlapped);
	push 0			; lpOverlapped = NULL
	mov r9, len		; lpNumberOfBytesWritten = &len
	mov r8, [len]		; nNumberOfBytesToWrite = len
	mov rdx, buf		; lpBuffer = &buf
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
