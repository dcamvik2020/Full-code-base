/// faster 55.15%, memory less 70.41%
/// know : 0 <= x <= 2^31 - 1

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while (l < r)
        {
            int m = l + (r-l)/2;
            if (m && m > INT_MAX / m || m * m >= x)
                r = m;
            else
                l = m + 1;
        }
        if (l && l > INT_MAX / l || l * l > x) l--;
        return l;
    }
};
