#include <iostream>
#include <thread>

#include <vector>

#include "tools.h"
#include "Matrix.h"

int main(int argc, char ** argv) {
  
  if (argc < 3 || argc > 4) {
    std::cout << "Error : wrong usage. There should be 3 or 4 parameters.\n";
    Usage();
    return 0;
  }
  std::string mode = "both";
  if (argc == 4) {
    mode = std::string(argv[3]);
    if (mode != "both" && mode != "threads" && mode != "usual") {
      std::cout << "Error : wrong work mode. It can be \"threads\", \"usual\" or \"both\"";
      Usage();
      return 0;
    }
  }
  


  const unsigned N = atol(argv[1]);
  //std::cout << "Matrices size : " << N << " * " << N << "\n";
 
  Timer timer; 
  double work_time_1, work_time_2;
  Matrix A("A", N, N);
  Matrix B("B", N, N); /// will be kept transposed
  Matrix C("C", N, N, false);

  
  
  /// MAIN PART 1
  if (mode == "threads" || mode == "both") {
    timer.reset();
    const unsigned threads = std::min((long)12, atol(argv[2]));
    //std::cout << "Available threads : "
    std::cout << threads << "       "; 
    //std::cout << "With threads--> ";
    //printf("%lf\n", work_time_1);
    C = mul(A, B, threads);
    work_time_1 = timer.elapsed();
    printf("      %lf          ", work_time_1);
  }



  /// MAIN PART 2
  Matrix D("D", N, N, false);
  if (mode == "usual" || mode == "both") {
    timer.reset();
    mul_func(0, N, A, N,  B, N, D);
    //std::cout << "Usual algo  --> ";
    //printf("%lf\n", work_time_2);
    work_time_2 = timer.elapsed();
    printf("%lf", work_time_2);
  }



  /// RESULT
  if (mode == "both") {
    bool correct = (C == D);
    std::cout << "        ";
    std::cout << work_time_2 / work_time_1;
    std::cout << "       RESULT is ";
    if (correct == true) {
      std::cout << "correct";
    } else { 
      std::cout << "INcorrect";
    }
  }
  std::cout << "\n"; 
  return 0;
}
