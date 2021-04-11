.386
.model flat

extrn GetStdHandle: near
extrn WriteFile: near
extrn ExitProcess: near

.data
Message db "Hell, Word!",0Dh,0Ah
Len	equ $ - Message
stdout	dd 0
nWritten dd 0

.code

Entry:
	; HANDLE __stdcall GetStdHandle(unsigned long nStdHandle);
	push -11		; STD_OUTPUT_HANDLE = (unsigned long)(-11)
	call GetStdHandle
	mov stdout, eax		; save result to stdout variable

	; bool __stdcall WriteFile(HANDLE hFile, const void *lpBuffer, unsigned long nNumberOfBytesToWrite,
	;                          unsigned long *lpNumberOfBytesWritten, OVERLAPPED *lpOverlapped);
	push 0			; lpOverlapped = NULL
	push offset nWritten	; lpNumberOfBytesWritten = &nWritten
	push Len		; nNumberOfBytesToWrite
	push offset Message	; lpBuffer = &Message
	push stdout		; hFile = stdout
	call WriteFile

	; void __stdcall ExitProcess(unsigned uExitCode);
	push 0
	call ExitProcess
;	mov eax, 0
;	ret
end Entry
