include io.asm
.386
.model flat

.data

num	dd 0

.code

Entry:
	getn num
	getn eax
	add eax, num
	putn eax
	newln
	exit 0
end Entry
