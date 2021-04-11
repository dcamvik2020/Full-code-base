.bss

max = 10
.lcomm buf, max
.lcomm len, 8

.text

.globl _start
_start:
	# ssize_t read(int fd, void *buf, size_t count);
	movq $0, %rax		# read
	movq $0, %rdi		# stdin
	movq $buf, %rsi
	movq $max, %rdx
	syscall
	movq %rax, len

	# ssize_t write(int fd, const void *buf, size_t count);
	movq $1, %rax		# write
	movq $1, %rdi		# stdout
#	movq $buf, %rsi
	movq len, %rdx
	syscall

	# void _exit(int status);
	movq $60, %rax		# _exit
	movq $0, %rdi
	syscall
