#include <stdio.h>
#include <stdlib.h>

int bottom_up_cut_rod(int*, int);

int
main(void)
{
	int p[] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	int max;
	max = bottom_up_cut_rod(p, 12);
	printf("the max:%d\n", max);
	return 0;
}

#define max(a, b) (a > b ? a : b)

int bottom_up_cut_rod(int* p, int n)
{
	int *r, j, i, q;
	r = malloc(sizeof(int) * (n + 1));
	for (j = 1; j <= n; j++) {
		q = -32468;
		for (i = 1; i <= j; i++)
			q = max(q, p[i] + r[j - i]);
		r[j] = q;
	}
	return r[n];
}
