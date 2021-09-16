/// Have : n pairs of '(' and ')'
/// Know : n = 1 ---> ()
///        n = 2 ---> (()), ()()
///        n = 3 ---> ((())), (()()), ()(()), (())(), ()()()

#include <iostream>

void foo(std::string & stack, unsigned open, unsigned close, unsigned n);

int main ()
{
  unsigned n;
  std::cin >> n;
  std::string stack;
  foo (stack, 0, 0, n);
  return 0;
}

/// reference to stack ---> time decrease from 34ms to 12ms (3 times faster)
void foo(std::string & stack, unsigned open, unsigned close, unsigned n)
{
  if (stack.size() == 2 * n)
  {
	  std::cout << stack << "\n";
	  return;
  }

  if (open < n)
  {
    stack.push_back('(');
	foo (stack , open + 1, close, n);
    stack.pop_back();
  }

  if (close < open)
  {
    stack.push_back(')');
    foo (stack , open, close + 1, n);
	stack.pop_back();
  }
}
