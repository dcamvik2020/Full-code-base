/// Have : vector of distinct numbers
/// Need : all permutations in any order

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        while (1)
        {
            for (int a : nums) cout << a << " ";
            cout << "\n";
            
            int j = nums.size() - 1;
            while (j && nums[j-1] > nums[j]) j--;
            
            res.push_back(nums);
            if (j == 0) break;
            
            /* CORRECT ---> 40 ms
            int k;
            for (k = nums.size() - 1; k >= j; --k)
                if (nums[k] > nums[j-1])
                    break;
            swap(nums[j-1], nums[k]);
            sort(next(nums.begin(), j), nums.end());
            */
            
            /* CORRECT ---> 28 ms
            int k;
            for (k = nums.size() - 1; k >= j; --k)
                if (nums[k] > nums[j-1])
                    break;
            swap(nums[k], nums[j-1]);
            for ( ; k < nums.size() - 1 && nums[k] < nums[k+1] ; k++)
                swap(nums[k], nums[k+1]);
            for ( ; k > 0 && nums[k-1] < nums[k] ; k--)
                swap(nums[k], nums[k-1]);
            
            /// reverse tail of the vector
            int tail_len = nums.size() - j; 
            for (k = 0; k < tail_len / 2; ++k)
                swap(nums[j + k], nums[nums.size() - 1 - k]);
            */
        }
        return res;
    }
};


/*   a1  a2  a3  a4 ... an ---> next = ?
 *   get position j : (aj ... an) is descending
 *   if j == 0 --> it's last permutation, return
 *
 *   put at (j-1) first from the end x : x > a_(j-1)
 *   
 *   sort ascending tail
 *
 *   1 4 2 5 3 ---> next = 1 4 3 2 5
 *   1 6 2 5 4 3 ---> next = 1 6 3 2 4 5
 */
