#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int x1, y1, x2, y2;
    cout << "Ends of 1st section :" << endl;
    cin >> x1 >> y1 >> x2 >> y2;
    int x3, y3, x4, y4;
    cout << "Ends of 2nd section :" << endl;
    cin >> x3 >> y3 >> x4 >> y4;

    /// intersection test : 2 tests checking that points are 
    /// on different sides from line ---> vector products

    int a, b, c, d;
    int vec_mul_1, vec_mul_2;
    /// vector product of 2 vectors from (0, 0) to (a, b) and (c, d)
    /// det({ {a, b} , {c, d} }) = a * d - c * b

    /// line  (x1, y1)-(x2, y2), points (x3, y3) and (x4, y4)
    /// (x1, y1) will be as (0, 0)
    a = x2 - x1; /// "core" vector that
    b = y2 - y1; /// would be used twice
    c = x3 - x1;
    d = y3 - y1;
    vec_mul_1 = a * d - b * c;
    c = x4 - x1;
    d = y4 - y1;
    vec_mul_2 = a * d - b * c;
    if (vec_mul_1 * vec_mul_2 > 0) {
        cout << "Lines don't cross" << endl;
	return 0;
    }

    /// line  (x3, y3)-(x4, y4), points (x1, y1) and (x2, y2)
    /// (x3, y3) will be as (0, 0)
    a = x4 - x3; /// "core" vector that
    b = y4 - y3; /// would be used twice
    c = x1 - x3;
    d = y1 - y3;
    vec_mul_1 = a * d - b * c;
    c = x2 - x1;
    d = y2 - y1;
    vec_mul_2 = a * d - b * c;
    if (vec_mul_1 * vec_mul_2 > 0) {
        cout << "Lines don't cross" << endl;
	return 0;
    }
    cout << "Lines cross" << endl;
    return 0;
}
