#include <iostream>
#include <unistd.h>
#include <cstring>

int main() {
    char *cwd;
    char name[256] = {0};
    
    strcpy(name, cwd = get_current_dir_name());
    std::cout << name << std::endl;
    
    free(cwd);
    return 0;
}
