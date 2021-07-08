class Solution {
public:
    /// low speed, low memory usage
	/// faster than 10%, memory less than 90% solutions (C++)
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for (unsigned i = 1; i < arr.size() - 1; ++i)
            if (arr[i] - arr[i-1] != arr[i+1] - arr[i])
                return false;
        return true;
    }

    
	/// faster 66,65% users and memory less than 5,65% users
	bool canMakeArithmeticProgression(vector<int>& arr) {

        /*
        sort(arr.begin(), arr.end());
        for (unsigned i = 1; i < arr.size() - 1; ++i)
            if (arr[i] - arr[i-1] != arr[i+1] - arr[i])
                return false;
        return true;
        */

        if (arr.size() == 0) return true;
        int min = arr[0], max = arr[0];
        unordered_map<int, int> cntNumbers;
        bool repeats = false;
        for (unsigned i = 0; i < arr.size(); ++i)
        {
            cntNumbers[arr[i]]++;
            if (cntNumbers[arr[i]] >= 2)
                repeats = true;

            if (arr[i] > max)
                max = arr[i];
            else if (arr[i] < min)
                min = arr[i];
        }
        if (repeats == true && cntNumbers.size() > 1)
            return false;

        if (max == min) return true;
        if ((max - min) % (arr.size() - 1) != 0) return false;
        int d = (max - min) / (arr.size() - 1);
        for (unsigned i = 1; i < arr.size(); ++i)
        {
            if ((arr[i] - arr[i-1]) % d != 0)
                return false;
        }
        return true;
    }
};
