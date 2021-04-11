#include <stdio.h>
#include <stdlib.h>

///    Avengers and their base are under attack
///    positions of avengers in ...; in one position can be > 1 avenger
///    but 1 av. can be only in 1 position
///    at any base  -> 2 options: destroy base fully    or    divide it into 2 bases

#define min(a, b) ((a) > (b) ? (b) : (a))
int A, B, n, k;

int cmp (const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int bin_search(int *positions, int x)
{   /// we want to find max index: positions[index] < x
    /// (positions[l] <= x <= positions[r])   ||   (x < positions[0])   ||   (positions[k-1] < x)
    int l = 0 , r = k-1;
    if (positions[r] < x) return r+1;
    if (x < positions[0]) return -1;
    while (l < r - 1)
    {
        if (x <= positions[l + (r-l)/2]) r = l + (r-l)/2; /// l = (l+r)/2  ->   potential overflow ;  also we will check not mid, but (mid + 1)
        else l = l + (r-l)/2; /// r =(l+r)/2;  ->   potential overflow
    }
    if (positions[l] == x) return l;
    else return r;
}

int destoy_energy(int *positions, int left, int right)
{
    int mid = left + (right - left) / 2, x;  /// x = quantity of avengers from l to r
    int left_ind, right_ind;
    left_ind = bin_search(positions, left); /// max index: positions[index] < left
    right_ind = bin_search(positions, right);
    while (right_ind < k && positions[right_ind + 1] == right)
        right_ind++;                        /// min index: positions[index] > right
    x = right_ind - left_ind;
    if (positions[left_ind] != left && !x) return A;
    if (left == right) return B*x;
    return min(destoy_energy(positions, left, mid) + destoy_energy(positions, mid + 1, right) , B*x*(right - left + 1));
}

int main()
{   /// 2^n = length of base, k = quantity of avengers, A = cost of destroying any empty base
    /// B*k*(2*n) = ... not empty base (similar for smaller bases)
    int *positions = NULL, i = 0;//, x;
    scanf("%d %d %d %d", &n, &k, &A, &B);
    /// positions = (int*) calloc(1 << n, sizeof(int)); it will be better to keep only array of indexes, not quantity of all numbers from 1 to 1<<n
    positions = (int*) malloc(k * sizeof(int));
    for (; i < k; i++)
    {
        ///scanf("%d", &x);        we can keep much less numbers -> memory, but also it will be easier to count "k"
        ///positions[x-1]++;       we will use binary search in sorted "positions" -> k = index(right end) - index(left end)
        scanf("%d", &positions[i]);
    }
    qsort(positions, k, sizeof(int), cmp);
    printf("%d\n", destoy_energy(positions, 1, 1<<n));
    free(positions);
    return 0;
}
