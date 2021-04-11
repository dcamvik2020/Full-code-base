#include <stdio.h>
#include <sys/ioctl.h>

int main() {
    int console_width, console_height;
    struct winsize size;
    ioctl(0, TIOCGWINSZ, &size);
    console_width = size.ws_col;
    console_height = size.ws_row;
    printf("console_width = %d\nconsole_height = %d\n", console_width, console_height);
    return 0;
}

