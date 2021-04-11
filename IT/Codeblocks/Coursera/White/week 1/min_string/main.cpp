#include <iostream>

using namespace std;

int main()
{
    string a, b, c, min;
    cin >> a >> b >> c;
    min = a;
    if (b < a) min = b;
    if (c < min) min = c;
    cout << min << endl;
    return 0;
}
