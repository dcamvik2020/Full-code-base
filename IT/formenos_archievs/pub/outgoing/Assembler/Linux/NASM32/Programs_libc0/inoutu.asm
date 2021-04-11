section .bss
buf resb 10
max equ $ - buf
len resd 1

section .text
extern read
extern write
extern _exit

global _start
_start:
	; len = read(0, buf, max);
	push max
	push buf
	push 0
	call read
	add esp, 12
	mov [len], eax

	; write(1, buf, len);
	push dword [len]
	push buf
	push 1
	call write
	add esp, 12

	; _exit(0);
	push 0
	call _exit
;	add esp, 4
