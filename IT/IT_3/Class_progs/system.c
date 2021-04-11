#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define N 4097
//4095 symbols, 1 '\n', 1 '\0' must be got in buffer

int args(char *s) {
    int i;
    char *p, *t;
    if ((t = strrchr(s, '\n'))) {
        *t = 0;
    }
    // if s = "" --> for won't execute, but i will be set as 0
    for (i = 0, p = s, t = s; p && *p; i++) {
        if ((p = strchr(t, ' '))) {
            for (; *p == ' '; *p = '\0', p++);
        }
        t = p;
    }
    return i;
}

void string_split_to_attr(char *s, char **argv, int argc) {
    int i;
    char *p;
    for (i = 0, p = s; i < argc; i++) {
        argv[i] = p;
        p = strchr(p, 0);
        for (; i < argc - 1 && !(*p); p++);
    }
    argv[argc] = NULL;
}

int main() {
    int argc;
    pid_t res;
    char s[N], **argv = NULL;
    while (fgets(s, N, stdin)) {
        // fgets reads max 4096 = N - 1: 4095 s[], '\n'
        if (!(argc = args(s))) {
            continue;
        } // argc = 0 --> not execute it
        if ((res = fork()) == -1) {
            perror("fork");
        } else if (res == 0) { //child process
            if ((argv = (char**) malloc((argc + 1) * sizeof(char*)))) {
                string_split_to_attr(s, argv, argc);
                execvp(argv[0], argv);
                perror("execvp");
                free(argv);
            }
            //exit(0); can cause some problems if there is another code/program after this program
            return 0;
        } // parent process
        if (waitpid(res, NULL, 0) == -1) {
            perror("waitpid");
        }
    }
    return 0;
}

