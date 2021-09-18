#include <iostream>

#define pi 3.141528

/// sin (x) = x - x^3 / 6 + x^5 / 5! - ...
int main() {
    double x, k = 1, sum = 0, tmp;
    std::cin >> x; // angle in degrees
    x = x * pi / 180;
    //std::cout << "x (rad) = " << x << std::endl;
    tmp = x;
    for (unsigned i = 1; i < 30; ++i) {
        //std::cout << "step " << i << " tmp = " << tmp << std::endl;
	sum += k * tmp;
	tmp *= x * x;
	k *= (double)(-1) / (2 * i) / (2 * i + 1); 
    }
    std::cout << sum << std::endl;
    return 0;
}
