#include <iostream>

#define pi 3.141528

/// sin (x) = x - x^3 / 6 + x^5 / 5! - ...
int main() {
    double x, k, tmp;
    std::cin >> x; // angle in degrees
    x = x * pi / 180;
    
    /// sin(x)
    double sin;
    k = 1, sin = 0, tmp = x;
    for (unsigned i = 1; i < 30; ++i) {
        //std::cout << "step " << i << " tmp = " << tmp << std::endl;
	sin += k * tmp;
	tmp *= x * x;
	k *= (double)(-1) / (2 * i) / (2 * i + 1); 
    }

    /// cos(x)
    double cos;
    k = 0.5, cos = 1;
    tmp = x * x;
    for (unsigned i = 1; i < 30; ++i) {
        cos -= k * tmp;
        tmp *= x * x;
        k *= (double)(-1) / (2 * i + 1) / (2 * i + 2);
    }

    /// tg(x)
    double tg = sin / cos;
    std::cout << tg << std::endl;
    return 0;
}
