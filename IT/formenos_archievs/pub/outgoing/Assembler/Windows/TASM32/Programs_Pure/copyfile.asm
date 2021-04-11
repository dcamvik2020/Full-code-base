.386
.model flat

extrn CopyFileA: near
extrn ExitProcess: near

.data

source	db "source.zip",0
target	db "target.zip",0

.code

Entry:
	; bool __stdcall CopyFileA(const char *lpExistingFileName, const char *lpNewFileName, bool bFailIfExists);
	push 1			; bFailIfExists
	push offset target	; lpNewFileName
	push offset source	; lpExistingFileName
	call CopyFileA

	; void __stdcall ExitProcess(unsigned uExitCode);
	push 0
	call ExitProcess
;	mov eax, 0
;	ret
end Entry
