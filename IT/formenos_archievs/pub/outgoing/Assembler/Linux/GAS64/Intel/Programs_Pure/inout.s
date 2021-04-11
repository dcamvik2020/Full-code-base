.bss

max = 10
.lcomm buf, max
.lcomm len, 8

.text

.globl _start
_start:
	# ssize_t read(int fd, void *buf, size_t count);
	mov rax, 0		# read
	mov rdi, 0		# stdin
	mov rsi, offset buf
	mov rdx, max
	syscall
	mov len, rax

	# ssize_t write(int fd, const void *buf, size_t count);
	mov rax, 1		# write
	mov rdi, 1		# stdout
#	mov rsi, offset buf
	mov rdx, len
	syscall

	# void _exit(int status);
	mov rax, 60		# _exit
	mov rdi, 0
	syscall
