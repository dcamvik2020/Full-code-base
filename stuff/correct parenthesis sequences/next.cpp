#include <iostream>


bool checkCorrectnessParenthesis(const std::string & seq);
std::string next(const std::string & seq);


int main ()
{
  std::string seq;
  std::cin >> seq;
  std::cout << next(seq) << "\n";
  return 0;
}


bool checkCorrectnessParenthesis(const std::string & seq)
{
  int counter = 0;
  for (const char & c : seq)
  {
    if (c == '(')
	  counter++;
	else if (c == ')')
	  counter--;
    else
	  return false;

	if (counter < 0)
	  return false;
  }
  return counter == 0;
}


std::string next(const std::string & seq)
{
  if (checkCorrectnessParenthesis(seq) == false)
    return "Error : input string isn't correct brackets sequence!";
  
  int balance = 0;
  unsigned pos;
  for (pos = seq.size() - 1; pos > 0; --pos)
  {
    if (seq[pos] == ')') balance++;
	else 
	if (seq[pos] == '(') 
	{
	  balance--;
      if (balance > 0) break;
	}
  }
  
  if (pos == 0) /// <---> seq[pos] = seq[0] = '('
    return "The sequence is the last in lexicographical order!";
  
  std::string next = seq;
  unsigned brackets_rest = next.size() - pos - 1;
  next[pos] = ')';
  pos++;
  for (unsigned i = 0; i < brackets_rest / 2; ++i)
  {
    next[pos + i] = '(';
    next[next.size() - 1 - i] = ')';
  }
  next[pos + brackets_rest / 2] = ')';
  
  if (checkCorrectnessParenthesis(next) == false)
    return "Error : next aequence was found wrong!";
  return next;
}
