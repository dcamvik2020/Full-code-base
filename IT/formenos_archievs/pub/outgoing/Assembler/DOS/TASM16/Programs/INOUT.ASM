.model small
.stack 256
.data
buf	db 128 dup(?)
.code
Entry:
	; standard begin
	mov ax, @data
	mov ds, ax

	; read string
	mov buf, 8			; max len. (<=126), incl. '\r'
	mov dx, offset buf		; dx points to "M?????????"
	mov ah, 0Ah
	int 21h

	; write CR ('\r')
	mov dl, 13
	mov ah, 2
	int 21h
	; write LF ('\n')
	mov dl, 10
	mov ah, 2
	int 21h

	mov bh, 0			; now buf is "MLxxxxxxx\r", L<M
	mov bl, buf[1]			; read real len. in bx
	mov buf[bx+2], '$'		; replace '\r' with '$'
	mov dx, offset buf + 2		; dx points to "xxxxxxx$"
	mov ah, 9
	int 21h

	; standard end
	mov al, 0
	mov ah, 4Ch
	int 21h
end Entry