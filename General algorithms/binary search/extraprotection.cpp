/// Have : base (w * h meters) on Mars = N blocks , same sizes (a * b meters)
/// Know : each block may have extra protection (d meters)
///        blocks have / don't have extra protection simultaneously
///        with protection each block <---> (a + 2d)(b + 2d) meters^2
///        blocks are parallel for sides of base, same orientation
/// Need : (1 <= N, a, b, w, h <= 10^18) ---> max(d) = ?

#include <iostream>

int main ()
{       ////    1, 1, 1, 3, 3
  long long N, a, b, w, h;
  std::cin >> N >> a >> b >> w >> h;
  
  long long min_d = 0, max_d = std::min(w-a, h-b); /// max protection
  /// max protection ---> "right" binsearch
  while (min_d < max_d)
  {
    //std::cout << min_d << " " << max_d << "\n";
	long long mid_d = min_d + (max_d - min_d + 1) / 2;
    long long new_a = a + 2 * mid_d, new_b = b + 2 * mid_d;
	long long kx = w / new_a;
	long long ky = h / new_b;
	if (kx * ky >= N)
	  min_d = mid_d;
	else
	  max_d = mid_d - 1;
  }
  std::cout << min_d << "\n";
  return 0;
}
