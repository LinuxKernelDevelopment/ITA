#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void optimal_bst(float *p, float *q, int n, float e[7][7], int root[7][7])
{
	int w[7][7] = {0 };
	int i, l, j, r, t; 
	for (i = 1; i < n + 1; i++) {
		printf("%f\t%f\n", p[i], q[i - 1]);
		e[i][i - 1] = q[i];
		w[i][i - 1] = q[i - 1];
	}
	for (l = 1; l < n; l++)
		for (i = 1; i < n - l + 1; i++) {
			j = i + l - 1;
			e[i][j] = INT_MAX;
			w[i][j] = w[i][j - 1] + p[j] + q[j];
			for (r = i; r < j; r++) {
				t = e[i][r-1] + e[r+1][j] + w[i][j];
				if (t < e[i][j]) {
					e[i][j] = t;
					root[i][j] = r;
				}
			}
		}
}
