#include <stdio.h>
#include <stdlib.h>

void debug_matrix(int *, int);
void square_matrix_add(int*, int*, int*, int);
void square_matrix_multiply(int*, int*, int, int *);

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
	square_matrix_multiply(a, b, 4, c);
	debug_matrix(c, 4);
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
	for (i = 0; i < num * num; i++)
		printf("%d\t", *(a + i));
	printf("\n");
}

int tmp[4][4];
void square_matrix_multiply(int *a1, int *b1, int num, int *c)
{
	debug_matrix(a1, num);
	debug_matrix(b1, num);
	int n = num, i, j;
	int *a11, *a12, *a21, *a22;
	int *b11, *b12, *b21, *b22;
	int *c11, *c12, *c21, *c22;
	int *c11a, *c11b, *c12a, *c12b, *c21a, *c21b, *c22a, *c22b;
	if (n == 1)
		*c = *a1 * *b1;
	else {
		a11 = malloc(sizeof(int) * num * num / 4);
		a12 = malloc(sizeof(int) * num * num / 4);
		a21 = malloc(sizeof(int) * num * num / 4);
		a22 = malloc(sizeof(int) * num * num / 4);
		b11 = malloc(sizeof(int) * num * num / 4);
                b12 = malloc(sizeof(int) * num * num / 4);
                b21 = malloc(sizeof(int) * num * num / 4);
                b22 = malloc(sizeof(int) * num * num / 4);
		for (i = 0; i < num; i++) {
			for (j = 0; j < num; j++)
			{
				if (i + 1 <= num / 2 && j + 1 <= num / 2) 
				{
					*(a11 + i * num / 2 + j) = *(a1 + i * num + j);
					 *(b11 + i * num / 2 + j) = *(b1 + i * num + j);
					printf("a11\ti:%d\tj:%d\n", i, j);
				}
				if (i + 1 <= num / 2 && j + 1 > num / 2) 
				{
					*(a12 + i * num / 2+ (j - num/2)) = *(a1 + i * num + j);
					*(b12 + i * num / 2+ (j - num/2)) = *(b1 + i * num + j);
					printf("a12\ti:%d\tj:%d\n", i, j);
				}
				if (i + 1 > num / 2 && j + 1 <= num / 2) 
				{
					*(a21 + (i - num / 2) * num / 2 + j) = *(a1 + i * num + j);
					*(b21 + (i - num / 2) * num / 2 + j) = *(b1 + i * num + j);
					printf("a21\ti:%d\tj:%d\n", i, j);
				}
				if (i + 1 > num / 2 && j + 1 > num / 2) 
				{
					*(a22 + (i - num / 2) * num / 2 + (j - num / 2)) = *(a1 + i * num + j);
					*(b22 + (i - num / 2) * num / 2 + (j - num / 2)) = *(b1 + i * num + j);
					printf("a22\ti:%d\tj:%d\n", i, j);
				}
			}
		}

		printf("haha\n");			
		c11a = malloc(sizeof(int) * (num / 2) * (num / 2));
		c11b = malloc(sizeof(int) * (num / 2) * (num / 2));
		c11 = malloc(sizeof(int) * (num / 2) * (num / 2));
		//computation C11
		square_matrix_multiply(a11, b11, num / 2, c11a);
		square_matrix_multiply(a12, b21, num / 2, c11b);
		square_matrix_add(c11a, c11b, c11, num / 2);
				
		c12a = malloc(sizeof(int) * (num / 2) * (num / 2));
                c12b = malloc(sizeof(int) * (num / 2) * (num / 2));
                c12 = malloc(sizeof(int) * (num / 2) * (num / 2));	
		//computation C12
		square_matrix_multiply(a11, b12, num / 2, c12a);                                                       
		square_matrix_multiply(a12, b22, num / 2, c12b);                                                       
		square_matrix_add(c12a, c12b, c12, num / 2);			
				
		c21a = malloc(sizeof(int) * (num / 2) * (num / 2));
		c21b = malloc(sizeof(int) * (num / 2) * (num / 2));
		c21 = malloc(sizeof(int) * (num / 2) * (num / 2));
		//computation C21
		square_matrix_multiply(a21, b11, num / 2, c21a);                                                       
		square_matrix_multiply(a22, b21, num / 2, c21b);                                                       
		square_matrix_add(c21a, c21b, c21, num / 2);

		c22a = malloc(sizeof(int) * (num / 2) * (num / 2));
		c22b = malloc(sizeof(int) * (num / 2) * (num / 2));
		c22 = malloc(sizeof(int) * (num / 2) * (num / 2));
		//computation C22
		square_matrix_multiply(a21, b12, num / 2, c22a);                                                       
		square_matrix_multiply(a12, b22, num / 2, c22b);                                                       
		square_matrix_add(c22a, c22b, c22, num / 2);
	}
			
	debug_matrix(c, num);
	
	/*debug_matrix(a11, num);
	debug_matrix(a12, num);
	debug_matrix(a21, num);
	debug_matrix(a22, num);*/
}
