/// Have : strings a, b
/// Need : return binary sum as a string


class Solution {
public:
    string addBinary(string a, string b) {
        unsigned i;
        unsigned max_size = max(a.size(), b.size()) + 1;
        string sum(max_size, '0');
        bool over = 0;
        
        for (i = 0; i < max_size; ++i) 
        {
            unsigned id_a = a.size() - 1 - i;
            unsigned id_b = b.size() - 1 - i;
            if (i == max_size - 1)
            {
                sum[i] = over + '0';
            }
            else
            if (i >= a.size()) 
            {
                sum[i] = (b[id_b] - '0' + over) % 2 + '0';
                over = (b[id_b] - '0' + over) / 2;
            }
            else
            if (i >= b.size())
            {
                sum[i] = (a[id_a] - '0' + over) % 2 + '0';
                over = (a[id_a] - '0' + over) / 2;
            }
            else
            {
                sum[i] = (a[id_a] - '0' + b[id_b] - '0' + over) % 2+'0';
                over = (a[id_a] - '0' + b[id_b] - '0' + over) / 2;
            }
        }
        cout << sum << "\n";
        
        for (i = sum.size() - 1 ; i && sum[i] == '0'; --i);
        ++i; // i = # of meanful digits now
        sum.resize(i);
        
        for (i = 0; i < sum.size() / 2; ++i)
        {
            char tmp = sum[i];
            sum[i] = sum[sum.size() - 1 - i];
            sum[sum.size() - 1 - i] = tmp;
        }
        
        return sum;
    }
};
