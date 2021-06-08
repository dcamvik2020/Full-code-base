#include <stdio.h>

#define IF(func)       \
    if (!(func))       \
        perror(#func); \
    else               \

int main(int argc, char *argv[]) {
    long offset = 0;
    FILE *file;
    char c;
    if (argc < 2) {
        puts("Too few arguments");
    } else {
        IF ((file = fopen(argv[1], "w+")) != NULL) {
            
	    // print at the beginning
	    fprintf(file, "%s", "Read from here!");
            offset = ftell(file); // current offset
	    
	    // print again to the start
	    rewind(file);
            fprintf(file, "%s: ", "Remember");
	    
	    // print at the end of file
	    fseek(file, 0, SEEK_END);
	    fprintf(file, " %s", "Mission complete!");
	    
            // check the "offset"-position
            fseek(file, offset, SEEK_SET);
            fscanf(file, "%c", &c);
	    printf("The symbol at old offset: %c\n", c);

	    fclose(file);
	}
    }
    return 0;
}
