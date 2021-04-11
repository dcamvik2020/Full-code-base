#include <iostream>

using namespace std;

void my_swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int x, y;
    int &a = x, &b = y;
    cin >> x >> y;
    my_swap(a, b);
    cout << x << " " << y << endl;
    return 0;
}
