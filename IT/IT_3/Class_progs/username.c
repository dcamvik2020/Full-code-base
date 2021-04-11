#include <stdio.h>
//#include <stdlib.h>      not needed ... ?
//#include <sys/types.h>   not needed ... ?
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

int main(void) {
    uid_t a = getuid();
    gid_t b = getgid();
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
