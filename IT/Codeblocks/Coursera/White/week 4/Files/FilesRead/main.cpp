#include <iostream>
#include <fstream>

using namespace std;

void print(ifstream& input) {
    string line;
    while (getline(input, line)) {
        cout << line << endl;
    }
}

int main()
{
    ifstream input("input.txt");
    if (input) {
        print(input);
    }
    return 0;
}
