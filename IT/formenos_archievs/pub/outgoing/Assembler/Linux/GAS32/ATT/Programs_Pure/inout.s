.bss

max = 10
.lcomm buf, max
.lcomm len, 4

.text

.globl _start
_start:
	# ssize_t read(int fd, void *buf, size_t count);
	movl $3, %eax		# read
	movl $0, %ebx		# stdin
	movl $buf, %ecx
	movl $max, %edx
	int $0x80
	movl %eax, len

	# ssize_t write(int fd, const void *buf, size_t count);
	movl $4, %eax		# write
	movl $1, %ebx		# stdout
#	movl $buf, %ecx
	movl len, %edx
	int $0x80

	# void _exit(int status);
	movl $1, %eax		# _exit
	movl $0, %ebx
	int $0x80
