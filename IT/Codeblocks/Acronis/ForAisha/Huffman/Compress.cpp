#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>

#include "String.h"
#include "Vector.h"
#include "Tree.h"

#include <string>
#include <cstring>

void PrintToBinFileFromSS(std::ofstream& output, std::stringstream& SS,
                          const Vector < std::string > & codes,
                          const Vector < char > & characters) {
    char c;
    char cnt = 0; /// counter of bits 0/1
    char symbol; /// from SS --> put its code to output

    uint8_t tmp = 0; /// fro comfortable write, we will put
    /// it to file as a simple block of bits

    while (1) {
        SS.read(&symbol, 1);
        if (SS.fail() == true) {
            break;
        }

        unsigned index = characters.find(symbol);
        std::stringstream local_input;
        local_input << codes[index];

        while (1) {
            local_input.read(&c, 1);
            if (local_input.fail() == true) {
                break;
            }

            if (cnt == 8) {
                output << tmp;
                cnt = 0;
                tmp = 0;
            }
            /// 2*63+1 = 127 (max char)
            tmp += (c - '0') << (7 - cnt);
            ++cnt;
        }
    }
    if (cnt > 0) {
        ///final tmp to put in file
        output << tmp;
    }
}

int Compress(const std::string& InputName, const std::string Format) {
    /// PART 2 : COMPRESS FILE
    std::ifstream input;
    input.open(InputName + "." + Format, std::ios::in);
    if (input && input.fail() == true) {
        std::cerr << InputName + "." + Format << " : error of open()" << std::endl;
        return 1;
    }

    std::ifstream CodesTable;
    CodesTable.open("CodesTable" + InputName + ".txt", std::ios::in | std::ios::binary);
    if (CodesTable && CodesTable.fail() == true) {
        std::cerr << "CodesTable" + InputName + ".txt : error of open()" << std::endl;
        return 2;
    }

    std::ofstream output;
    output.open("output" + InputName + ".bin", std::ios::out | std::ios::binary);
    if (output && output.fail() == true) {
        std::cerr << "output" + InputName + ".bin : error of open()" << std::endl;
        return 3;
    }

    char c;
    std::string line, code;
    Vector<std::string> codes;
    Vector<char> characters;

    for (unsigned i = 0; getline(CodesTable, line); ++i) {
        std::stringstream tmp_input;
        tmp_input << line;

        /// c = '\n' --> code on the next line -->
        /// --> at first it will be fail
        if (tmp_input.str() == "") {
            /// <--> there was '\n' <--->
            /// next line in CodesTable with code exists
            c = '\n';
            getline(CodesTable, line);
            tmp_input << line;
        } else {
            /// <--->  if (c != '\n') {
            /// it can be ' '
            tmp_input.read(&c, 1);
        }
        tmp_input >> code;

        characters.push(c);
        codes.push(code);
    }

    std::stringstream SS; /// String Stream
    while (getline(input, line)) {
        line += '\n';
        SS << line;
    }

    /// IN  SS  WE  HAVE  THE  TEXT  TO  COMPRESS
    PrintToBinFileFromSS(output, SS, codes, characters);

    return 0;
}

