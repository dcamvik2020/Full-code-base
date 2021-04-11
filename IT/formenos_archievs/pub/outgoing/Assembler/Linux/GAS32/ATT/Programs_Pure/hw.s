.data

Message:
	.ascii "Hell, Word!\n"
Length = . - Message

.text

.globl _start
_start:
	# ssize_t write(int fd, const void *buf, size_t count);
	movl $4, %eax		# write
	movl $1, %ebx		# stdout
	movl $Message, %ecx
	movl $Length, %edx
	int $0x80

	# void _exit(int status);
	movl $1, %eax		# _exit
	movl $0, %ebx
	int $0x80
