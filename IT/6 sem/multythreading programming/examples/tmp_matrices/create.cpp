#include <iostream>
#include <thread>

#include <ctime>

#include <queue>


/// A, B, C -- square matrices
/// B is transposed
void func(int * rowA, int ** B, int * rowC, unsigned size,
	  std::queue<unsigned> & free_threads,
	  unsigned min_free_proc_pos) {
  for (unsigned j = 0; j < size; ++j) {
    rowC[j] = 0;
    for (unsigned k = 0; k < size; ++k) {
      rowC[j] += rowA[k] * B[j][k];
    }
  }
  free_threads.push(min_free_proc_pos);
}

void Usage() {
  std::cout << "Usage : \n"
	  << "\t./create N proc\n"
	    << "N = size of matrices\n"
	    << "proc = numver of processes\n";
}


int main(int argc, char ** argv) {
  if (argc != 3) {
    std::cout << "Error: wrong parameters.\n";
    Usage();
    return 0;
  }


  const unsigned N = atol(argv[1]);
  srand(time(NULL));
  int ** A, ** B, ** C;
  A = new int*[N];
  B = new int*[N];
  C = new int*[N];
  for (unsigned i = 0; i < N; ++i) {
    A[i] = new int[N];
    B[i] = new int[N];
    C[i] = new int[N];
    for (unsigned j = 0; j < N; ++j) {
      A[i][j] = rand() % 10;
    }
  }
  for (unsigned i = 0; i < N; ++i) {
    for (unsigned j = 0; j < N; ++j) {
      B[j][i] = rand() % 10;
    }
  }
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
*/


/// MAIN PART 1
  const unsigned count_threads = atol(argv[2]);
  std::thread * T = new std::thread[count_threads];
  std::queue<unsigned> free_threads; /// indexes of free threads
  for (unsigned i = 0; i < count_threads; ++i) {
    free_threads.push(i);
  }
  double work_time_1 = clock();
  for (unsigned i = 0; i < N; ++i) {
    std::cout << "New iteration : TID = ";
    unsigned min_free_proc_pos;

    // get first free proc
    while (1) {
      if (free_threads.empty() == false) {
        min_free_proc_pos = free_threads.front();
	free_threads.pop();
	std::cout << min_free_proc_pos << "\n";
	break;
      }
    }
    
    T[min_free_proc_pos] = std::thread(func, A[i], B, C[i], N, std::ref(free_threads), min_free_proc_pos);
  }
  for (unsigned i = 0; i < count_threads; ++i) {
    T[i].join();
  }
  work_time_1 = clock() - work_time_1 ;
  work_time_1 = (double) work_time_1 / CLOCKS_PER_SEC;
  std::cout << "With threads--> ";
  printf("%lf\n", work_time_1);
  delete [] T;


/// MAIN PART 2
  int ** D = new int*[N];
  for (unsigned i = 0; i < N; ++i) {
    D[i] = new int[N];
  }
  double work_time_2 = clock();
  for (unsigned i = 0; i < N; ++i) {
    for (unsigned j = 0; j < N; ++j) {
      D[i][j] = 0;
      for (unsigned k = 0; k < N; ++k) {
        D[i][j] += A[i][k] * B[j][k];
      }
    }
  }
  work_time_2 = clock() - work_time_2;
  work_time_2 = (double) work_time_2 / CLOCKS_PER_SEC;
  std::cout << "Usual algo  --> ";
  printf("%lf\n", work_time_2);


/// RESULT
  bool correct = true;
  //std::cout << "Matrix C : \n";
  for (unsigned i = 0; i < N; ++i) {
    for (unsigned j = 0; j < N; ++j) {
      //std::cout << C[i][j] << " ";
      if (C[i][j] != D[i][j]) {
        correct = false;
      }
    }
    //std::cout << "\n";
  }
  //std::cout << "\n";
  std::cout << std::boolalpha << correct << "\n";


/// FREE RESOURCES
  for (unsigned i = 0; i < N; ++i) {
    delete [] A[i];
    delete [] B[i];
    delete [] C[i];
    delete [] D[i];
  }
  delete [] A;
  delete [] B;
  delete [] C;
  delete [] D;
  return 0;
}
