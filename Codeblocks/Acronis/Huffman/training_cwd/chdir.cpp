#include <iostream>
#include <unistd.h>
#include <cstring>

/// change cwd
/// print new cwd
/// return to initial cwd

int main() {
    char *cwd;
    char name[256] = {0};
    char new_name[256] = {0};

    strcpy(name, cwd = get_current_dir_name());
    free(cwd);
    std::cout << name << std::endl;

    chdir("..");
    strcpy(new_name, cwd = get_current_dir_name());
    free(cwd);
    std::cout << new_name << std::endl;

    chdir(name);
    strcpy(new_name, cwd = get_current_dir_name());
    free(cwd);
    std::cout << new_name << std::endl;

    return 0;
}
