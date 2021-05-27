/// command line : cat /proc/cpuinfo | grep processor | wc -l

#include <iostream>
#include <thread> 

int main() {
  std::cout << "hardware concurrency : ";
  std::cout << std::thread::hardware_concurrency() << "\n";
  return 0;
}
