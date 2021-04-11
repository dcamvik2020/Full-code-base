include io.asm
.386
.model flat

.code

Entry:
	getn ecx
	mov edx, 0

	jecxz exit_loop
main_loop:
	getn eax
	add edx, eax
	loop main_loop
exit_loop:

	putn edx
	newln

	exit 0
end Entry
