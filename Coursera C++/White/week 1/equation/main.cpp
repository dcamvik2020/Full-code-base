#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c, D; /// ax^2 + bx + c = 0
    cin >> a >> b >> c;
    if (a) {
        D = b*b - 4*a*c;
        if (!D) {
            cout << -b / 2 / a << endl;
        } else if (D > 0) {
            cout << (-b - sqrt(D)) / 2 / a << " " << (-b + sqrt(D)) / 2 / a << endl;
        }
    } else {
        if (b) cout << -c / b;
    }
    return 0;
}
