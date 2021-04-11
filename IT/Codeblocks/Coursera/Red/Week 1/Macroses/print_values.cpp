#include "test_runner.h"

#include <ostream>
#include <string>
using namespace std;

/// BAD MACROS ---> task : correct it
//#define PRINT_VALUES(out, x, y) out << (x) << endl; out << (y) << endl

#define PRINT_VALUES(out, x, y)   \
                                  \
    out << (x) << endl            \
        << (y) << endl           \
  

void TestIfElse();
void TestFor();

int main() {
  {
    TestRunner tr;
    tr.RunTest([] {
      ostringstream output;
      PRINT_VALUES(output, 5, "red belt");
      ASSERT_EQUAL(output.str(), "5\nred belt\n");
    }, "PRINT_VALUES usage example");
  }

  {
    TestRunner tr;
    tr.RunTest(TestIfElse, "If-Else");
  }

  {
    TestRunner tr;
    tr.RunTest(TestFor, "For");
  }

}

void TestIfElse(){
  ostringstream out;
  if (true)
    PRINT_VALUES(out, 1, 2);
  else
    PRINT_VALUES(out, 3, 4);
  ASSERT_EQUAL(out.str(), "1\n2\n")
}

void TestFor(){
  ostringstream out;
  for (unsigned i = 0; i < 4; ++i) {
    if (i % 2 == 0)
      PRINT_VALUES(out, i, "even");
    else
      PRINT_VALUES(out, i, "not even");
  }
  
  string expected = "";
  expected += "0\neven\n";
  expected += "1\nnot even\n";
  expected += "2\neven\n";
  expected += "3\nnot even\n";
  ASSERT_EQUAL(out.str(), expected);
}
