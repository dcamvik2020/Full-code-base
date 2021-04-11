section .bss
buf resb 10

section .text
extern gets
extern puts
extern exit

global _start
_start:
	; gets(buf)
	push buf
	call gets
;	add esp, 4

	; puts(buf);
;	push buf
	call puts
	add esp, 4

	; exit(0);
	push 0
	call exit
;	add esp, 4
