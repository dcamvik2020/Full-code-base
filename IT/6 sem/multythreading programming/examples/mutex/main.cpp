#include <iostream>
#include <fstream>
#include <vector>
#include <mutex>
#include <thread>

std::vector<int> v1, v2;
std::mutex mtx;

void f1 (const unsigned N, bool first) {
  std::lock_guard<std::mutex> lg(mtx);
  for (unsigned i = 0; i < N; ++i) {
    v1.push_back(2 * i + first);
  }
}

void f2 (const unsigned N, bool first) {
  for (unsigned i = 0; i < N; ++i) {
    v2.push_back(2 * i + first);
  }
}

void print(std::ostream & os, const std::vector<int> & v) {
  for (unsigned i = 0, cycle = 0; i < v.size(); ++i, ++cycle) {
    os << v[i] << " ";
    if (cycle == 15) {
      os << "\n";
      cycle = 0;
    }
  }
  os << "\n";
}

int main(int argc, char ** argv) {
  if (argc < 2) {
    std::cout << "Too few arguments.\n";
    return 0;
  }
  const unsigned N = atoi(argv[1]);
  
  /// with lock_guard
  std::thread t1(f1, N, true);
  std::thread t2(f1, N, false);
  t1.join();
  t2.join();
  std::ofstream out1;
  out1.open("output1.txt", std::ios::out | std::ios::trunc);
  if (!out1) {
    std::cout << "error with out1\n";
    return 0;
  }
  print(out1, v1);

  /// withOUT lock_guard
  std::thread t3(f2, N, true);
  std::thread t4(f2, N, false);
  t3.join();
  t4.join();
  std::ofstream out2;
  out2.open("output2.txt", std::ios::out | std::ios::trunc);
  if (!out2) {
    std::cout << "error with out2\n";
    return 0;
  }
  print(out2, v2);

  return 0;
}
