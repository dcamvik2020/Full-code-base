#include <iostream>
#include <sstream>
#include <string>
#include <math.h>

#include <map>
#include <set>
#include <vector>

using namespace std;

///    PART  5  : map, set, vector of Rational
///                 (operator <)
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
    return {x.Numerator() * y.Denominator(), x.Denominator() * y.Numerator()};
}

bool IsNumber(const string& s) {
    int i;
    for (i = 0; s[i] == ' '; ++i);
    for (; s[i]; ++i) {
        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }
    return true;
}

istream& operator >> (istream& input, Rational& x) {

    char c;
    int a, b;
    if (input.tellg() != -1) {
        input >> a;
        if (input.tellg() != -1) {
            input >> c;
            if (input.tellg() != -1) {
                input >> b;
                if (input.fail() == false) {
                    x = Rational(a, b);
                }
            }
        }
    }
    return input;

/// VERSION 2   ---   OK, but not so nice and breifly
/*
    if (input.tellg() == -1) {
        return input;
    }
    input >> a;
    if (input.tellg() == -1) {
        return input;
    }
    input >> c;
    if (input.tellg() == -1) {
        return input;
    }
    input >> b;
    if (input.fail()) {
        return input;
    }
    x = Rational(a, b);
    return input;
*/

/// VERSION 1   ----    complete fail
/*
    string line;
    getline(input, line);
    stringstream stream;
    stream << line;
    if (stream.str() == "") {
        return input;
    }
    /// if stream is empty ---> return
    if (!input || input.peek() == -1 ||
                  input.peek() == '\n' ||
                  input.tellg() == -1) {
        return input;
    }*/
/*
    int a;
    string b;
    char c;
    //input >> a;
    stream >> a;
    //if (input.eof() == false) {
    if (stream.str() != "") {
        //input >> c;
        stream >> c;
        if (c == '/') {
            //input >> b;
            stream >> b;
            if (IsNumber(b)) {
                x = Rational{a, stoi(b)};
            }
        }
    }
    input << line[stream.tellg()];
    return input;
*/


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

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
