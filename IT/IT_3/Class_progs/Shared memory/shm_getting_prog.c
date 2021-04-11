#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// Max size of shared memory
#define N 4096
#define IF(func)       \
    if (!(func))       \
        perror(#func); \
    else               \

// s after t, idx = len_str_1
int strins(char *point, int len_str_1, int len_filled_sh_mem, const char *s) {
    int len_s = strlen(s), i;
    for (i = len_filled_sh_mem + len_str_1; i >= len_filled_sh_mem + len_s; i--) {
        point[i] = point[i - len_s];
    }
    for (i = len_str_1; s[i - len_str_1]; i++) {
        point[i] = s[i - len_str_1];
    }
    //puts(t);
    return 0;
}

int main(int argc, char *argv[]) {
    int shmid;
    // argv[1] --> name of main program, used to make key
    key_t key;
    //printf("Start: %s\n", argv[0]);
    if (argc < 2) {
        printf("Too few arguments for %s\n", argv[0]);
        return 0;
    }
    IF ((key = ftok(argv[1], 0)) >= 0) {
        IF ((shmid = shmget(key, N, 0666 | IPC_CREAT)) >= 0) {
            char *point; //, *t, *p;
            IF ((point = (char *) shmat(shmid, NULL, 0)) != (char *) -1) {
                pid_t res;
                char s[] = "String1";

                // paste 2 string: String1, String2
                *point = '\0';
                sprintf(point, "%s", s);
                puts("Old SH_MEM:");
		puts(point);

                if ((res = fork()) < 0) {
                    perror("fork");
                } else if (res == 0) {
                    execlp(argv[1], argv[1], NULL);
                    perror("execlp");
                    return 0;
                } else {
                    waitpid(res, NULL, 0);
                }
            }
            IF (shmctl(shmid, IPC_RMID, NULL) == 0) {
            }
        }
    }
    //printf("Exit from %s\n", argv[0]);
    return 0;
}
