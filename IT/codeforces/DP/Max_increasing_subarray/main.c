#include <stdio.h>
#include <stdlib.h>

/// We have an array. Sub-array = sequence of consecutive (подряд идущие) elements
/// We need to find the length of the longest INCREASING sub-array

unsigned max_inc_sub_arr(unsigned *a, unsigned n)
{
    unsigned max_len = 1, i = 0, len = 1;
    for (; i < n - 1; i++)
    {
        while (a[i] < a[i+1] && i < n - 1)
        {
            i++;
            len++;
        }
        if (len > max_len)
        {
            max_len = len;
        }
        len = 1;
    }
    return max_len;
}

int main()
{
    unsigned *a, n, i = 0;
    scanf("%d", &n);
    a = (unsigned*) malloc(n*sizeof(unsigned));
    for (; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("%d\n", max_inc_sub_arr(a, n));
    return 0;
}
