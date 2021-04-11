#include <iostream>
#include <cstring>
#include <dirent.h>
#include <sys/types.h>

std::string LastFileInDirectory(const std::string & dirname) {
    DIR * d;
    if ((d = opendir(dirname.c_str())) == nullptr) {
        perror("opendir");
        return "";
    }
    std::string name;
    struct dirent *pEntry;
    // find the last file in sorted order in directory
    while ((pEntry = readdir(d)))  {
        if (((pEntry -> d_type) & DT_DIR) == 0) {
            if (strcmp(name.c_str(), pEntry -> d_name) < 0) {
                name = pEntry -> d_name;
	    }
	    std::cout << name << std::endl;
        }
    }
    std::cout << std::endl;
    return name;
}

int main() {
  std::string dirname;
  std::cin >> dirname;
  std::cout << LastFileInDirectory(dirname) << std::endl;
}
