segment stack stack
	resb 256
stacktop:

segment data
Message	db "Hell, Word!",0xD,0xA,'$'

segment code
..start:
	mov ax, data
	mov ds, ax
	mov ax, stack
	mov ss, ax
	mov sp, stacktop

	mov dx, Message
	mov ah, 9
	int 0x21

	mov al, 0
	mov ah, 0x4C
	int 0x21
