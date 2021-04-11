int gcd(int a, int b)
{
  while (b)
  {
    int c = a % b;
    a = b;
    b = c;        
  }
  return abs(a);
}

int gcd(int a, int b)
{
  while (a != b)
    if (a > b)
      a -= b;
    else
      b -= a;
  return a;
}
