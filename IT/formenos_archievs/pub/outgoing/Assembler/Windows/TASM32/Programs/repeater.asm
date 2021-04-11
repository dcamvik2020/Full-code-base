include io.asm
.386
.model flat

.data

buf	db 256 dup(0)
max	equ $ - buf

.code

Entry:				; while (gets(max, buf))
	gets max, offset buf
	cmp eax, 0
	je short exit_file_cycle
	puts offset buf		;	puts(buf);
	newln
	jmp short Entry
exit_file_cycle:
	exit 0
end Entry
