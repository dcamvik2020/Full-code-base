// we have such command as:
// - pwd
// - cd
// - ls

#include "ls.h"
#include "constants.h"

void pwd();
void cd(char *path);
int args(const char *s);

void parse(const char *cmd) {
    // we need to define the command we have received
    //char *p = NULL;
    if (strcmp(cmd, "pwd") == 0) {
        pwd();
    } else if (strncmp(cmd, "cd ", 3) == 0) {
        char path[MAX_CWD_LEN];
	if (args(cmd) > 2) {
            puts("Too many arguments!");
	} else if (args(cmd) < 2) { 
            puts("Too few arguments!");
	} else {
            sscanf(cmd, "cd  %s", path);
	    cd(path);
	}
    } else if (strcmp(cmd, "ls") == 0) {
        ls();
    } else {
        puts("Unknown command!");
    }
}

int args(const char *s) {
    int i;
    const char *p, *t; // p++, t++ --> possible
                       // *p = ..., *t = ... --> ERROR!!!

    // if s = "" --> for won't execute, but i will be set as 0
    for (i = 0, p = s, t = s; p && *p; i++) {
        if ((p = strchr(t, ' '))) {
            for (; *p == ' '; p++);
        } 
        t = p;
    }
    return i;
}

void pwd() {
    char cwd[MAX_CWD_LEN + 1];
    if (!getcwd(cwd, MAX_CWD_LEN + 1)) {
        perror("getcwd");
    } else {
        puts(cwd);
    } 
}

void cd(char *path) {
    if (chdir(path) < 0) {
        perror("chdir");
    }
    //pwd();
}
