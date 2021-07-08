/*#include <iostream>

int main() {
	long long N;
    std::cin >> N;
	
    long long prev = - (1 << 33), cur;
    for (long long i = 0; i < N; ++i) {
		std::cin >> cur;
		if (cur != prev)
          std::cout << cur << "\n";
        prev = cur;
    }
    
	return 0;
}*/






#include <iostream>
#include <vector>

int main() {
	int N;
	std::cout << "OK1\n";
    std::cin >> N;
    
    std::cout << "OK2\n";
    std::vector<int> arr(N);
    
    std::cout << "OK3\n";
    for (int i = 0; i < N; ++i) {
		std::cin >> arr[i];
    }
    
    std::cout << "OK4\n";
    if (N)
    {
      if (N > 1)
      {
        for (int i = 0; i < N-1; ++i)
        {
          if (arr[i] != arr[i+1])
            std::cout << arr[i] << "\n";
        }
      }
      std::cout << arr[N-1] << "\n";    
    }
	return 0;
}





/*
#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int> & arr, int n)
{
    if (n <= 1)
        return n;
    int j = 0;
    for (int i = 0; i < n-1; i++)
        if (arr[i] != arr[i+1])
            arr[j++] = arr[i];

    arr[j++] = arr[n-1];
    return j;
}

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> arr(N);
    for (int i = 0; i < N; ++i)
      std::cin >> arr[i];
    N = removeDuplicates(arr, N);
    for (int i = 0; i < N; i++)
        std::cout << arr[i] << " ";
    return 0;
} 
*/
