#include <iostream>
#include <ctime>

#include <stdexcept>
#include "number.h"

void testSum () {
    /// test sum
    srand(time(NULL));
	std::cout << "Sum test : ";
    Number a, b;
	for (unsigned i = 0; i < 10000; ++i) {
        unsigned x = rand() % 100000000;
        unsigned y = rand() % 100000000;
        a = std::to_string(x);
        b = std::to_string(y);

        Number sum = a + b;
        std::string c = std::to_string(x + y);
        Number real_sum(c);

        if (sum != real_sum) {
            std::cout << "Wrong answer! for "
                      << "a = " << a << "\tb = " << b
                      <<"\nExpected : ";
            std::cout << a + b << " = " << real_sum;
            std::cout << "\nGotten : " << sum << "\n";

            std::cout << "blocks in real_sum : "
                      << real_sum.getData().size() << "\n";

            std::cout << "blocks in sum : "
                      << sum.getData().size() << "\n";
            throw std::runtime_error("Wrong answer!");
		}
        //std::cout << sum << "\n";
    }
    std::cout << "OK\n\n";
}

void testSub () {
    /// test sub
    srand(time(NULL));
    Number a, b;
	std::cout << "Sub test : ";
    for (unsigned i = 0; i < 10000; ++i) {
        unsigned x = rand() % 100000000;
        unsigned y = rand() % 100000000;
        a = std::to_string(x);
        b = std::to_string(y);

        Number sub = a - b;
        std::string c = std::to_string(x - y);
        Number real_sub(c);

        if (sub != real_sub) {
            std::cout << "Wrong answer! for "
                      << "a = " << a << "\tb = " << b
                      <<"\nExpected : ";
            std::cout << a - b << " = " << real_sub;
            std::cout << "\nGotten : " << sub << "\n";

            std::cout << "blocks in real_sum : "
                      << real_sub.getData().size() << "\n";

            std::cout << "blocks in sum : "
                      << sub.getData().size() << "\n";
            throw std::runtime_error("Wrong answer!");
        }
        //std::cout << sum << "\n";
    }
    std::cout << "OK\n\n";
}

