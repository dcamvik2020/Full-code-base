
//������� ����������� � +, -, *, /, ������ n-��� �������


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double calc (char *s)
{
    char *p = strrchr(s, '+'); // last '+'
    if (p)
    {
        *p = '\0';
        return calc(s) + calc(p+1);
    }
    p = strrchr(s, '-'); // last '-'
    if (p)
    {
        *p = '\0';
        return calc(s) - calc(p+1);
    }
    p = strrchr(s, '*'); // last '*'
    if (p)
    {
        *p = '\0';
        return calc(s) * calc(p+1);
    }
    p = strrchr(s, '/'); // last '/'
    if (p)
    {
        *p = '\0';
        return calc(s) / calc(p+1);
    }
    p = strrchr(s, '^'); // last '^'
    if (p)
    {
        *p = '\0';
        return pow(calc(s), calc(p+1));
    }
    p = strrchr(s, '#'); // last '#'
    if (p)
    {
        *p = '\0';
        if(&s[0] != p)
        {
            return pow(calc(p + 1), 1/calc(s));
        }
        else
        {
            return sqrt(calc(p+1));
        }
    }
    return atof(s);
}

int main()
{
    char s[1500];
    scanf("%s", s);
    printf("%lg\n", calc(s));
    return 0;
}
