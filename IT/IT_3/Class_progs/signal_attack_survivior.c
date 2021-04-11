#include <stdio.h>
#include <signal.h>

#define MAX_SIG 31
typedef void (*sighandler_t) (int);

int sig_count[MAX_SIG];

void handler(int signum) {
    if (sig_count[signum - 1] <= 2) {
        printf("%d\n", signum);
	sig_count[signum - 1]++;
    }
}

int main() {
    sighandler_t old_handler;
    while (1) {
        old_hadler = signal(signum, handler);
    }
    //printf("%d\n", SIGKILL);
    return 0;
}
