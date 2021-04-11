#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 30
void GenCoeff(vector<vector<int>> & c);
int C_n_k(int N, int K, const vector<vector<int>> & c);

int main() {
  int N, K;
  cin >> N >> K;
  vector<vector<int>> c(MAX_N, vector<int>(MAX_N, 0)); /// table of C_n_k
  GenCoeff(c);
  cout << C_n_k(N, K, c) << endl;
  return 0;
}

void GenCoeff(vector<vector<int>> & c) {
  for (int i = 0; i < MAX_N; ++i) {
    c[0][i] = 0;
    c[i][0] = 1;
  }
  for (int n = 1; n < MAX_N; ++n) {
    for (int k = 1; k < MAX_N; ++k) {
      c[n][k] = c[n-1][k] + c[n-1][k-1];
    }
  }
/*
  for (int n = 1; n < MAX_N; ++n) {
    for (int k = 1; k < MAX_N; ++k) {
      cout << c[n][k] << " ";
    }
    cout << endl;
  }
*/


}

int C_n_k(int N, int K, const vector<vector<int>> & c) {
  return c[N][K];
}
