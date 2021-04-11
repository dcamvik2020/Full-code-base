#include <stdio.h>
#include <errno.h>
#include <pthread.h>

void *thread_proc(void *arg) {
    int i;
    for (i = 0; i < 200000; i++) {
        printf("%s", (char *)arg);
    }
    puts("");
    if (*((char *) arg) == 'F') {
        return (void *) "First";
    } else {
        return (void *) "Second";
    }
    // return (void *)arg;
}

int main() {
    int i;
    char *t;
    pthread_t TID1, TID2; //memory allocation for TID1 is important;
    if ((errno = pthread_create(&TID1, NULL, thread_proc, "F ")) != 0) {
        perror("pthread_create (1)");
    } else {
        if ((errno = pthread_create(&TID2, NULL, thread_proc, "S ")) != 0) {
            perror("pthread_create (2)");
        } else {
            for (i = 0; i < 100000; i++) {
                printf("M ");
            }
            puts("");
            if ((errno = pthread_join(TID2, (void**)&t)) != 0) {
                perror("pthread_join (2)");
            }
	    printf("\nAfter second process: %s\n",t);
        }
        if ((errno = pthread_join(TID1, (void**)&t)) != 0) {
            perror("pthread_join (1)");
        }
        printf("\nAfter first process: %s\n", t);
    }
    return 0;
}

