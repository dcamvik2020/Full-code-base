.data

Message:
	.ascii "Hell, Word!\n"
Length = . - Message

.text

.globl _start
_start:
	# ssize_t write(int fd, const void *buf, size_t count);
	mov rax, 1		# write
	mov rdi, 1		# stdout
	mov rsi, offset Message
	mov rdx, Length
	syscall

	# void _exit(int status);
	mov rax, 60		# _exit
	mov rdi, 0
	syscall
