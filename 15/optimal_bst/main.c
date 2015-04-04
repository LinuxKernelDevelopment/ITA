#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	float p[] = { 0, 0.15, 0.10, 0.05, 0.10, 0.20};
	float q[] = { 0.05, 0.10, 0.05, 0.05, 0.05, 0.10};
	int **e, **root, i, j;
	int n = sizeof(p) / sizeof(int) - 1;
	e = malloc(sizeof(int *) * (n + 1));
	for (i = 0; i <= n + 1; i++)
		e[i] = malloc(sizeof(int) * (n + 1));
	root = malloc (sizeof(int *) * (n + 1));
	for (i = 0; i <= n + 1; i++)
		root[i] = malloc(sizeof(int) * (n + 1));
	optimal_bst(p, q, n, e , root);
	for (i = 0; i < n + 1; i++)
	{
		printf("\n");
		for (j = 0; j < n + 1; j++)
			printf("%d\t", root[i][j]);
	}
	printf("\n");
	return 0;
}
