#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    int x;
    int N, M;
    ifstream input("input.txt");
    /// N strings, M columns
    /// format : CSV (comma-separated values)
    /// print table : column_width = 10, columns are seperated
    /// by 1 space, there is NO space after the last column

    if (input) {
        input >> N >> M;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                input >> x;
                input.ignore(1);
                cout << setw(10) << x;
                if (j < M - 1)
                    cout << " ";
                else
                    cout << endl;
            }
        }
    }

    return 0;
}
