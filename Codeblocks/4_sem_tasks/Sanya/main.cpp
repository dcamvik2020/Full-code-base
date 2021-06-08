#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

vector<int> input;
int cmp(const void *a, const void *b) {
    return input[*(int *)a] - input[*(int *)b];
}

int main() {
    int N, x;
    int counter = 0;
    int max_left = -1, min_right;
    vector<int> output_min, output_max;

    cin >> N;
    min_right = N + 1;
    int* sorted = new int[N];
    int* sorted2 = new int[N];

    for (int i = 0; i < N; ++i) {
        cin >> x;
        input.push_back(x);
        sorted[i] = i;
    }

    qsort(sorted, N, sizeof(int), cmp);
    for (int i = 0; i < N; ++i) {
        int j;
        for (j = 0; sorted[j] != i; j++);
        sorted2[i] = j;
    }

    for (int i = 0; i < N; ++i) {
        cout << i << "    " << input[i] << "    ";
        cout << sorted[i] << "    " << sorted[i] << "    " << endl;
        if (input[i] <= min_right && input[i] >= max_left) {
            if (sorted2[i] > (N-1) / 2) {
                output_max.push_back(input[i]);
                min_right = input[i];
            } else {
                output_min.push_back(input[i]);
                max_left = input[i];
            }
            ++counter;
        }
    }

    cout << counter << endl;

    delete [] sorted;
    delete [] sorted2;
    return 0;
}
