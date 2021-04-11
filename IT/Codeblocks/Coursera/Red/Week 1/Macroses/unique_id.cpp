#include <string>
#include <vector>
using namespace std;

// Реализуйте этот макрос так, чтобы функция main компилировалась
#define id id
//#define x x                            /// This way ...
#define f(a, b) a ## b
#define ID(line) f(id, line)
//#define id(line) f(x, line)            /// doesn't ...
#define UNIQ_ID ID(__LINE__)
//#define UNIQ_ID id(__LINE__)           /// work ... WHHHYYYYY ????


///           their code ... 
/*  #define UNIQ_ID_IMPL_2(lineno) _a_local_var_##lineno
 *  #define UNIQ_ID_IMPL(lineno) UNIQ_ID_IMPL_2(lineno)
 *  #define UNIQ_ID UNIQ_ID_IMPL(__LINE__)
 */


int main() {
  int UNIQ_ID = 0;
  string UNIQ_ID = "hello";
  vector<string> UNIQ_ID = {"hello", "world"};
  vector<int> UNIQ_ID = {1, 2, 3, 4};

  //id12++;

  return 0;
}
