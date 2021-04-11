section .data

source	db "source.zip",0
target	db "target.zip",0

section .text

extern CopyFileA
extern ExitProcess

global _start
_start:
	; bool __stdcall CopyFileA(const char *lpExistingFileName, const char *lpNewFileName, bool bFailIfExists);
	mov r8, 1		; bFailIfExists
	mov rdx, target		; lpNewFileName
	mov rcx, source		; lpExistingFileName
	sub rsp, 40		; "shadow space" + alignment
	call CopyFileA
	add rsp, 40

	; void ExitProcess(unsigned uExitCode);
	mov rcx, 0
	sub rsp, 40		; "shadow space" + alignment
	call ExitProcess
;	add rsp, 40
;	mov rax, 0
;	ret
