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

void PrintFromBinFileToSS(std::ifstream& input, std::stringstream& SS,
                          const Vector < std::string > & codes,
                          const Vector < char > & characters) {
    uint8_t c; /// c --> string of '0', '1'
    std::string buf; /// buffer for not used parts

    while (1) {
        input.read((char*)&c, 1);
        if (input.fail() == true) {
            break;
        }

        std::string s = buf;
        buf = ""; /// don't keep trash

        /// get string of '0', '1' from "c" -- code
        for (char cnt = 0; cnt < 8; ++cnt) {
            s += '0' + (c >> (7-cnt)) % 2;
            c -= ((c >> (7-cnt)) % 2) << (7-cnt);
        }

        /// now, find code or save it in buf
        bool read_all = false; /// checked all codes or not in all iterations
        while (s.size() && read_all == false) {
            unsigned how_many_read = 0;

            for (unsigned i = 0; i < codes.size(); ++i, ++how_many_read) {
                int res = my_strncmp(s, codes[i], codes[i].size());
                bool null = is_null(s);

                /// check if it is the last symbol to decompress and if the rest of (s) consists only of 0
                if (res == 0 && null == false) {

                    /// they equal --> find code and char for it
                    char symbol = characters[i];
                    SS.write(&symbol, 1);

                    for (unsigned j = 0; j < s.size() - codes[i].size(); j++) {     /// don't
                        s[j] = s[j + codes[i].size()];                              /// keep
                    }                                                               /// used
                    s.resize(s.size() - codes[i].size());                           /// 0 and 1
                    if (buf.size() >= codes[i].size()) {                            /// both
                        buf.resize(buf.size() - codes[i].size());                   /// in s
                    }                                                               /// and buf
                    break;
                }
            }
            if (how_many_read == codes.size()) {
                read_all = true;
            }
        }

        /// the rest we save in buf
        if (input.peek() != EOF) {
            /// if the next character exists -->
            /// we need to keep the unread part of string(s)
            buf += s;
        }
    }
}

int Decompress(const std::string& FileName, const std::string& Format) {
    /// open file to decompress
    std::ifstream input;
    /// "outputCompressedFileName.bin"
    input.open("output" + FileName + ".bin", std::ios::in | std::ios::binary);
    if (input && input.fail() == true) {
        std::cerr << "output" + FileName + ".bin : error of open()" << std::endl;
        return 1;
    }

    std::ifstream CodesTable;
    CodesTable.open("CodesTable" + FileName + ".txt", std::ios::in | std::ios::binary);
    if (CodesTable && CodesTable.fail() == true) {
        std::cerr << "CodesTable" + FileName + ".txt : error of open()" << std::endl;
        return 2;
    }

    std::ofstream output;
    output.open("decompressed" + FileName + "." + Format, std::ios::out | std::ios::binary);
    if (output && output.fail() == true) {
        std::cerr << "decompressed" + FileName + "." + Format + " : error of open()" << std::endl;
        return 3;
    }

    /// get codes
    char c;
    std::string line, code;
    Vector<std::string> codes;
    Vector<char> characters;

    for (unsigned i = 0; getline(CodesTable, line); ++i) {
        std::stringstream tmp_input;
        tmp_input << line;

        if (tmp_input.str() == "") {
            /// <--> there was '\n' <--->
            /// next line in CodesTable with code exists
            c = '\n';
            getline(CodesTable, line);
            tmp_input << line;
        } else {
            ///   <--->  if (c != '\n') {
            /// it can be ' '
            tmp_input.read(&c, 1);
        }
        /// c = '\n' --> code on the next line
        /// --> at first it will be fail
        tmp_input >> code;

        characters.push(c);
        codes.push(code);
    }

    /// decompress
    std::stringstream SS;
    PrintFromBinFileToSS(input, SS, codes, characters);

    while (1) {
        SS.read(&c, 1);
        if (SS.fail() == true) {
            break;
        }
        output.write(&c, 1);
    }
    return 0;
}
