#include <iostream>

unsigned long long cntSequences(unsigned long long n);

int main ()
{
  unsigned long long n; /// n pairs of brackets
  std::cin >> n;

  std::cout << "Correct parenthesis sequances "
            << "with n pairs of brackets : "
			<< cntSequences(n) << "\n";
  return 0;
}


unsigned long long cntSequences(unsigned long long n)
{
  if (n <= 1) return 1;
  unsigned long long cnt = 0;
  for (unsigned long long k = 0; k < n; ++k)
  {
    unsigned long long left = cntSequences(k);
	unsigned long long right = cntSequences(n - 1 - k);
	cnt += left * right;
  }
  return cnt;
}
