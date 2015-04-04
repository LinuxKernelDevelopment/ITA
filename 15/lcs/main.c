#define LCS
#include <stdio.h>
#include <stdlib.h>
#include "lcs_length.h"

int
main()
{
	lcss X, Y;
	int **b, **c, i, j;
	
	X.arr = malloc(sizeof(char) * 7);
	X.arr = "BDCABA";
	X.length = 6;
	Y.arr = malloc(sizeof(char) * 8);
	Y.arr = "ABCBDAB";
	Y.length = 7;
	b = malloc(sizeof(int *));
	c = malloc(sizeof(int *));
	for (i = 0; i < X.length + 1; i++) {
		b[i] = malloc(Y.length * sizeof(int));
		c[i] = malloc(Y.length * sizeof(int));
	}

	lcs_length(X, Y, b, c);
	print_lcs(b, X, X.length, Y.length);
	for (i = 0; i < X.length; i++)
	{
		printf("\n");
		for (j = 0; j < Y.length; j++)
		{
			printf("%d\t", b[i][j]);
		}
	}
	return 0;
}
	


