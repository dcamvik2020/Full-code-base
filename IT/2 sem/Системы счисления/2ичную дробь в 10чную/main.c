#include <stdio.h>

int main()
{
    char s[31], flag = 0;
    double res = 0, k = 0.5;
    int i;
    scanf("%s", s);
    for (i = 0; s[i]; i++)
    {
        if (s[i] == '.')
        {
            flag = 1;
            continue;
        }
        if (flag)
        {
            res += (s[i] - '0') * k;
            k /= 2;
        }
        else
        {
            res = res * 2 + s[i] - '0';
        }
    }
    printf("%.12lf\n", res);
    return 0;
}
