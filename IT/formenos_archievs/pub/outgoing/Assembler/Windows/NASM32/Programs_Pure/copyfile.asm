section .data use32 class=DATA

source	db "source.zip",0
target	db "target.zip",0

section .text use32 class=CODE

extern CopyFileA
extern ExitProcess

global _start
_start:
	; bool __stdcall CopyFileA(const char *lpExistingFileName, const char *lpNewFileName, bool bFailIfExists);
	push 1			; bFailIfExists
	push target		; lpNewFileName
	push source		; lpExistingFileName
	call CopyFileA

	; void __stdcall ExitProcess(unsigned uExitCode);
	push 0
	call ExitProcess
;	mov eax, 0
;	ret
