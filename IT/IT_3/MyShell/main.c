#include "headers.h"

#include "colors.h"
#include "macros.h"
#include "constants.h"

#include "print_user_cwd.h"
#include "parse_cmd.h"

void update_history(char history[][MAX_CMD_LEN], const char *cmd) {
    int i;
    if (strcmp(cmd, history[0]) == 0) return;
    
    // delete the oldest cmd, move all down, add new
    for (i = MAX_HISTORY_SIZE - 1; i > 0; i--) {
        strcpy(history[i], history[i-1]);
    }
    strcpy(history[0], cmd);
}

int main(int argc, char *argv[]) {

    char cmd[MAX_CMD_LEN] = "";
    char history[MAX_HISTORY_SIZE][MAX_CMD_LEN] = {{0}};

    if (argc > 1) {
	puts("Too many arguments!");
	exit(0);
    }
    if (!argv[0]) {
        puts("Don't have name of the program!");
	exit(0);
    } 
    
    while (1) {
        print_user_pwd();    	    
	if (fgets(cmd, MAX_CMD_LEN, stdin) != NULL) {
            
	    // check our command
	    char *p;
	    if ((p = strchr(cmd, '\n'))) {
                *p = '\0';
	    }
	    if (strcmp(cmd, "exit") == 0) {
                return 0;
	    }
	    if (strcmp(cmd, "") == 0) {
                continue;
	    }
            //if (strcmp(cmd, "^[[A") == 0) {
            //   strcpy(cmd, history[0]);
	    //   printf("  ->  %s", cmd);
	    //}
            // parse and excute it
	    parse(cmd);
            update_history(history, cmd);
            
	    /*
	    puts("HISTORY:");
            for (i = 0; history[i][0]; i++) {
                puts(history[i]);
	    }
	    puts("");
            */

        } else {
            puts("Can't read the command");
	}
    }
}
