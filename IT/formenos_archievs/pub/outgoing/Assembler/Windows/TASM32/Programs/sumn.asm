include io.asm
.386
.model flat

.data

num	dd 0

.code

Entry:
	getn num
	mov edx, 0

	mov edi, 0
main_cycle:
	cmp edi, num
	jae short exit_cycle
	getn eax
	add edx, eax
	inc edi
	jmp short main_cycle
exit_cycle:

	putn edx
	newln

	exit 0
end Entry
