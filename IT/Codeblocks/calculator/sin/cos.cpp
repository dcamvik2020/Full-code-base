#include <iostream>

#define pi 3.141528

/// cos (x) = 1 - x*2/2 + x^4 /4! - x^6 / 6! - ...
int main() {
    double x, k = 0.5, sum = 1, tmp;
    std::cin >> x; // angle in degrees
    x = x * pi / 180;
    tmp = x * x;
    for (unsigned i = 1; i < 30; ++i) {
       	sum -= k * tmp;
	tmp *= x * x;
	k *= (double)(-1) / (2 * i + 1) / (2 * i + 2); 
    }
    std::cout << sum << std::endl;
    return 0;
}
