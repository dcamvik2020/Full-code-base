include io.asm
.386
.model flat

.data

buf	db 10 dup(0)
max	equ $ - buf

.code

Entry:
	gets max, offset buf
	puts offset buf
	newln
	exit 0
end Entry
