#include <stdio.h>

void square_matrix_multiply(int (*)[4], int (*)[4]);

int c[4][4] = { 0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int
main(int argc, char *argv[])
{
	int i, j;
	int a[4][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };
	int b[4][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };
	int n;
	square_matrix_multiply(a, b);
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			printf("%d\n", c[i][j]);
	return 0;
}

void square_matrix_multiply(int (*a1)[4], int (*b1)[4])
{
	int n, i, j, k;
	n = sizeof(*a1) / sizeof(**a1);
	printf("%d\n", n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			c[i][j] = 0;
			for (k = 0; k < n; k++) {
				c[i][j]  = c[i][j] + a1[i][k] * b1[k][j];
				printf("c[%d][%d]:%d\n", i, j, c[i][j]);
			}
		}
}
