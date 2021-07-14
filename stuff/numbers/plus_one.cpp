class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        /* CORRECT , but long
		vector<int> res = digits;
        
        if (res[res.size() - 1] < 9)
        {
            res[res.size() - 1]++;
            return res;
        }
        
        unsigned over = 1;
        for (unsigned i = digits.size() - 1; i < digits.size() && over; --i)
        {
            res[i] = (digits[i] + over) % 10;
            over = (digits[i] + over) / 10;
        }
        
        if (over)
        {
            res = vector(res.size() + 1, 0);
            res[0] = 1;
        }
        return res;*/
        
		/// correct ans short solution
        bool over = 1;
        for (int i = digits.size() - 1; i < digits.size() && over; --i)
        {
            int tmp = (digits[i] + over);
            digits[i] = tmp % 10;
            over = tmp / 10;
        }
        
        if (over == 1)
        {
            digits.resize(digits.size() + 1);
            digits[0] = 1;
        }
        
        return digits;
    }
};
