#include <stdio.h>

void matrix_chain_order(int *p, int pl, unsigned int *m, int *s)
{
	int i, j, l, k, q;
	int n = pl - 1;
	for (i = 1; i <= n; i++)
		*(m + i * 6 + i) = 0;
	for (l = 2; l <= n; l++)
		for (i = 1; i <= n-l+1; i++)
		{
			j = i + l - 1;
			*(m + i * 6 + j) = -1;
			for (k = i; k <= j-1; k++)
				q = *(m + i * 6 + k) + *(m + (k+1) * 6 + j) + p[i-1]*p[k]*p[j];
			if (q < *(m + i * 6 + j)) {
				*(m + i * 6 + j) = q;
				*(s + i * 6 + j) = k;
			}
		}
}

void print_optimal_parens(int *s, int i, int j)
{
	if (i == j)
		printf("A%d", i);
	else {
		printf("(");
		print_optimal_parens(s, i, *(s + (i - 1) * 6 + j));
		print_optimal_parens(s, *(s + (i - 1) * 6 + j) + 1, j);
		printf(")");
	}
}
