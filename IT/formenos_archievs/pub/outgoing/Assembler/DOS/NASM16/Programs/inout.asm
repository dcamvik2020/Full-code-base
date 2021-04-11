segment stack stack
	resb 256
stacktop:

segment data
buf	times 128 db 0

segment code
..start:
	; standard begin
	mov ax, data
	mov ds, ax
	mov ax, stack
	mov ss, ax
	mov sp, stacktop

	; read string
	mov byte [buf], 8		; max len. (<=126), incl. '\r'
	mov dx, buf			; dx points to "M?????????"
	mov ah, 0xA
	int 0x21

	; write CR ('\r')
	mov dl, 13
	mov ah, 2
	int 0x21
	; write LF ('\n')
	mov dl, 10
	mov ah, 2
	int 0x21

	mov bh, 0			; now buf is "MLxxxxxxx\r", L<M
	mov bl, [buf+1]			; read real len. in bx
	mov byte [buf+bx+2], '$'	; replace '\r' with '$'
	mov dx, buf + 2			; dx points to "xxxxxxx$"
	mov ah, 9
	int 0x21

	; standard end
	mov al, 0
	mov ah, 0x4C
	int 0x21
