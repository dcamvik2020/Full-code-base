.386
.model flat

extrn GetStdHandle: near
extrn ReadFile: near
extrn WriteFile: near
extrn ExitProcess: near

.data
buf	db 10 dup(0)
max	equ $ - buf
len	dd 0
stdin	dd 0
stdout	dd 0

.code

Entry:
	; HANDLE __stdcall GetStdHandle(unsigned long nStdHandle);
	push -10		; STD_INPUT_HANDLE = (unsigned long)(-10)
	call GetStdHandle
	mov stdin, eax		; save result to stdin variable

	push -11		; STD_OUTPUT_HANDLE = (unsigned long)(-11)
	call GetStdHandle
	mov stdout, eax		; save result to stdout variable

	; bool __stdcall ReadFile(HANDLE hFile, void *lpBuffer, unsigned long nNumberOfBytesToRead,
	;                         unsigned long *lpNumberOfBytesRead, OVERLAPPED *lpOverlapped);
	push 0			; lpOverlapped = NULL
	push offset len		; lpNumberOfBytesRead = &len
	push max		; nNumberOfBytesToRead = max
	push offset buf		; lpBuffer = &buf
	push stdin		; hFile = stdin
	call ReadFile

	; bool __stdcall WriteFile(HANDLE hFile, const void *lpBuffer, unsigned long nNumberOfBytesToWrite,
	;                          unsigned long *lpNumberOfBytesWritten, OVERLAPPED *lpOverlapped);
	push 0			; lpOverlapped = NULL
	push offset len		; lpNumberOfBytesWritten = &len
	push len		; nNumberOfBytesToWrite = len
	push offset buf		; lpBuffer = &buf
	push stdout		; hFile = stdout
	call WriteFile

	; void __stdcall ExitProcess(unsigned uExitCode);
	push 0
	call ExitProcess
;	mov eax, 0
;	ret
end Entry
