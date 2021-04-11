section .data

Message	db "Hell, Word!",0xA
Length	equ $ - Message

section .text
extern write

global main
main:
	; write(1, Message, Length);
	push Length
	push Message
	push 1
	call write
	add esp, 12

	; return 0;
	mov eax, 0
	ret
