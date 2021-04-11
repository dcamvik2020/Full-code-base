#include <iostream>
#include <time.h>

using std::cin;
using std::cout;
using std::endl;

void bubble(int * a, unsigned n);

int main() {
    srand(time(NULL));
    unsigned n;
    cin >> n;
    int * a = new int[n]();
    for (unsigned i = 0; i < n; ++i) {
        cin >> a[i];
    }
    bubble(a, n);
    for (unsigned i = 0; i < n; ++i) {
        cout << a[i] << endl;
    }
    cout << endl;
    delete [] a;
    return 0;
}

void bubble(int * a, unsigned n) {
    int buf;
    for (unsigned i = 0; i < n; ++i) {
        for (unsigned j = 1; j < n - i; j++) {
	    if (a[j-1] > a[j]) {
                buf = a[j-1];
                a[j-1] = a[j];
                a[j] = buf;
            }
	}
    }
}
