#include <iostream>
#include <fstream>

using namespace std;

void PrintToFile(ifstream& input, ofstream& output) {
    string line;
    while (getline(input, line)) {
        output << line << endl;
    }
}

int main()
{
    ifstream input("input.txt");
    if (input) {
        ofstream output("output.txt");
        if (output) {
            PrintToFile(input, output);
        }
    }
    return 0;
}
