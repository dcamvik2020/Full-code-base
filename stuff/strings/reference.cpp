#include <iostream>

void foo (const std::string & s) {
    std::string s1 = s;
	std::cout << s1 << "\n";
    s1[0] = 'h';
	std::cout << s1 << "\n";
}

int main () {
    std::string s = "abcdefg";
	foo(s);
    return 0;
}
