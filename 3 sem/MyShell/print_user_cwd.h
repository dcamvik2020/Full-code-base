

void find_part_cwd(char *part_cwd, char *user) {
    char cwd[MAX_CWD_LEN], *p, *usr_in_cwd;
    char *last_slash = NULL, *penalt_slash;
    if (!getcwd(cwd, MAX_CWD_LEN)) {
        perror("getcwd");
	exit(0);
    } else {
        // find the username in cwd
	usr_in_cwd = strstr(cwd, user);

        // in bash: if cwd = /home/username/...
	// then we need to check all after username 
        if (usr_in_cwd) {
	    // /home/username/IT --> /IT
	    // BUT!! if (cwd == "/home/username") --> problem:
	    // [usr_in_cwd + strlen(user)] not in cwd --> SIGSEGV
            if (*(usr_in_cwd + strlen(user)) == '/') {
                strcpy(cwd, usr_in_cwd + strlen(user));
	    } else {
                strcpy(cwd, "");
	    }
	    strcat(part_cwd, "~");
	}

        // find in cwd "/dir/dir"
	last_slash = strrchr(cwd, '/');
	penalt_slash = last_slash;
	if (last_slash) {
            for (p = last_slash - 1; (int) (p - cwd) >= 0; p--) {
                if (*p == '/') {
                    penalt_slash = p;
		    break;
	        } 
	    }
            strcat(part_cwd, penalt_slash);
        }
    }
}

void print_user_pwd() {
    // $USER@$HOSTNAME:~/dir2/dir1$
    
    char username[MAX_USER_HOST + 1] = ""; // ... + '\0'
    char hostname[MAX_USER_HOST + 1] = ""; // ... + '\0'
    char part_cwd[2 * (MAX_FILE_NAME + 1)] = ""; // "/dir/dir" -> 
                                                 // 2(1+MAX_FILE_NAME)

    // find $USER
    if ((strcpy(username, getlogin())) == NULL) {
        perror("getlogin");
	exit(0);
    } 

    // find $HOSTNAME
    if (gethostname(hostname, MAX_USER_HOST) != 0) {
        perror("gethostname");
	exit(0);
    }
    
    // 2 last dirs
    find_part_cwd(part_cwd, username);
       
    printf(BOLD_GREEN "%s@%s" 
           COLOR_RESET ":" 
	   BOLD_BLUE "%s" 
	   COLOR_RESET "$ ",
           username, hostname, part_cwd);
}
