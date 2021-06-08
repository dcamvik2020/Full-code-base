#include <stdio.h>
#include <time.h>

int main(/*int argc, char *argv[]*/) {
    int HH, MM, SS;
    time_t cur_time = time(NULL), last_time = time(NULL);
    
    while (1) {
	cur_time = time(NULL);
	
	if (cur_time == last_time + 1) {
	    last_time = cur_time;
	    SS = cur_time % 60;
	    cur_time /= 60;
	    MM = cur_time % 60;
	    cur_time /= 60;
	    HH = cur_time % 24;
	    printf("\n    %d:%d:%d    \n", HH, MM, SS);
	}
    }
    return 0;
}
