#include <stdio.h>

int main(void) {
    FILE *f1 = NULL, *f2 = NULL;
    char s[1000];
    f1 = fopen("�� ����� ���� ���������.txt", "w");
    f2 = fopen("C:/users/Sony/Desktop/� ������ �� ����.txt", "r");
    if (!f1 || !f2)
    {
        puts("fuck");
    }
    else
    {
        while(fgets(s, 999, f2))
        {
            puts(s);
            fprintf(f1, "%s\n", s);
        }
    }
    fclose(f2);
    fclose(f1);
    ///________________________________________________________________
    /*f = fopen("0.txt", "a+t");
    if (!f)
    {
        puts("NO");
    }
    else
    {
        fprintf(f, "YES!");
    }
    fclose(f);*/
    ///________________________________________________________________
    /*
    f = fopen("C:/users/Sony/Desktop/� ������ �� ����.txt", "a");
    if (!f)
    {
        puts("NO");
    }
    else
    {
        fprintf(f, "DOUBLE YES!");
    }
    fclose(f);*/
    ///________________________________________________________________



    return 0;
}
