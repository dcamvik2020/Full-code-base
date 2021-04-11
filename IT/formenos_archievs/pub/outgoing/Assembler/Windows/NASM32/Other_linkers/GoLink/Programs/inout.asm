section .bss

buf	resb 10
max	equ $ - buf
len	resd 1
stdin	resd 1
stdout	resd 1

section .text

extern GetStdHandle
extern ReadFile
extern WriteFile
extern ExitProcess

start:
	; HANDLE __stdcall GetStdHandle(unsigned long nStdHandle);
	push -10		; STD_INPUT_HANDLE = (unsigned long)(-10)
	call GetStdHandle
	mov [stdin], eax	; save result to stdin variable

	push -11		; STD_OUTPUT_HANDLE = (unsigned long)(-11)
	call GetStdHandle
	mov [stdout], eax	; save result to stdout variable

	; bool __stdcall ReadFile(HANDLE hFile, void *lpBuffer, unsigned long nNumberOfBytesToRead,
	;                         unsigned long *lpNumberOfBytesRead, OVERLAPPED *lpOverlapped);
	push 0			; lpOverlapped = NULL
	push len		; lpNumberOfBytesRead = &len
	push max		; nNumberOfBytesToRead = max
	push buf		; lpBuffer = &buf
	push dword [stdin]	; hFile = stdin
	call ReadFile

	; bool __stdcall WriteFile(HANDLE hFile, const void *lpBuffer, unsigned long nNumberOfBytesToWrite,
	;                          unsigned long *lpNumberOfBytesWritten, OVERLAPPED *lpOverlapped);
	push 0			; lpOverlapped = NULL
	push len		; lpNumberOfBytesWritten = &len
	push dword [len]	; nNumberOfBytesToWrite = len
	push buf		; lpBuffer = &buf
	push dword [stdout]	; hFile = stdout
	call WriteFile

	; void __stdcall ExitProcess(unsigned uExitCode);
	push 0
	call ExitProcess
;	mov eax, 0
;	ret
