.486
.data
cwr	dw	?
rq	label	qword
rd	label	dword
rab	dt	?
adr_rab	dd	rab+8

.xlist
.start	macro	a
	mov	ax,@data
	mov	ds,ax
	ifnb	<a>
	assume	es:@data
	mov	es,ax
	endif
	endm

get_ch	macro	x
	mov	ah,8
	int	21h
	ifnb	<x>
	  mov	x,al
	endif
	endm

newline	macro
	push	ax
	push	dx
	mov	ah,2
	mov	dl,13
	int	21h
	mov	dl,10
	int	21h
	pop	dx
	pop	ax
	endm

pr_char	macro	c,k:=<1>
	push	ax
	mov	ah,2
	ifdifi	<c>,<dl>
	  push	dx
	  mov     dl,c
	endif
	ifidni <k>,<bx>
	  push	cx	;; первая строка
	  mov	cx,bx
	elseif k gt 1
	  push	cx	;; вторая строка
	  mov	cx,k
	endif
	int	21h
	ifidni <k>,<bx>
	  loop	$-2
	  pop	cx
	elseif k gt 1
	  loop	$-2
	  pop	cx
	endif
	ifdifi	<c>,<dl>
	  pop	dx
	endif
	pop	ax
	endm

pr_str	macro	str
	push	ax
	push	dx
	mov	ah,9
	lea	dx,str
	int	21h
	pop	dx
	pop	ax
	endm

pr_int	macro	x,m:=<1>
	local	m1,m2,m3,m4,m5,m6,m7,m8,fin
	pusha
	if type x eq 1
	 push	ax
	 mov	ah,x
	 sar	ax,8
	 mov	word ptr rab,ax
	 pop	ax
	 fild	word ptr rab
	else
	 fild	x		; Загрузили в стек FPU целое число
	endif
	fbstp	rab		; Выгрузили в память в BCD формате
	les	di,adr_rab	; Старший байт - байт знака и переполнения
	mov	al,[di+1]
	xor	al,0ffh		; Если =FFh - переполнение
	jnz	short m1
	pr_char	'*',5		; печатаем звездочки
	jmp	fin
m1:	mov	al,[di+1]
	test	al,80h		; Проверка знака
	jz	short m2
	pr_char	'-'		; Печатаем минус, если число отрицательное
m2:	std
	mov	cx,9		; Обработка матниссы
	xor	al,al
	repe	scasb		; Пропускаем старшие нули
	jz	short m5
	mov	bx,cx
	inc	bx
	shl	bx,1
	sub	bl,m
	ja	short m6
	jz	short m8
	neg	bl
	pr_char	'0',bx
m8:	mov	bh,1
m6:	mov	dl,[di+1]	; Первый не нулевой байт
	shr	dl,4
	jnz	short m3
	test	bh,1
	jz	short m7
m3:	add	dl,48		; Цифра в старшем полубайте не нуль
	pr_char	dl
m7:	mov	dl,[di+1]
	and	dl,0fh		; Цифра из младшего полубайта
	add	dl,48
	pr_char	dl
	jcxz	short fin	; Переход если этот байт единственный
	mov	si,di
m4:	lodsb
	mov	dl,al
	shr	dl,4		; Старший полубайт текущего байта
	add	dl,48
	pr_char	dl
	mov	dl,al
	and	dl,0fh		; Младший полубайт текущего байта
	add	dl,48
	pr_char	dl
loop	m4
	jmp	short fin
m5:	pr_char	'0',m		; Печать нулевого числа
fin:	cld
	popa
	endm

print	macro	tp,x,after:=<5>
	local	m,m1,k
	ifidni	<tp>,<int>
	  pr_int x           	; Вывод целого числа со знаком
	elseifidni <tp>,<unsign>
	  push	ax		; Вывод целого без знака
k= (type x) /2 
	while k lt 3
	mov	word ptr rab + 2*k,0
k=k+1
	endm
	  if type x eq 1
	    mov	al,x
	    mov byte ptr rq,al
	  elseif type x eq 2
	    mov	ax,x
	    mov	word ptr rq,ax
	  elseif type x eq 4
	    mov eax,x
	    mov	dword ptr rq,eax
	  else
	    Display "Error Type of Unsigned Parameter &x"
	    .err
	    exitm
	  endif
	  pop	ax
	  pr_int rq
	elseifidni <tp>,<real>
	fstcw	cwr		; Вывод вещественного числа
	push	cwr
	and	cwr,0f3ffh	; Установить режим отбрасывания дробной части
	or	cwr,0c00h
	fldcw	cwr
	fld	x		; Загузить в стек FPU вещественное число
	fist	rd		; сохранить в памяти целую часть
	push	rd
	cmp	rd,0
	jnz	short m1
	ftst
	fstsw	ax
	sahf
	jae	short m1
	pr_char '-'
m1:	pr_int	rd		; и вывести её
	pr_char	'.'		; Вывести десятичную точку
	pop	rd
	fisub	rd		; Вычислить дробную часть
	ftst
	fstsw	ax
	sahf
	ja	short m
	fchs			; Изменить знак в случае отрицательного числа
m:
k=0
	rept 5
	  mov	word ptr rab + k,0
k=k+2
	endm
	if (after mod 2) eq 1
	  mov	byte ptr rab+(after shr 1),10h
	else
	  mov	byte ptr rab+(after shr 1),1
	endif			; Определили сомножитель для выделения
	fbld	rab		; цифр после запятой
	fmul
	pop	cwr		; Воссатновить прежний режим работы FPU
	fldcw	cwr
	fistp	rd		; Сохранить целое число составленное из цифр,
	pr_int	rd,after	; стоящих после запятой и вывести его
	else
	 Display	"Error First Parameter"
	 .err
	endif
	endm

fpw	macro	x,y,z
	local cnt
	k= (type x) - 1
	mov	al,byte ptr (x+k)
	test	al,80h
	jz	cnt
.exit 1
cnt:	finit	
	fld	y
	fld	x
	fyl2x
	fld	st
	frndint
	fxch
	fsub	st,st(1)
	f2xm1
	fld1
	fadd
	fscale
	ffree	st(1)
	ifnb	<z>
	  fstp	z
	else
	  fstp	x
	endif
	endm

profiler	macro		; Печатает значение регистра счетчика тактов
	pushad
	db	0fh,31h		; RDTSC
	mov	rd,eax
	popad
	print	unsign,rd
	endm
.list