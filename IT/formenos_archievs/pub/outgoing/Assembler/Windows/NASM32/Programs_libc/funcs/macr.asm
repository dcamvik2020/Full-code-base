section .text use32 class=CODE

; Начало макроса
; parameters: %1, %2, %3, %4
%macro my_macro 4			; 4 - это число параметров в макросе
	mov eax, %1			; к параметрам обращаемся по номеру, после %
	add eax, %2
	add eax, %3
	add eax, %4
;	mov %1, %2			; можно не только в правой части, но и в левой
%endmacro
; Конец макроса

global _start
_start:
	my_macro 1, 2, 3, 4		; вызов макроса
	; анализ возвращаемого значения
	cmp eax, 10
	je end

;	my_macro eax, 2, [a], [b]	; можно подавать не только константы, но и регистры и всё что угодно
	my_macro 10, 20, 30, 40		; вызов макроса
	; анализ возвращаемого значения
;	cmp eax, 0
;	jcc ...

end:
	mov eax, 0
	ret
