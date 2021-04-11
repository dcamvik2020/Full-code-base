SSEG segment stack 'stack'
	db 256 dup(?)
SSEG ends

DSEG segment
Message	db "Hell, Word!",0Dh,0Ah,'$'
DSEG ends

CSEG segment
assume cs: CSEG, ds: DSEG, ss: SSEG, es: nothing
Entry:
	mov ax, DSEG
	mov ds, ax

	mov dx, offset Message
	mov ah, 9
	int 21h

	mov al, 0
	mov ah, 4Ch
	int 21h
CSEG ends
end Entry