#include <stdio.h>

#define N 102401

int j = 0;
char s0[N];

void push(char a)
{
    s0[j] = a;
    j++;
}

char pop()
{
    if (j == 0)
        return 0;
    j--;
    return s0[j];
}

int main()
{
    char s[N], c;
    int i;
    scanf("%s", s);
    for (i = 0; s[i]; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[' || s[i] == '<')
        {
            push(s[i]);
        }
        else
        {
            c = pop();
            if (!((s[i] == ')' && c == '(') ||
                (s[i] == ']' && c == '[') ||
                (s[i] == '}' && c == '{') ||
                (s[i] == '>' && c == '<')))
            {
                puts("NO");
                return 0;
            }
        }
    }
    if (j == 0)
        puts("YES");
    else
        puts("NO");
    return 0;
}
