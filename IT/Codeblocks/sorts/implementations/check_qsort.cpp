#include <iostream>


using std::cin;
using std::cout;
using std::endl;

int cmp(const void * a, const void * b) {
    return *(int *)a - *(int *)b;
}

int main() {
    unsigned n;
    cin >> n;

    int * a = new int[n];
    for (unsigned i = 0; i < n; ++i) {
	cin >> a[i];
    }
    qsort(a, n, sizeof(int), cmp);
    for (unsigned i = 0; i < n; ++i) {
        cout << a[i] << endl;
    }
    cout << endl;
    delete [] a;
    return 0;
}
