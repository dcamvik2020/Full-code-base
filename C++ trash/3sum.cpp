#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums);

/// vector of int --> find all {i, j, k} : i != j, i != k, k != j
/// nums[i] + nums[j] + nums[k] == 0
int main() {
  unsigned N;
  std::cin >> N;
  std::vector<int> nums(N);
  for (unsigned i = 0; i < N; ++i) std::cin >> nums[i];
  threeSum(nums);
  
  std::cout << "size - 2 = " << nums.size() - 2 << "\n";
  
  return 0;
}

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
  if (nums.size() < 3) return std::vector<std::vector<int>>();
  
  std::cout << "Come here, boy!\n";
	
  std::set<std::vector<int>> res;
  for (unsigned i = 0; i < nums.size() - 2; ++i) {
    std::cout << "\tNew i iter\n";
    for (unsigned j = i + 1; j < nums.size() - 1; ++j) {
      std::cout << "\t\tNew j iter\n";
      for (unsigned k = j + 1; k < nums.size(); ++k) {
        std::cout << "\t\t\tNew k iter\n";
        if (nums[i] + nums[j] + nums[k] == 0) {
          std::vector<int> tmp{nums[i], nums[j], nums[k]};
          sort(tmp.begin(), tmp.end());
          res.insert(tmp);
        }
      }
    }
  }

  std::cout << "Oh yes, baby!\n";

  if (res.empty()) return std::vector<std::vector<int>>();
  return std::vector<std::vector<int>>(res.begin(), res.end());
}
