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
#define ASCII_SIZE 128

void HuffmanCodesForSymbols (std::ifstream& IF,
                             Vector < std::string > & codes,
                             Vector < char > & characters) {

    /// input
    struct {
        unsigned CharNum[ASCII_SIZE] = {0}; /// has a map
        int Chars[ASCII_SIZE];              /// function
        int cmp(const void* a, const void* b) {
            /// decreasing from 0 to 127 = max_ascii
            return CharNum[(int)(*(char*)a)] - CharNum[(int)(*(char*)b)];
        }
    } CharsData; /// don't need type, just merge some arrays and comparator

    std::string line;
    std::stringstream input;
    while (getline(IF, line)) {
        input << line << '\n';
    }
    for (int i = 0; i < ASCII_SIZE; ++i) {
        CharsData.Chars[i] = i;
    }
    char c;
    while (1) {
        input.read(&c, 1);
        if (input.fail() == true) {
            break;
        }
        ++CharsData.CharNum[(int)c];
    }

    /// create ground for tree
    Vector<Element> Ground;
    Vector<Node> Tree;
    for (int i = 0, iter = 0; i < ASCII_SIZE; ++i) {
        if (CharsData.CharNum[CharsData.Chars[i]]) {
            unsigned index = Ground.insert(Element(CharsData.CharNum[CharsData.Chars[i]], iter));
            iter++; /// new (sorted) positions of needed characters
            Tree.insert( Node(0, 0, 0, 0, CharsData.Chars[i]) , index);
        }
    }

    /// build tree: connect ground nodes --> every iteration new Node that
    /// connects to 2 other Nodes --> (N-1) iterations
    for (unsigned i = 0; Ground.size() > 1; i += 2) {

        /// Ground is sorted always!
        unsigned min1 = Ground[0].sum, min2 = Ground[1].sum;
        Tree.push(Node(i, i+1, Tree.size(), 0, -1));

        /// after push Tree.size() increases
        Tree[i].parent = Tree.size() - 1;
        Tree[i].branch = 0;
        Tree[i+1].parent = Tree.size() - 1;
        Tree[i+1].branch = 1;
        Ground.erase(0);
        Ground.erase(0);
        Ground.insert(Element(min1 + min2, Tree.size() - 1));
    }

    for (unsigned index = 0; Tree[index].c >= 0; ++index) {
        std::string tmp = "";
        for (unsigned i = index; i != Tree.size() - 1; i = Tree[i].parent) {
            tmp += Tree[i].branch + '0';
        }
        Reverse(tmp);
        codes.push(tmp);
        characters.push(Tree[index].c);
    }
}

int MakeDictionary(const std::string& InputName, const std::string& Format) {

    /// PART 1 : MAKE "CODE DICTIONARY"
    std::ifstream input;
    input.open(InputName + "." + Format, std::ios::in | std::ios::binary);
    if (input.fail() == true) {
        std::cerr << InputName + "." + Format << " : error of open()" << std::endl;
        return 1;
    }

    std::ofstream CodesTable;
    CodesTable.open("CodesTable" + InputName + ".txt", std::ios::out);
    if (CodesTable.fail() == true) {
        std::cerr << "CodesTable" + InputName + ".txt : error of open()" << std::endl;
        input.close();
        return 2;
    }

    Vector<std::string> codes;
    Vector<char> characters;
    HuffmanCodesForSymbols(input, codes, characters);

    for (unsigned i = 0; i < codes.size(); ++i) {
        CodesTable << characters[i] << " " << codes[i] << std::endl;
    }

    CodesTable.close();
    input.close();
    return 0;
}


