#include <stdio.h>
#include <stdlib.h>

int memoized_cut_rod(int*, int);

int
main(void)
{
	int p[] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	int max;
	max = memoized_cut_rod(p, 5);
	printf("the max:%d\n", max);
	return 0;
}

#define max(a, b) (a > b ? a : b)

int memoized_cut_rod_aux(int *p, int n, int *r)
{
	int q, i;
	if (r[n] >= 0)
		return r[n];
	if (n == 0)
		q = 0;
	else {
		q = -32468;
		for (i = 1; i <= n; i++)
			q = max(q, p[i] + memoized_cut_rod_aux(p, n - i, r));
		r[n] = q;
	}
	return q;
}

int memoized_cut_rod(int *p, int n)
{
	int i;
	int q = -32468;
	int *r;
	r = malloc(sizeof(int) * (n + 1));
	for (i = 0; i <= n; i++)
		r[i] = -32468;
	return memoized_cut_rod_aux(p, n, r);
}
