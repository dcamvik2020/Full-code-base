#include <stdio.h>
#include <stdlib.h>

char * const suit = "cshd";
char * const rank = "23456789TJQKA";

struct Card {
    char rank;    // достоинство
    char suit;    // масть
};

int check(struct Card * hand)
{
    struct Card * p;
    int i = 0, x = 0;
    int a[13] = {0};
    for (p = hand; p->rank != 0; p++)
    {
        if (p->rank == 'T')
        {
            a[8]++;
            continue;
        }
        if (p->rank == 'J')
        {
            a[9]++;
            continue;
        }
        if (p->rank == 'Q')
        {
            a[10]++;
            continue;
        }
        if (p->rank == 'K')
        {
            a[11]++;
            continue;
        }
        if (p->rank == 'A')
        {
            a[12]++;
            continue;
        }
        a[p->rank - '0' - 2]++;
    }
    return x;
}

int main()
{
    struct Card hand[] = {{'Q', 's'}, {'A','h'}, {'9', 'd'}, {0, 0}};
    struct Card * p;
    // напечатает QsAh9d
    for (p=hand; p->rank != 0; p++) {
        printf("%c%c", p->rank, p->suit);
    }
    printf("\n");
    // проверяем
    printf("%d\n", check(hand));
    return 0;
}
