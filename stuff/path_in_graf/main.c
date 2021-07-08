#include <stdio.h>
#include <stdlib.h>

//int t = 0;
/*
int search_path (int a[][100], int N, int start, int finish)
{
    int i;
    if (a[start][finish])
        return 1;
    for (i = 0;i < N; i++)
    {
        if (a[start][i] && search_path(a, N, i, finish))
            return 1;
    }
    return 0;
}
*/




int main()
{
    int a[100][100], viwed[100] = {0};
    int N, i, j;
    int start, finish;
    int flag;///1 - connection exists
    {///input
        scanf("%d %d %d", &N, &start, &finish);
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                scanf("%d", &a[i][j]);
        //for (i = 0; i < N; i++)
        //    a[i][i] = 0;
    }




    viwed[start] = 1;
    while (1)
    {

    }





/*
    {///check
        flag = 0;
        if (a[start - 1][finish - 1])
        {
            puts("check_YES");
            return 0;
        }
        for (i = 0; i < N; i++)
            if (a[start - 1][i])
            {
                flag = 1;
                break;
            }
        if (!flag)
        {
            puts("1_check_NO");
            return 0;
        }

        flag = 0;
        for (i = 0; i < N; i++)
        {
            //printf("%d ", a[finish - 1][i]);
            if (a[finish - 1][i])
            {
                puts("here is a weak place");
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            puts("2_check_NO");
            return 0;
        }
    }
*/
    return 0;
}
