#include <stdio.h>
#include <stdlib.h>

void square_matrix_add(int*, int*, int*, int);
void square_matrix_multiply(int*, int*, int);

int c[4][4] = { 0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int
main(int argc, char *argv[])
{
	int i, j;
	int a[4][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };
	int b[4][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };
	int n;
	int **c;
	c = malloc(sizeof(int *) * 4);
	for (i = 0; i < 4; i++)
		c[i] = malloc(sizeof(int) * 4);
	/*square_matrix_add(a, b, c, 4);
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			printf("%d\t", *((int *)c + i * 4 + j));*/
	square_matrix_multiply(a, b, 4);
	return 0;
}


void square_matrix_add(int* a1, int* b1, int *c, int num)
{
	int i, j;
	for (i = 0; i < num; i++)
		for (j = 0; j < num; j++)
			*(c + i * num + j) = *(a1 + i * num + j) + *(b1 + i * num + j);	
}

void debug_matrix(int *a, int num)
{
	int i = 0;
	for (i = 0; i < num * num / 4; i++)
		printf("%d\t", *(a + i));
	printf("\n");
}

int tmp[4][4];
void square_matrix_multiply(int *a1, int *b1, int num)
{
	int n = num, i, j;
	int *c = malloc(sizeof(int) * num * num);
	int *a11, *a12, *a21, *a22;
	if (n == 1)
		*c = *a1 * *b1;
	else {
		a11 = malloc(sizeof(int) * num * num / 4);
		a12 = malloc(sizeof(int) * num * num / 4);
		a21 = malloc(sizeof(int) * num * num / 4);
		a22 = malloc(sizeof(int) * num * num / 4);
		for (i = 0; i < num; i++)
			for (j = 0; j < num; j++)
			{
				if (i + 1 <= num / 2 && j + 1 <= num / 2) 
				{
					*(a11 + i * num / 2 + j) = *(a1 + i * num + j);
					printf("a11\ti:%d\tj:%d\n", i, j);
				}
				if (i + 1 <= num / 2 && j + 1 > num / 2) 
				{
					*(a12 + i * num / 2+ (j - num/2)) = *(a1 + i * num + j);
					printf("a12\ti:%d\tj:%d\n", i, j);
				}
				if (i + 1 > num / 2 && j + 1 <= num / 2) 
				{
					*(a21 + (i - num / 2) * num / 2 + j) = *(a1 + i * num + j);
					printf("a21\ti:%d\tj:%d\n", i, j);
				}
				if (i + 1 > num / 2 && j + 1 > num / 2) 
				{
					*(a22 + (i - num / 2) * num / 2 + (j - num / 2)) = *(a1 + i * num + j);
					printf("a22\ti:%d\tj:%d\n", i, j);
				}
			}

	}
	debug_matrix(a11, num);
	debug_matrix(a12, num);
	debug_matrix(a21, num);
	debug_matrix(a22, num);
}
