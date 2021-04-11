#include <iostream>
#include <cstdlib>

using namespace std;

int cmp(const void *a, const void *b) {
    return *((int *) b) - *((int *) a);
}

int cmp2(const void *a, const void *b) {
    return *((int *) a) - *((int *) b);
}

int (& MaxArray(int (&a)[10], int (&b)[10]))[10] {
    //size = 10
    int suma = 0, sumb = 0, i = 0;
    for (i = 0; i < 10; i++) {
        suma += a[i];
        sumb += b[i];
    }
    qsort(a, 10, sizeof(int), cmp);
    qsort(b, 10, sizeof(int), cmp2);
    if (suma >= sumb) {
        return a;
    } else {
        return b;
    }
}

int main()
{
    int a[10] = {0,1,2,3,4,5,6,7,8,9},
        b[10] = {1,2,3,4,5,6,7,8,9,10};
    for (int i = 0; i < 10; i++) {
        a[i] = i;
        b[i] = i+1;
    }
    int (&d)[10] = MaxArray(a, b);

    int (&c)[10] = MaxArray(a, b);
    MaxArray(a, b)[9] = -10;

    for (int i = 0; i < 10; i++) cout << c[i] << " ";
    cout << endl;

    delete []a;
    delete []b;

    return 0;
}
