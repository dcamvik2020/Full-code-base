section .text use32 class=CODE

; ������ �������
; parameters: %1, %2, %3, %4
%macro my_macro 4			; 4 - ��� ����� ���������� � �������
	mov eax, %1			; � ���������� ���������� �� ������, ����� %
	add eax, %2
	add eax, %3
	add eax, %4
;	mov %1, %2			; ����� �� ������ � ������ �����, �� � � �����
%endmacro
; ����� �������

global _start
_start:
	my_macro 1, 2, 3, 4		; ����� �������
	; ������ ������������� ��������
	cmp eax, 10
	je end

;	my_macro eax, 2, [a], [b]	; ����� �������� �� ������ ���������, �� � �������� � �� ��� ������
	my_macro 10, 20, 30, 40		; ����� �������
	; ������ ������������� ��������
;	cmp eax, 0
;	jcc ...

end:
	mov eax, 0
	ret
