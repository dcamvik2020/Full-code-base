#include <iostream>
#include "tools.h"
#include "operation.h"

// Plan :
// - divide to blocks matrices A & B
// - mul blocks from A & B to C
// - 

int main(int argc, char ** argv) {
  Timer timer;
  srand(time(NULL));

  /// Not enough parameters --> exit
  if (argc != 4) {
    std::cout << "Error : there should be 3 parameters.\n";
    Usage();
    return 0;
  }

  /// First step : allocate memory (matrices A, B, C)
  const unsigned N = atol(argv[1]);
  const unsigned mod = atol(argv[2]);
  const unsigned proc = atol(argv[3]);
  int ** A = new int*[N];
  int ** B = new int*[N];
  int ** C = new int*[N];
  for (unsigned i = 0; i < N; ++i) {
    A[i] = new int[N];
    B[i] = new int[N];
    C[i] = new int[N];
  }

  /// Second step : generate values
  for (unsigned i = 0; i < N; ++i) {
    for (unsigned j = 0; j < N; ++j) {
      A[i][j] = rand() % mod;
      B[j][i] = rand() % mod;
    }
  } 

  /// main step : multiplication
  mul((const int **) A, (const int **) B, C, N, proc);

  /// Final step : free memory, print result and workTime
/*
  std::cout << "Matrix A : \n";
  for (unsigned i = 0; i < N; ++i) {
    for (unsigned j = 0; j < N; ++j) {
      std::cout << A[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";

  std::cout << "Matrix B : \n";
  for (unsigned i = 0; i < N; ++i) {
    for (unsigned j = 0; j < N; ++j) {
      std::cout << B[j][i] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";

  std::cout << "Matrix C = A * B : \n";
  for (unsigned i = 0; i < N; ++i) {
    for (unsigned j = 0; j < N; ++j) {
      std::cout << C[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
*/  
  for (unsigned i = 0; i < N; ++i) {
    delete [] A[i];
    delete [] B[i];
    delete [] C[i];
  }
  delete [] A;
  delete [] B;
  delete [] C;
}
