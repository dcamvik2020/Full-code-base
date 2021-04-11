#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

int main(void) {
    uid_t a = geteuid();
    gid_t b = getegid();
    struct passwd *A = getpwuid(a);
    struct group *B = getgrgid(b);
    if (!A) {
        perror("getpwuid");
    } else {
        if (!B) {
            perror("getgrgid");
        } else {
            printf("%s (%d)\n%s (%d)\n", A->pw_name, a, B->gr_name, b);
        }
    }
    return 0;
}
