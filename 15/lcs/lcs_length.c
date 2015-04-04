#include <stdio.h>
#include "lcs_length.h"

void
lcs_length(lcss X, lcss Y, int** b, int** c)
{
	printf("%s\n", X.arr);
	printf("%s\n", Y.arr);
	int m, n, i, j;

	m = X.length;
	n = Y.length;
	
	for (i = 0; i < m + 1; i++)
		c[i][0] = 0;
	for (j = 0; j < n + 1; j++)
		c[0][j] = 0;
	for (i = 1; i < m + 1; i++)
		for (j = 1; j < n + 1; j++)
			if (X.arr[i] == Y.arr[j]) {
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = RA;
			} else if (c[i-1][j] >= c[i][j-1]) {
				c[i][j] = c[i-1][j];
				b[i][j] = UA;
			} else {
				c[i][j] = c[i][j-1];
				b[i][j] = LA;
			}
}

void
print_lcs(int** b, lcss X, int i, int j)
{
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == RA) {
		print_lcs(b, X, i-1, j-1);
		printf("%c", X.arr[i]);
	} else if (b[i][j] == UA) {
		print_lcs(b, X, i - 1, j);
	}
	else
		print_lcs(b, X, i , j - 1);
}
