.386
model flat

assume cs: flat, ds: flat, ss: flat, es: flat

extrn GetStdHandle: near
extrn WriteFile: near
extrn ExitProcess: near

_DATA segment
Message	db "Hell, Word!",0Dh,0Ah
Len	equ $ - Message
stdout	dd 0
nWritten dd 0
_DATA ends

_TEXT segment

Entry:
	; HANDLE WINAPI GetStdHandle(DWORD nStdHandle);
	push -11		; STD_OUTPUT_HANDLE = (DWORD)(-11)
	call GetStdHandle
	mov stdout, eax		; save result to stdout variable

	; BOOL WINAPI WriteFile(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite,
	;                       LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped);
	push 0			; lpOverlapped = NULL
	push offset nWritten	; lpNumberOfBytesWritten = &nWritten
	push Len		; nNumberOfBytesToWrite
	push offset Message	; lpBuffer = &Message
	push stdout		; hFile = stdout
	call WriteFile

	; VOID WINAPI ExitProcess(UINT uExitCode);
	push 0
	call ExitProcess
;	mov eax, 0
;	ret

_TEXT ends

end Entry
