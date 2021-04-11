#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

int main()
{
    int N, num = 0; /// N <= 10^6, x(temperatures) <= 10^8
    int64_t sum = 0; /// 10^6 * 10^8 = 10^14 > 2^32 ---> int64_t
    cin >> N;
    if (N) {
        vector<int> temperatures(N);
        for (auto & x : temperatures) {
            cin >> x;
            sum += x;
        }
        sum /= N;
        for (const auto & x : temperatures) {
            if (x > sum) {
                ++num;
            }
        }
        cout << num << endl;
        for (int i = 0; i < N; ++i) {
            if (temperatures[i] > sum) {
                cout << i << " ";
            }
        }
    } else {
        cout << N;
    }
    cout << endl;
    return 0;
}
