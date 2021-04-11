.data

Message:
	.ascii "Hell, Word!\n"
Length = . - Message

.text

.globl _start
_start:
	# ssize_t write(int fd, const void *buf, size_t count);
	movq $1, %rax		# write
	movq $1, %rdi		# stdout
	movq $Message, %rsi
	movq $Length, %rdx
	syscall

	# void _exit(int status);
	movq $60, %rax		# _exit
	movq $0, %rdi
	syscall
