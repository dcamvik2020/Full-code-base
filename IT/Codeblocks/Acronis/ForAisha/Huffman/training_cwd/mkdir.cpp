#include <iostream>
#include <unistd.h>
#include <cstring>

/// for mkdir
#include <sys/stat.h>
#include <sys/types.h>
#define MAX_DIR_NAME_LEN 4096
/// change cwd
/// print new cwd
/// return to initial cwd

int main() {
    
    char cwd[MAX_DIR_NAME_LEN] = {0};
    char new_dir[MAX_DIR_NAME_LEN + 1] = {0};
    std::cin >> new_dir;
    
    
    
    
    if (getcwd(cwd, MAX_DIR_NAME_LEN + 1) == 0) {
        perror("getcwd");
        return -1;
    }
    std::cout << cwd << std::endl;
    strcpy(new_dir, strcat(strcat(cwd, "/"), new_dir));
    /// rights : rwx r_x r_x
    if (mkdir(new_dir, 0755) < 0) {
        perror("mkdir");
        return -1;
    }
    if (chdir(new_dir) == -1) {
        perror("chdir");
	return -1;
    }
    if (getcwd(cwd, MAX_DIR_NAME_LEN + 1) == 0) {
        perror("getcwd");
        return -1;
    }
    std::cout << cwd << std::endl;



    chdir("..");
    if (getcwd(cwd, MAX_DIR_NAME_LEN + 1) == 0) {
        perror("getcwd");
        return -1;
    }
    std::cout << cwd << std::endl;
    return 0;
}
