.model small
.stack 256
.data
Message	db "Hell, Word!",0Dh,0Ah,'$'
.code
Entry:
	mov ax, @data
	mov ds, ax

	mov dx, offset Message
	mov ah, 9
	int 21h

	mov al, 0
	mov ah, 4Ch
	int 21h
end Entry