#include <iostream>
#include <math.h>

using namespace std;

///    PART  2  : operators ==, +, -
///    Garanted: type int is evrywhere.

int GCD(int a, int b) {
    while (b) {
        if (a >= b) {
            a = a % b;
        }
        swap(a, b);
    }
    return a;
}

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int p, int q) {
        /// GCD
        if (q < 0) {
            p *= -1;
            q *= -1;
        }
        int gcd = GCD(abs(p), abs(q));
        numerator   = gcd ? (p / gcd) : p;
        denominator = gcd ? (q / gcd) : q;
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

private:
    int numerator;
    int denominator;
};

bool operator == (Rational x, Rational y) {
    if (x.Denominator() == y.Denominator()) {
        return x.Numerator() == y.Numerator();
    }
    return x.Denominator() == y.Denominator();
}

Rational operator + (Rational x, Rational y) {
    int a = x.Numerator(), b = x.Denominator();
    int c = y.Numerator(), d = y.Denominator();
    return {a*d + b*c,
             + b*d};
}

Rational operator - (Rational x, Rational y) {
    int a = x.Numerator(), b = x.Denominator();
    int c = y.Numerator(), d = y.Denominator();
    return {a*d - b*c,
             + b*d};
}

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
