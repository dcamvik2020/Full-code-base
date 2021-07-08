class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        unsigned size = nums.size();
        if (size == 0) return size;
        
        unsigned i = 0, j = size - 1;
        while (i < j)
        {
            while (i < j && nums[i] != val) ++i;
            while (i < j && nums[j] == val) --j;
            if (i < j) 
            {
                swap(nums[i++], nums[j--]);
            }
        }
        if (nums[i] == val) size = i;
        else size = i + 1;
        
        nums.resize(size);
        return size;
    }
};
