include io.asm
.386
.model flat

.data

Message	db "Hell, Word!",0

.code

Entry:
	puts offset Message
	newln
	exit 0
end Entry
