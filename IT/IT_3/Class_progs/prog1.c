#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

int main(void) {
	pid_t a = getpid();
	pid_t c = fork();
	uid_t x = getuid();
	gid_t y = getgid();
	struct passwd *A;
	/*if (!c)
	{
		perror("error");
		return -1;
	}*/
	if (a == getpid()) puts("Parent");
        if (a == getppid()) puts("Child");
	printf("pid = %d\n", getpid());
	return 0;
}

