#include <iostream>
#include <thread>

#include <vector>
#include <ctime>
#include <queue>

#include "tools.h"
#include "Matrix.h"

int main(int argc, char ** argv) {
  
  if (argc < 3 || argc > 4) {
    std::cout << "Error: wrong usage.\n";
    Usage();
    return 0;
  }
  std::string mode;
  if (argc == 3) {
    mode = "both";
  } else if (argc == 4) {
    mode = std::string(argv[3]);
  }



  const unsigned N = atol(argv[1]);
  //std::cout << "Matrices size : " << N << " * " << N << "\n";
  srand(time(NULL));
 
  Timer timer; 
  Matrix A("A", N, N);
  Matrix B("B", N, N); /// will be kept transposed
  Matrix C("C", N, N);

  for (unsigned i = 0; i < N; ++i) {
    for (unsigned j = 0; j < N; ++j) {
      A[i][j] = rand() % 10;
      B[j][i] = rand() % 10; /// transposed
    }
  }



  double work_time_1, work_time_2;
  
  /// MAIN PART 1
  if (mode == "threads" || mode == "both") {
    const unsigned threads = std::min((long)12, atol(argv[2]));
    //std::cout << "Available threads : " << threads << "\n";
    std::cout << threads << "       ";
    std::vector<std::thread> T;
    const unsigned rows_per_thread = N / threads;
    timer.reset();
    for (unsigned tid = 0; tid < threads; ++tid) {
      unsigned first_row = rows_per_thread * tid;
      unsigned last_row = (tid == threads - 1) ? N : rows_per_thread * (tid + 1);
      T.push_back( std::thread(mul_func, first_row, last_row,
			     std::cref(A), std::cref(B), 
  			     std::ref(C), N) );
    }  
    for (unsigned i = 0; i < T.size(); ++i) {
      T[i].join();
    }
    //std::cout << "With threads--> ";
    //printf("%lf\n", work_time_1);
    work_time_1 = timer.elapsed();
    //printf("      %lf          ", work_time_1);
  }



  /// MAIN PART 2
  Matrix D("D", N, N);
  if (mode == "usual" || mode == "both") {
    timer.reset();
    mul_func(0, N, A, B, D, N);
    //std::cout << "Usual algo  --> ";
    //printf("%lf\n", work_time_2);
    work_time_2 = timer.elapsed();
    //printf("%lf", work_time_2);
  }



  /// RESULT
  if (mode == "both") {
    bool correct = (C == D);
    std::cout << "        ";
    std::cout << work_time_2 / work_time_1;
    //std::cout << "       RESULT is ";
    if (correct == true) {
      //std::cout << "correct";
    } else { 
      std::cout << "INcorrect";
    }
  }
  std::cout << "\n"; 
  return 0;
}
