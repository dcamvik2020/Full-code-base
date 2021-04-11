#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

// max size of shared memory segment
#define N 4096
#define MAXLEN 1024

#define IF(func)       \
    if (!(func))       \
	perror(#func); \
    else               \

// s after t, idx = len_str_1
int strins(char *point, int sizeof_str_1, int filled_memory, const char *s) {
    int len_s = strlen(s), i;
    // moving
    for (i = filled_memory + len_s - 1; i >= sizeof_str_1 + len_s; i--) {
        point[i] = point[i - len_s];
    }
    // copying
    for (i = sizeof_str_1; s[i - sizeof_str_1]; i++) {
        point[i] = s[i - sizeof_str_1];
    }
    return 0;
}

int main(int argc, char *argv[])
{
    key_t key;
    if (argc < 1) {
        printf("Too few arguments for %s\n", argv[0]);
        return 0;
    }
    //printf("Start: %s\n", argv[0]);
    IF ((key = ftok(argv[0], 0)) >= 0)
    {
        int shmid;
        IF ((shmid = shmget(key, N, 0)) >= 0) {
            char *point, s[1024];
            IF ((point = (char *) shmat(shmid, NULL, 0)) != (char *) -1) {
                //printf("Enter the string s as input for %s\ns = ", argv[0]);
                if (fgets(s, MAXLEN, stdin) != NULL) {
                    // point --> start of shared memory
                    //int i, len_s = strlen(s), flag_move_p, new_line;
                    int filled_memory, empty_memory = 0;
                    char *p = NULL, *q = NULL; //, *t;

                    // check input
                    if ((p = strchr(s, '\n')) != NULL) {
                        *p = 0;
                    }
                    
                    // find the end of the shared memory
                    q = strchr(point, '\0'); // '\0' exists

                    // find the end of the 1st string
                    if ((p = strchr(point, '\n')) == NULL) {
                        p = q;
                    }
                    
                    //if "s" isn't empty
                    if (*s) {
                        // insert the string into shared memory
                        if (((int) (q - p)) != 0) {
                            // q != p --> more than 1 string
                            // need '\n' after inserted string
                            strcat(s, "\n");
                        } else if (((int) (p - point)) != 0) {
                            strcat(point, "\n");
                            //p++; // move the end of the 1st string
                            // q++; is not neccessary
                        } else {
                            // q = p = point --> sh_mem is empty
                            empty_memory = 1;
                        }
                    } else {
                        // s is empty --> only \n
                        strcat(s, "\n");
                    }
                    
                    
                    filled_memory = strlen(point) + 1;
                    strins(point,
                          (int) (p - point) + (1 - empty_memory),
                          filled_memory, s);
                    
                    // output
                    //puts("New SH_MEM:");
                    //puts(point);
                } else {
                    //puts("s wasn't read");
                }
            }
            IF (shmdt(point) == 0) {
            }
        }
    }
    //printf("Exit from %s\n", argv[0]);
    return 0;
}
