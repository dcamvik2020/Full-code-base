/// Have : vector of numbers (not always distinct)
/// Need : next permutation in lexicographical order
///        (for the biggest the next is the smallest one)

/// COORECT : faster 79.61%, memory less 33.65%
class Solution {
public:
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
};
