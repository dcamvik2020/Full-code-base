#include <stdio.h>

///knapsack, but we have to search the set of items with max quantity
///so, if we have 2 sets with 2 and 3 items(giving the same profit)
///we choose THE SECOND(3 ITEMS)

#define max(a, b) (((a) > (b)) ? (a) : (b))

int P, N, i = 0, j = 0, weight = 0, var = 0;
int w[1000], v[1000], answ[1000], A[1000][1000];

void print(unsigned char choice)
{
    int i = 1;
    for (; i <= N; i++)
    {
        if (answ[i])
        {
            switch(choice)
            {
                case 1:
                    printf("%d ", i);
                    break;
                case 2:
                    printf("%d ", w[i]);
                    weight += w[i];
                    break;
                case 3:
                    printf("%d ", v[i]);
                    var += v[i];
                    break;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &P, &N);
    ///input, initial data
    for (i = 1; i <= N; i++)
    {
        scanf("%d %d", &w[i], &v[i]);
        answ[i] = 0;
    }
    for (i = 0; i <= N; i++)
    {
        A[i][0] = 0;
    }
    for (j = 0; j <= P; j++)
    {
        A[0][j] = 0;
    }
    ///filling the table
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= P; j++)
        {
            A[i][j] = (j >= w[i]) ? (max(A[i - 1][j], A[i - 1][j - w[i]] + v[i])) : (A[i - 1][j]);
        }
    }
    i--;
    j--;
    ///searching the answer
    for (; i > 0 && j > 0; i--) /// it's important to decrease i at every iteration -> for(; ; i--)
    {
        if (A[i][j] == A[i - 1][j]) /// we "go" in table "up" while we have an opportunity to choose from less set of items than initial
            continue;
        ///if (A[i][j] == A[i - 1][j - w[i]] + v[i])
        answ[i] = 1;
        j -= w[i];
    }
    puts("");
    ///output
    print(1);
    puts("");
    print(2);
    printf("%d\n", weight);
    print(3);
    printf("%d\n", var);
    return 0;
}
