#include <iostream>
#include <string>   /// for to_string
#include <deque>

using namespace std;

void ArithmeticExp(int x, int N) {
    deque<char> exp;
    string number = to_string(x);
    for (unsigned i = 0; i < number.size(); ++i) {
        exp.push_back(number[i]);
    }

    int num; /// number
    char op; /// operation
    for (int i = 0; i < N; ++i) {
        exp.push_front('(');
	exp.push_back(')');
	cin >> op >> num;

	exp.push_back(' ');
        exp.push_back(op);
	exp.push_back(' ');
	
	number = to_string(num);
	for (unsigned i = 0; i < number.size(); ++i) {
	    exp.push_back(number[i]);
	}
    }

    /// print exp
    for (const char & c : exp) {
        cout << c;
    }
    cout << endl;
}

int main() {
    int x;       /// "root" of an expression
    cin >> x;
    int N;       /// quantity of operations :
    cin >> N;    /// + a, - b, * c, / d
    
    ArithmeticExp(x, N);
    return 0;
}
