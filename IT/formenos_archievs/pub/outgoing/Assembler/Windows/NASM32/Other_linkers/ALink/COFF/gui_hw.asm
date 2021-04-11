section .data

Message	db "Hello, World!",0

section .text

extern MessageBoxA
extern ExitProcess

global _start
_start:
	; int __stdcall MessageBoxA(HWND hWnd, const char *lpText, const char *lpCaption, unsigned uType);
	push 0			; uType = MB_OK
	push Message		; lpCaption = &Message
	push Message		; lpText = &Message
	push 0			; hWnd = NULL
	call MessageBoxA

	; void __stdcall ExitProcess(unsigned uExitCode);
	push 0
	call ExitProcess
;	mov eax, 0
;	ret
