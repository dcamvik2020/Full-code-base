.386
.model flat

extrn MessageBoxA: near
extrn ExitProcess: near

.data
Message	db "Hello, World!",0

.code

Entry:
	; int __stdcall MessageBoxA(HWND hWnd, const char *lpText, const char *lpCaption, unsigned uType);
	push 0			; uType = MB_OK
	push offset Message	; lpCaption = &Message
	push offset Message	; lpText = &Message
	push 0			; hWnd = NULL
	call MessageBoxA

	; void __stdcall ExitProcess(unsigned uExitCode);
	push 0
	call ExitProcess
;	mov eax, 0
;	ret
end Entry
