section .bss
buf resb 10

section .text
extern gets
extern puts

global main
main:
	; gets(buf)
	push buf
	call gets
;	add esp, 4

	; puts(buf);
;	push buf
	call puts
	add esp, 4

	; return 0;
	mov eax, 0
	ret
