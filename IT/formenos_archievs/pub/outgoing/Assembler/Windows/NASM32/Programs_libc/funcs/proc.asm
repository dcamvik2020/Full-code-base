section .text use32 class=CODE

; ������ ���������
; parameters: eax, ebx, ecx, edx
; returns: eax
my_proc:
	add eax, ebx
	add eax, ecx
	add eax, edx
	ret
; ����� ���������

global _start
_start:
	; �������� ���������� ����� ��������
	mov eax, 1
	mov ebx, 2
	mov ecx, 3
	mov edx, 4
	call my_proc	; ����� ���������
	; ������ ������������� ��������
	cmp eax, 10
	je end

	; �������� ���������� ����� ��������
	mov eax, 10
	mov ebx, 20
	mov ecx, 30
	mov edx, 40
	call my_proc	; ����� ���������
	; ������ ������������� ��������
;	cmp eax, 0
;	jcc ...

end:
	mov eax, 0
	ret
