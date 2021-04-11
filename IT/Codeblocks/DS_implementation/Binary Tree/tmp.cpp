#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int * a = new int[n];
    int * b = a;
    delete [] b;
    return 0;
}
