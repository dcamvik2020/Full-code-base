#include <iostream>

#define eps 1e-6
#define isNull(x) (-eps < (x) && (x) < eps)

int main()
{
  double a, b, c, d, e, f;
  std::cin >> a >> b >> c >> d >> e >> f;
  double d0 = a * d - b * c;
  double d1 = e * d - b * f;
  double d2 = a * f - e * c;

  if (!isNull(d0))
  {
    std::cout << "2 " << d1 / d0 << " " << d2 / d0 << "\n";
  } 
  else 
  {
    if (!isNull(d1) or !isNull(d2))
	{
        std::cout << "0\n";
    }
	else
	{
      bool wrongEquation1 = isNull(a) && isNull(b) && !isNull(e);
      bool wrongEquation2 = isNull(c) && isNull(d) && !isNull(f);
      bool allNull_1 = isNull(a) && isNull(b) && isNull(e);
      bool allNull_2 = isNull(c) && isNull(d) && isNull(f);
      if (wrongEquation1 || wrongEquation2)
	  {
        std::cout << "0\n";
      }
      else if (allNull_1 && allNull_2)
	  {
        std::cout << "5\n";
      }
      else
	  {
        if (allNull_1)
          a = c, b = d, e = f;
		  
        //  !! if we change a, b, e ---->
        // we need to change aNull, bNull
        if (isNull(b))
          std::cout << "3 " << e / a << "\n";
        else if (isNull(a))
          std::cout << "4 " << e / b << "\n";
        else  // y = px + q
          std::cout << "1 " << -a/b << " " << e/b << "\n";
      }
    }
  }
  return 0;
}
