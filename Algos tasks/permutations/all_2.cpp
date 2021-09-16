/// Have : array with duplicates
/// Need : all distinct permutations in any order

/// CORRECT --> faster 94.82%, memory less 88.85%
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        map<int, int> num_cnt;
        for (int x : nums)
            num_cnt[x]++;
        
        /// quantity of permutations with same numbers
        int total_permut_cnt = factorial(nums.size());
        int extra_combinations = 1;
        for (auto p : num_cnt)
            extra_combinations *= factorial(p.second);
        int permut_with_repeats = total_permut_cnt / extra_combinations;
        
        /// get all permutations with repeats
        for (int i = 0; i < permut_with_repeats; ++i)
        {
            res.push_back(nums);
            nextPermutation(nums);
        }
        /// res.push_back(nums); the last = the smallest ...
        return res;
    }
  
    void nextPermutation(vector<int>& nums) {
        int j, k;
        
        for (j = nums.size() - 1; j > 0; --j)
            if (nums[j-1] < nums[j])
                break;
        
        //if (j == 0)
        //    return;
        if (j > 0)
        {
            for (k = nums.size() - 1; k >= j; --k)
                if (nums[j-1] < nums[k])
                    break;

            swap(nums[j-1], nums[k]);

            while (k < nums.size() - 1 && nums[k] < nums[k+1]) 
                swap(nums[k], nums[k+1]);
            while(k > j && nums[k-1] < nums[k])
                swap(nums[k-1], nums[k]);
        }
        int tail_len = nums.size() - j;
        for (k = 0; k < tail_len / 2; ++k)
            swap(nums[j+k], nums[nums.size()-1-k]);
    }

    int factorial (int n)
    {
        if (n == 1) return 1;
        return n * factorial(n-1);
    }

};

