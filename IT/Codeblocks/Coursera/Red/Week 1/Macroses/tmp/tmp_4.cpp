#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

//#define f(a, b) a ## b
//#define g(a) #a
//#define h(a) g(a)


#define f(a) #a
#define g(x) f(a)
#define asser(x, y)            \
    ostringstream os;          \
    os << x << " "            \
       << #y << endl;          \
    cout << os.str() << endl;

int main() {
	ostringstream os0;
	os0 << "karaganda";
	asser(os0.str(), 2); /// output: karaganda 2
	
	//cout << g(f(1, 2)) << endl;
	//cout << h(f(1, 2)) << endl;
	return 0;
}
