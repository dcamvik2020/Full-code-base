#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///Find the quantity of all "QAQ" in a string.
///The letters may be at any places. (QyAfQ   ->   1 "QAQ" exists)

int dp_search_QAQ(char *s, int n)
{
    int res = 0, quantity_q;   ///counter[i] = quantity of "A" between "Q" (s[last_q] and s[new_q]), a[i] is quantity of sub-consequences "QAQ"
    int a[100] = {0}, i, counter = 0, last_q;   ///in first i symbols, where the second "Q" is s[i]; so, if s[i] != 'Q', a[i]=0
    char *p = strchr(s, 'Q');                   ///"p" can be NULL -- absolute address of the first "Q"
    last_q = (p) ? ((int) p - (int) s) : (-2);  /// local address of the first "Q" (beginning from 0);
    if (last_q != -2)
    {
        quantity_q = 1; ///if last_q = -2, in "for(...)" we'll have i = -1 and cycle won't be completed
    }                   ///and there won't be UB-mistake
    for (i = last_q + 1; i < n && i != -1; i++)
    {
        if (s[i] != 'Q')
        {
            a[i] = 0;
            if (s[i] == 'A')
            {
                counter++;
            }
        }
        else
        {
            a[i] = counter * quantity_q + a[last_q]; /// difference consist only of "A" between all pairs of "Q" (last "Q" and all previous "Q")
            last_q = i;                              /// in a[last_q] we have quantity of "QAQ" where second "Q" = s[i], but "A" aren't between
            counter = 0;                             /// s[last_q] and s[i] (second "Q"), "A" are before s[last_q]
            res += a[i];
            quantity_q++;
        }
    }
    return res; ///result = sum(a[i]) from i=0 to i = n, since all a[i] tell us about different situations
}

int main()
{
    char s[101];
    scanf("%s", s);
    ///printf("%d\n", (int) strchr(s, 'Q') - (int) s); ///subtraction of two elements' adresses of one array is possible -> OK
    printf("%d\n", dp_search_QAQ(s, strlen(s)));
    return 0;
}
