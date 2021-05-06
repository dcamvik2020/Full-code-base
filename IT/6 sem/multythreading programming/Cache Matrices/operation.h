#include <queue>
#include <pthread>

/// B is transposed --> cache hit is better
void simpleMul(const int ** A, const int ** B, int ** C, const unsigned N) {
  for (unsigned i = 0; i < N; ++i) {
    for (unsigned j = 0; j < N; ++j) {
      C[i][j] = 0;
      for (unsigned k = 0; k < N; ++k) {
        C[i][j] += A[i][k] * B[j][k];
      }
    }
  }
}

void mul(const int ** A, const int ** B, int ** C, const unsigned N, const unsigned proc) {
  simpleMul(A, B, C, N);
}
