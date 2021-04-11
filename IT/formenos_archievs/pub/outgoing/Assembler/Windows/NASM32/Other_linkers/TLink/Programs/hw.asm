section data public use32 class=DATA

Message	db "Hell, Word!",0xD,0xA
Length	equ $ - Message
stdout	dd 0
nWritten dd 0

section code public use32 class=CODE

extern GetStdHandle
extern WriteFile
extern ExitProcess

..start:
	; HANDLE __stdcall GetStdHandle(unsigned long nStdHandle);
	push -11		; STD_OUTPUT_HANDLE = (unsigned long)(-11)
	call GetStdHandle
	mov [stdout], eax	; save result to stdout variable

	; bool __stdcall WriteFile(HANDLE hFile, const void *lpBuffer, unsigned long nNumberOfBytesToWrite,
	;                          unsigned long *lpNumberOfBytesWritten, OVERLAPPED *lpOverlapped);
	push 0			; lpOverlapped = NULL
	push nWritten		; lpNumberOfBytesWritten = &nWritten
	push Length		; nNumberOfBytesToWrite
	push Message		; lpBuffer = &Message
	push dword [stdout]	; hFile = stdout
	call WriteFile

	; void __stdcall ExitProcess(unsigned uExitCode);
	push 0
	call ExitProcess
;	mov eax, 0
;	ret
