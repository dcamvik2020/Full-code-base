#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include <map>
#include <set>
#include <vector>

#include <exception>

using namespace std;

///    Extra  :   division by 0 exception
///    Garanted: all that was garanted earlier.

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
        /// Exception
        if (q == 0) {
            throw invalid_argument("");
        }

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

bool operator == (const Rational& x, const Rational& y) {
    if (x.Denominator() == y.Denominator()) {
        return x.Numerator() == y.Numerator();
    }
    return x.Denominator() == y.Denominator();
}

Rational operator + (const Rational& x, const Rational& y) {
    int a = x.Numerator(), b = x.Denominator();
    int c = y.Numerator(), d = y.Denominator();
    return {a*d + b*c, b*d};
}

Rational operator - (const Rational& x, const Rational& y) {
    int a = x.Numerator(), b = x.Denominator();
    int c = y.Numerator(), d = y.Denominator();
    return {a*d - b*c, b*d};
}

Rational operator * (const Rational& x, const Rational& y) {
    return {x.Numerator() * y.Numerator(), x.Denominator() * y.Denominator()};
}

Rational operator / (const Rational& x, const Rational& y) {
    if (y.Numerator() == 0) {
        throw domain_error("");
    }
    return {x.Numerator() * y.Denominator(), x.Denominator() * y.Numerator()};
}

istream& operator >> (istream& input, Rational& x) {

    char c;
    int a, b;
    if (input.tellg() != -1) {
        input >> a;
        if (input.tellg() != -1) {
            input >> c;
            if (c != '/') {                     /// we need
                throw invalid_argument("");     /// to
            }
            if (input.tellg() != -1) {
                input >> b;
                if (input.fail() == false) {
                    x = Rational(a, b);
                } else {
                    throw invalid_argument(""); /// throw
                }                               /// an
            } else {                            /// exception
                throw invalid_argument("");     /// after
            }                                   /// every
        } else {                                /// fail
            throw invalid_argument("");         /// situation
        }
    }
    return input;
}

ostream& operator << (ostream& output, const Rational& x) {
    output << x.Numerator() << "/" << x.Denominator();
    return output;
}

bool operator < (const Rational& x, const Rational& y) {
    /// it is not clear
    ///return x.Numerator() * y.Denominator() < x.Denominator() * y.Numerator();

    /// it is clear
    return (x-y).Numerator() < 0;
}



int main()
{
    ///   exp = x/y + a/b
    ///   garanted :y, b >= 0

    /// so... "cin" reads just before the first space
    /// thus, we have to wtite "1/2+1/3" instead of
    /// "1/2 + 1/3"... it is uncomfortable

    int a, b, x, y;
    char c1, c2, operation;
    cin >> a >> c1 >> b
        >> operation
        >> x >> c2 >> y;



    Rational A, B;
    stringstream expression;
    expression << a << c1 << b
               << operation
               << x << c2 << y;
    //cout << "      srteam.str : _|" << expression.str() << "|_" << endl;
    try {
        expression >> A >> operation >> B;
        //cin >> A;
    } catch (invalid_argument&) {
        cout << "Invalid argument" << endl;
        return 1;
    }



    switch (operation) {
        case '+':
            cout << A + B << endl;
            break;
        case '-':
            cout << A - B << endl;
            break;
        case '*':
            cout << A * B << endl;
            break;
        case '/':
            try {
                cout << A / B << endl;
                break;
            } catch (domain_error&) {
                cout << "Division by zero" << endl;
                return 2;
            }
    }
    return 0;
}
