#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define abs(x) (((x) > 0) ? (x) : (-x))

int main()
{
    int N;
    cin >> N;

    vector<int> arr(N);
    for (auto& i: arr) {
        cin >> i;
    }

    sort(begin(arr), end(arr), [](int x, int y) {
                                    return (abs(x) < abs(y));
                                });

    for(auto& i : arr) {
        cout << i << " ";
    }

    cout << endl;
    return 0;
}
