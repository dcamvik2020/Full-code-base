#include <iostream>

// HORISONTAL works faster
//#define HORISONTAL

// 1000 --> stackoverflow
#define N 100
#define REPEAT 100000

int main() {
  int A[N][N] = {{123456}};
  unsigned sum = 0;
  
  #ifdef HORISONTAL
  std::cout << "HORISONTAL:" << std::endl;
  for (int index = 0; index < REPEAT; ++index) { 
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        sum += A[i][j];
      }
    }
  }
  #else
  std::cout << "VERTICAL:" << std::endl;
  for (int index = 0; index < REPEAT; ++index) { 
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        sum += A[j][i];
      }
    }
  }
  #endif
  return 0;
}
