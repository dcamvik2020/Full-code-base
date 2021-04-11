section .data use32 class=DATA

Message	db "Hell, Word!",0

section .text use32 class=CODE

extern puts
extern exit

global _start
_start:
	; puts(Message);
	push Message
	call puts
	add esp, 4

	; exit(0);
	push 0
	call exit
;	add esp, 4
