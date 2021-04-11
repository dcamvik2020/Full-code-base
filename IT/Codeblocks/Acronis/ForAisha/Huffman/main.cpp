#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <fstream>

#include "String.h"
#include "Vector.h"
#include "Tree.h"

#include <string>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#define MAX_FILE_NAME_LEN 255
#define MAX_DIR_NAME_LEN 4096

/// this code compresses TEXT (.txt) files with ASCII codes
/// --> it is char from 0 to 127

void HuffmanCodesForSymbols (std::ifstream& IF, Vector < std::string > & codes,
                             Vector < char > & characters);

int MakeDictionary (const std::string& InputName, const std::string& Format);

void PrintToBinFileFromSS (std::ofstream& output, std::stringstream& SS,
		           const Vector < std::string > & codes,
			   const Vector < char > & characters);
int Compress(const std::string& InputName, const std::string Format);

void PrintFromBinFileToSS (std::ifstream& input, std::stringstream& SS,
		           const Vector < std::string > & codes,
			   const Vector < char > & characters);
int Decompress (const std::string& FileName, const std::string& Format);

void Usage () {
    std::cout << "Usage:" << std::endl;
    std::cout << "In directory with executable file \"main\":" << std::endl;
    std::cout << "    ./main compress file.txt" << std::endl;
    std::cout << "        OR" << std::endl;
    std::cout << "    ./main decompress file   (\"file\" without / at the end)" << std::endl;
    std::cout << "In case of successful operation the inscription \"Success!\" will appeare." << std::endl;
}


int main (int argc, char *argv[]) {

    if (argc < 3) {
        std::cerr << "Too few arguments!" << std::endl;
        Usage();
        return 1;
    }

    if (strcmp(argv[1], "compress") != 0 && strcmp(argv[1], "decompress") != 0 ) {
        std::cerr << "Wrong command!" << std::endl;
        Usage();
        return 2;
    }

    if (strcmp(argv[1], "compress") == 0) {
        for (unsigned i = 2; argv[i]; i++) {

            /// InputName.Format ---> get InputName, Format
            char *p = strchr(argv[i], '.');
            if (p == NULL || (p - argv[i] == 0)) {
                std::cerr << "Error : wrong input file name!" << std::endl;
                return 3;
            }
            char tmp[MAX_FILE_NAME_LEN + 1] = {0};
	    char Format[MAX_FILE_NAME_LEN] = {0};
            strncpy(tmp, argv[i], (size_t) (p - argv[i]));
            strcpy(Format, p + 1);
            
            /// Create a directory for compressed, decompressed, codes table
            char cwd[MAX_DIR_NAME_LEN] = {0};
            char new_dir[MAX_DIR_NAME_LEN + 1] = {0};
            strcpy(new_dir, tmp);
            if (getcwd(cwd, MAX_DIR_NAME_LEN + 1) == 0) {
                perror("getcwd");
                return -1;
            }
            strcpy(new_dir, strcat(strcat(cwd, "/"), new_dir));
            /// rights : rwx r_x r_x
            if (mkdir(new_dir, 0755) < 0) {
                perror("mkdir");
                return -1;
            }
                        
	    
            /// Make a table with codes and compress file
	    /// mv InputName.txt InputName/
	    /// cd InputName/
	    std::string InputName(tmp);
	    /// command : mv InputName.Format file/ --> extra 9 chars
            char command_mv_file_to_its_directory[2 * MAX_FILE_NAME_LEN + 9] = {0};
 	    strcpy(command_mv_file_to_its_directory, "mv ");
	    strcat(command_mv_file_to_its_directory, tmp);
	    strcat(command_mv_file_to_its_directory, ".");
	    strcat(command_mv_file_to_its_directory, Format);
	    strcat(command_mv_file_to_its_directory, " ");
	    strcat(command_mv_file_to_its_directory, strcat(tmp, "/"));
	    system(command_mv_file_to_its_directory);
	    if (chdir(new_dir) == -1) {
                perror("chdir 1");
                return -1;
            }

            int first = MakeDictionary(InputName, Format);
            if (first) {
		std::cerr << "Error in MakeDictionary" << std::endl;
		return first;
            }

            int second = Compress(InputName, Format);
            if (second) {
		std::cerr << "Error in Compress" << std::endl;
                return second;
            }

	    if (chdir("..") == -1) {
	        perror("chdir 2");
		return -1;
	    }
        }
    } else { //if (my_strcmp(argv[1], "decompress") == 0) {
        for (unsigned i = 2; argv[i]; i++) {

            /// outputFileName.bin --> FileName is a name of needed directory -->
	    /// needed_dir = FileName --> don't need full file name
            
            /*char *p = strchr(argv[i], '.');
            if (p == NULL || (p - argv[i] <= 6)) {
                std::cerr << "Error : wrong compressed file name!" << std::endl;
                return 3;
            }*/
            char tmp[MAX_FILE_NAME_LEN + 1] = {0};
            char Format[MAX_FILE_NAME_LEN + 1] = {0};
	    //strncpy(tmp, argv[i] + 6, (size_t) (p - argv[i] - 6));
            strcpy(tmp, argv[i]); // but we could save '/' at the end of name 
	                          // the file to decompress --> detect it
            char *p = strchr(tmp, '/');
	    if (p) {	
		*p = '\0';
	    }
            
	    /// Find the format of compressed file
            DIR *dir;
	    if (!(dir = opendir(argv[i]))) {
		std::cerr << "Can't open directory: " << argv[i] << std::endl; 
		return -1;
	    }
	    struct dirent *pEntry;
	    while((pEntry = readdir(dir))) {
	        if (strncmp(pEntry -> d_name, argv[i], strlen(tmp)) == 0) {
                    strcpy(Format, pEntry -> d_name + strlen(tmp) + 1);
		    break;
		}
	    }
	    if (closedir(dir) != 0) {
		std::cerr << "Can't close directory: " << argv[i] << std::endl;
		return -1;
	    }

	    /// Go to needed directory
            char cwd[MAX_DIR_NAME_LEN] = {0};
            char needed_dir[MAX_DIR_NAME_LEN + 1] = {0};
	    strcpy(needed_dir, tmp);
            if (getcwd(cwd, MAX_DIR_NAME_LEN + 1) == 0) {
                perror("getcwd");
                return -1;
            }
	    strcpy(needed_dir, strcat(strcat(cwd, "/"), needed_dir));
            if (chdir(needed_dir) == -1) {
                perror("chdir 1");
                return -1;
            }

	    /// Decompress file
	    std::string FileName(tmp);
            int third = Decompress(FileName, Format);
            if (third) {
                return third;
            }
	    if (chdir("..") == -1) {
                perror("chdir 2");
                return -1;
            }
        }
    }

    std::cout << "Success!" << std::endl;
    return 0;
}

