typedef unsigned int size_t;
typedef int (*__compar_fn_t) (const void *, const void *);
extern void qsort (void *base, size_t nmemb, size_t size, __compar_fn_t compar);

int sum(int A[], int n);
void sort(int *, int);
int sum(int A[], int n) {
 int i, s = 0;
 for (i = 0; i < n; i++)
  s += A[i];
 return s;
}
static int cmp(const void *p1, const void *p2) {
 return *(int *)p1 - *(int *)p2;
}
void sort(int A[], int n) {
 qsort(A, n, sizeof(int), cmp);
}
