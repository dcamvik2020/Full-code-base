#include "tools.h"

void Usage() {
  std::cout << "Usage : \n"
          << "\t./ex N proc (mode)\n\n"
          << "\tN = size of matrices\n"
          << "\tproc = numver of processes\n"
          << "\tmode = \"threads\", \"usual\", \"both\" or empty string\n";
}
