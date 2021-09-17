#include <iostream>

#include "number.h"
//#include "add_sub.h"

#include <string>
#include <ctime>

void testSum ();
void testSub ();

int main ()
{
    std::string a_0, b_0;
    Number a(a_0), b(b_0);

	
    testSum();
    testSub();
    
    Number a_copy = a;

    //sum.print();
    //print(sum);
    
    return 0;
}
