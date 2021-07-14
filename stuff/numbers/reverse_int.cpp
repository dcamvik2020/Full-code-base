/// if reversed ---> integer overloop --> return 0;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x)
        {
            if (res > INT_MAX / 10 || res < INT_MIN / 10 ||
                (res > 0 && x % 10 > INT_MAX - res * 10) || 
                (res < 0 && x % 10 < INT_MIN - res * 10))
            {
                cout << res << "\n";
                return 0;
            }
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};
