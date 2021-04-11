#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int x1, y1, x2, y2;
    cout << "Points of 1st line :" << endl;
    cin >> x1 >> y1 >> x2 >> y2;
    int x3, y3, x4, y4;
    cout << "Points of 2nd line :" << endl;
    cin >> x3 >> y3 >> x4 >> y4;

    /// lines ---> check that they are parallel --->
    /// check  (vector_A x vector_B) == 0 ---> det() == 0

    int a, b, c, d;
    int vec_mul;
    /// vector product of 2 vectors from (0, 0) to (a, b) and (c, d)
    /// det({ {a, b} , {c, d} }) = a * d - c * b

    /// line  (x1, y1)-(x2, y2), points (x3, y3) and (x4, y4)
    /// (x1, y1) will be as (0, 0)
    a = x2 - x1; /// first
    b = y2 - y1; /// line
    c = x4 - x2; /// second
    d = y4 - y2; /// line
    vec_mul = a * d - b * c;
    if (vec_mul != 0) {
        cout << "Lines cross" << endl;
	return 0;
    }
    cout << "Lines don't cross" << endl;
    return 0;
}
