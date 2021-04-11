; section .bss use32 class=BSS

; buf	resb 101
; sz_buf	equ $ - buf

section .data use32 class=DATA

buf	times 101 db 0
sz_buf	equ $ - buf
t1	db "Qwe123RTY",0
t2	db "QWE011rty",0
t3	db "ABqwe911-0YZ",0

section .text use32 class=CODE

extern gets
extern puts


; 6) Text doesn't contain any characters except digits and Latin characters
global check
check:
	mov edx, [esp+4]
check_cycle:			; for (i = 0; s[i]; i++)
	mov cl, [edx]		; cl = s[i];
	cmp cl, 0
	je exit_check_cycle
		cmp cl, '0'		; if (!(s[i] >= '0' &&
		jb check_if1
		cmp cl, '9'		;	s[i] <= '9' ||
		jbe exit_check_if
check_if1:
		cmp cl, 'A'		;	s[i] >= 'A' &&
		jb check_if2
		cmp cl, 'Z'		;	s[i] <= 'Z' ||
		jbe exit_check_if
check_if2:
		cmp cl, 'a'		;	s[i] >= 'a' &&
		jb check_if_body
		cmp cl, 'z'		;	s[i] <= 'z'))
		jbe exit_check_if
check_if_body:
			xor eax, eax
			ret
exit_check_if:
	inc edx
	jmp check_cycle
exit_check_cycle:
	mov eax, 1
	ret


; 2) Replace each digit (except 0) with corresponding lower-case Latin character (1 -> a, 2 -> b, ..., 9 -> i)
global rule1
rule1:
	mov edx, [esp+4]
rule1_cycle:			; for (i = 0; s[i]; i++)
	mov cl, [edx]		; cl = s[i];
	cmp cl, 0
	je exit_rule1_cycle
		cmp cl, '1'		; if (s[i] >= '1' &&
		jb exit_rule1_if
		cmp cl, '9'		;	s[i] <= '9')
		ja exit_rule1_if
			add byte [edx], 'a' - '1'	; s[i] += 'a' - '1'
exit_rule1_if:
	inc edx
	jmp rule1_cycle
exit_rule1_cycle:
	ret


; 5) Leave only that characters, that appears only once
global rule2
rule2:
;	enter 256, 0		; prologue; char A[256];
	push ebp
	mov ebp, esp
	push esi
	push edi
	sub esp, 256

;				; char A[256] = {0};
;	mov al, 0		; char to fill
;	mov edi, esp		; address of A
;	mov ecx, 256		; length of array
;	cld			; clear direction flag (move forward)
;rep	stosb			; for (ecx; ecx > 0; ecx--) es:[edi++] = al;

	mov edx, [ebp+8]	; char *s
				; A[0] is [esp]

	mov ecx, 256		; length of array
rule2_fill0:			; for (i = 255; i >= 0; i--)
	mov byte [esp+ecx-1], 0	;	A[i] = 0;
	loop rule2_fill0

;	mov ecx, 0
	mov esi, 0
rule2_parse:			; for (i = 0; s[i]; i++)
	cmp byte [edx+esi], 0
	je exit_rule2_parse
		mov cl, [edx+esi]	; s[i]
		inc byte [esp+ecx]	; A[s[i]]++;
	inc esi
	jmp rule2_parse
exit_rule2_parse:

	mov esi, 0		; source index, j
	mov edi, esi		; destination index, i
rule2_cycle:			; for (i = j = 0; s[j]; i++, j++)
	cmp byte [edx+esi], 0
	je exit_rule2_cycle
		mov cl, [edx+esi]	; s[j]
		cmp byte [esp+ecx], 1	; if (A[s[j]] > 1)   i--;
		jbe else_rule2_if
			dec edi
			jmp exit_rule2_if	; else
else_rule2_if:
;		mov cl, [edx+esi]
		mov [edx+edi], cl	; s[i] = s[j];
exit_rule2_if:
	inc esi
	inc edi
	jmp rule2_cycle
exit_rule2_cycle:
	mov byte [edx+edi], 0	; s[i] = '\0';

	add esp, 256
	pop edi
	pop esi
	mov esp, ebp
	pop ebp
;	leave			; epilogue
	ret


global test
test:
	mov eax, [esp+4]
	cmp eax, 3
	jl l2
	mov eax, t3
	ret
l2:
	cmp eax, 2
	jl l1
	mov eax, t2
	ret
l1:
	mov eax, t1
	ret


global main
main:
	; gets(buf)
	push buf
	call gets
;	add esp, 4

	; puts(buf);
;	push buf
	call puts
;	add esp, 4

;	push buf
	call check
;	add esp, 4
	test eax, eax
	jz do_rule2
;		push buf
		call rule1
;		add esp, 4
		jmp exit_main_check
do_rule2:
;		push buf
		call rule2
;		add esp, 4
exit_main_check:

	; puts(buf);
;	push buf
	call puts
	add esp, 4

	; return 0;
	mov eax, 0
	ret


extern exit

global _start
_start:
	call main

	; exit(ret);
	push eax
	call exit
;	add esp, 4
