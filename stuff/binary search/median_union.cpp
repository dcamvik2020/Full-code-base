#include <iostream>
#include <vector>

/// a, b, are sorted weakly ascending
int getMedianUnion(unsigned N, const std::vector<int> & a,
                               const std::vector<int> & b)
{
  /// median of union = m <---> 
  /// (N-1) numbers < m, N numbers >= m
  /// take 2 medians of a, b --> compare
  unsigned l_a = 0, l_b = 0; /// [l_a, r_a)
  unsigned r_a = N, r_b = N;
  unsigned size = N;
  while (size > 1) 
  {
    /// a[mid_a] >= b[mid_b] ---- a[mid] >= b[i] \forall i <= mid_b
	///                           a[mid] >= a[i] \forall i < mid_a
	///                           a[mid] >= in total (1+mid_b)+ mid_a
	///                           elements in a[], b[]
    /// a[mid_a] >= b[mid_b] ---- a[mid] >= b[i] \forall i <= mid_b
	///                           a[mid] >= a[i] \forall i < mid_a
	///                           a[mid] >= in total (1+mid_b)+ mid_a
	///                           elements in a[], b[]
    
    if (size == 2)
	{
	  if (b[l_b + 1] <= a[l_a + 0])
	    return b[l_b + 1];
      if (a[l_a + 1] <= b[l_b + 0])
	    return a[l_a + 1];
	  if (a[l_a + 0] <= b[l_b + 0])
	    return b[l_b + 0];
	  return a[l_a + 0];
	}

    unsigned mid_a = (l_a + r_a) / 2;
    unsigned mid_b = (l_b + r_b) / 2;
    if (a[mid_a] == b[mid_b])
	  return a[mid_a];
    
	if (a[mid_a] > b[mid_b])
	{
	  if (size % 2 == 0)
        l_b = l_b + size / 2 - 1;
	  else
        l_b = l_b + size / 2;
	}
    else /// a[mid_a] < b[mid_b]
	{
	  if (size % 2 == 0)
        l_a = l_a + size / 2 - 1;
	  else
        l_a = l_a + size / 2;
	}

	if (size % 2 == 0)
	  size = size - size / 2 + 1;
	else
	  size = size - size / 2;
	std::cout << "mid_a = " << mid_a << "   "
	          << "mid_b = " << mid_b << "\n";
  }

  return std::min(a[l_a], b[l_b]);
}


int main ()
{
  unsigned N, L;
  std::cin >> N >> L;

  std::vector<std::vector<int>> vectors(N, std::vector<int>(L));
  for (unsigned i = 0; i < N; ++i)
  {
    for (unsigned j = 0; j < L; ++j)
      std::cin >> vectors[i][j];
  }

  for (unsigned i = 0; i < N; ++i)
  {
    for (unsigned j = i + 1; j < N; ++j)
      std::cout << getMedianUnion(L, vectors[i], vectors[j]) << "\n";
  }
  return 0; 
}
