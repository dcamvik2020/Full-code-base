//#include <iostream>


/// TASK : to get a unique id for variables

#define f(a, b) a ## b

//    the first way
//#define line(__LINE__) __LINE__
//#define param(line) f(x, line)          ---> ok


//    the second way
#define g(a) f(x, a)                //    ---> ok
#define param g(__LINE__)           //    ---> ok
int main() {
  int param  = 5;                 //      ---> works
  
  
  //int param(line(__LINE__)) = 5;        ---> works
  //std::cout << x11 << std::endl;
  return 0;
}
