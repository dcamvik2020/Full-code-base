/// idea : not move, but first miss zeros, and in second
///        round just put them where needed

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        const int val = 0;
        unsigned size = nums.size();
        if (size == 0) return ;

        unsigned pos = 0;
        for (unsigned i = 0; i < size; ++i)
        {
            if (nums[i] != val)
            {
                nums[pos] = nums[i];
                pos++;
            }
        }
        for (unsigned i = pos; i < size; ++i)
            nums[i] = val;
    }

};
