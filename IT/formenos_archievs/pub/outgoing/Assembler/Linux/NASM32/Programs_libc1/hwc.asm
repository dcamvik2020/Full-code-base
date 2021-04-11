section .data

Message	db "Hell, Word!",0

section .text

extern puts

global main
main:
	; puts(Message);
	push Message
	call puts
	add esp, 4

	; return 0;
	mov eax, 0
	ret
