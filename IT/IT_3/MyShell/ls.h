
// here are functions:
int compar(const void *a, const void *b);
void smart_print_ls(char **file_list, int files);
void ls();



int compar(const void *a, const void *b) {
    // a --> char *      then:      *a -->  char **
    return strcmp(*(char **) a, *(char **) b);
}

void smart_print_ls(char **file_list, int files) {
    // we need to print names of files with right color
    // and to make right choice of number of names in a line
    int i, j, rows, columns; //columns = #(words in line)
    int max_filename_len = 0;
    int console_width;
    struct winsize size;
    
    ioctl(0, TIOCGWINSZ, &size);
    console_width = size.ws_col;

    for (i = 0; i < files; i++) {
        int len = strlen(file_list[i]);
	max_filename_len = max(len, max_filename_len);
    }

    columns = console_width / (max_filename_len + 1); // +1 --> whitespace
    rows = round_up(files, columns);
    
    printf("max_filename = %d\n"
	   "", max_filename_len);

    // i = 0 --> file_list[0] = "."
    // i = 1 --> file_list".."
    for (i = 0; i < rows; i++) {
	for (j = 0; (2 + i + j * rows < files) && j < columns; j++) {
	    int k = 2 + i + j * rows, white_spaces;
	    char file_execute_rights;
	    struct stat buf;
            
	    stat(file_list[k], &buf);
            file_execute_rights = buf.st_mode & 0111;

	    if (file_execute_rights) {
                printf(BOLD_GREEN);
	    }
	    printf("%s", file_list[k]);
	    printf(COLOR_RESET);
	    
	    for (white_spaces = 0; 
	         white_spaces < max_filename_len+1-(int)strlen(file_list[k]);
		 white_spaces++) {
                printf(" ");
	    }
	}
	puts("");
    }
}

void ls() {
    // we need to scan directory and print all files in it
    int files = 0, i;
    DIR *dir;
    char cwd[MAX_CWD_LEN + 1];
    char **file_list = NULL;
    struct dirent *pEntry;

    // get cwd
    if (!getcwd(cwd, MAX_CWD_LEN + 1)) {
        perror("getcwd");
    } else {
        // open dir (cwd)
        if (!(dir = opendir(cwd))) {
            perror("opendir");
        } else {
            // count files
            while ((pEntry = readdir(dir))) {
                files++;
            }
            
            // read dir again
            rewinddir(dir);

            // save & sort filenames
            if ((file_list = (char **) malloc(files * sizeof(char *)))) {
                for (i = 0; i < files; i++) {
                    pEntry = readdir(dir);
                    if ((file_list[i] = strdup(pEntry -> d_name)) == NULL) {
                        perror("strdup");
                        exit(0);
                    }
                }
                
		// sort --> file_list[0] = ".", file_list[1] = ".."
		qsort(file_list, files, sizeof(char *), compar);
		
                // print & free
                smart_print_ls(file_list, files);
		
		for (i = 0; i < files; i++) {
                    //puts(file_list[i]);
		    free(file_list[i]);
                }
                free(file_list);
            } else {
                puts("Can't print the list of files!");
            }
            
	    // close dir
	    if (closedir(dir) == -1) {
                perror("closedir");
            }
        }
    }
}
