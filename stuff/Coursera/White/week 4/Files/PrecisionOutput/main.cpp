#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    double x;
    ifstream input("input.txt");

    if (input) {
        cout << fixed << setprecision(3);
        while (input >> x) {
            cout << x << endl;
        }
    }
    return 0;
}
