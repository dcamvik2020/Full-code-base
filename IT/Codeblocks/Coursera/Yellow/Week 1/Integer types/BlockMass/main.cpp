/// several objects with the same density, but
/// different sizes ----> count mass M of all

#include <iostream>

using namespace std;

int main()
{
    int N, R; /// quantity <= 10^5, density <= 100
    cin >> N >> R;
    ///vector<int> W(N), H(N), D(N); /// all <=10^4
    /// final mass <= M = 10^5 * 100 * 10^4
    ///                 * 10^4 * 10^4 = 10^19
    /// let's take uint64_t
    uint64_t M = 0;
    ///int w, h, d;
    uint64_t w, h, d;
    for (int i = 0; i < N; ++i) {
        ///cin >> W[i] >> H[i] >> D[i];
        cin >> w >> h >> d;

        /// w, h, d <= 10^4 --> whd <= 10^12
        /// 10^12 is not int... --> need to use
        /// w, h, d as uint64_t also
        /// or we can use static_cast<uint64_t>(w) * h * d;
        M += w * h * d;
    }
    M *= R;
    cout << M
     << endl;
    return 0;
}
