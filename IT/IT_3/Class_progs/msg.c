#include <stdio.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>

#define N 101

#define IF(func)           \
	if (!(func))       \
            perror(#func); \
	else               \

int main(int argc, char *argv[]) {
    key_t key;
    IF ((key = ftok(argv[0], 0)) >= 0) {
        int msqid;
        ssize_t len;
        // create new message queue or get existing
        IF ((msqid = msgget(key, IPC_CREAT | 0666)) >= 0) {
            //message for sending
            struct _msg {
                long mtype;
                char mtext[N];
            } buf_snd;
            scanf("%ld", &buf_snd.mtype);
            fgets(buf_snd.mtext, N-1, stdin);
            //message for receiving
            struct {
                long mtype;
                struct _msg msg;
            } buf_rcv = {0, {0, ""}};
            IF (msgsnd(msqid, (struct msgbuf *) &buf_snd, N, 0) >= 0) {
            }
            IF ((len = msgrcv(msqid, (struct msgbuf *) &buf_rcv, sizeof buf_rcv.msg, 1, 0)) >= 0) {
            }
            printf("%s\n", buf_rcv.msg.mtext);
        }
    }
    return 0;
}
