int printf (const char *format, ...);
int scanf (const char *format, ...) ;

int sum(int A[], int n);
void sort(int *, int);

int main(void)
{
	int i, m = 0, A[5];
	for (i = 0; i < 5; i++) {
		scanf("%d", &A[i]);
		m = ((m) > (((A[i]) > 0 ? (A[i]) : -(A[i]))) ? (m) : (((A[i]) > 0 ? (A[i]) : -(A[i]))));
	}
	printf("max = %d\nsum = %d\n", m, sum(A, 5));
	sort(A, sizeof A / sizeof A[0]);
	for (i = 0; i < 5; i++)
		printf("%d ", A[i]);
	printf("\n");
	return 0;
}
