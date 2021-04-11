.386
model flat

assume cs: flat, ds: flat, ss: flat, es: flat

extrn MessageBoxA: near
extrn ExitProcess: near

_DATA segment
Message	db "Hell, Word!",0
_DATA ends

_TEXT segment

Entry:
	; int WINAPI MessageBox(HWND hWnd, LPCTSTR lpText, LPCTSTR lpCaption, UINT uType);
	push 0			; uType = MB_OK
	push offset Message	; lpCaption = &Message
	push offset Message	; lpText = &Message
	push 0			; hWnd = NULL
	call MessageBoxA

	; VOID WINAPI ExitProcess(UINT uExitCode);
	push 0
	call ExitProcess
;	mov eax, 0
;	ret

_TEXT ends

end Entry
