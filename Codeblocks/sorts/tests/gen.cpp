#include <iostream>
#include <time.h>

using std::cin;
using std::cout;
using std::endl;

int main() {
    srand(time(NULL));

    int n;
    cin >> n;
    
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        cout << rand() << " ";
    }
    return 0;
}
