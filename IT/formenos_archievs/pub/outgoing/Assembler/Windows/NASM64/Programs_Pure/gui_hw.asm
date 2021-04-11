section .data

Message	db "Hello, World!",0

section .text

extern MessageBoxA
extern ExitProcess

global _start
_start:
	; int MessageBoxA(HWND hWnd, const char *lpText, const char *lpCaption, unsigned uType);
	mov r9, 0		; uType = MB_OK
	mov r8, Message		; lpCaption = &Message
	mov rdx, Message	; lpText = &Message
	mov rcx, 0		; hWnd = NULL
	sub rsp, 40		; "shadow space"
	call MessageBoxA
	add rsp, 40

	; void ExitProcess(unsigned uExitCode);
	mov rcx, 0
	sub rsp, 40		; "shadow space"
	call ExitProcess
;	add rsp, 40
;	mov rax, 0
;	ret
