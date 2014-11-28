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
	square_matrix_multiply((int *)a, (int *)b, 4, (int *)c);
	debug_matrix((int *)c, 4);
	return 0;
}


void square_matrix_add(int* a1, int* b1, int *c, int num)
{
	int i, j;
	for (i = 0; i < num; i++)
		for (j = 0; j < num; j++)
			*(c + i * num + j) = *(a1 + i * num + j) + *(b1 + i * num + j);	
}

void square_matrix_sub(int *a, int *b, int *c, int num)
{
	int i, j;
	for (i = 0; i < num; i++)
		for (j = 0; j < num; j++)
			*(c + i * num + j) = *(a + i * num + j) - *(b + i * num + j);
}

void debug_matrix(int *a, int num)
{
	int i = 0;
	for (i = 0; i < num * num; i++)
	{
		if (i % num == 0) printf("\n");
		printf("%d\t", *(a + i));
	}
	printf("\n");
}

int tmp[4][4];
void square_matrix_multiply(int *a1, int *b1, int num, int *c)
{
	int n = num, i, j;
	int *a11, *a12, *a21, *a22;
	int *b11, *b12, *b21, *b22;
	int *c11, *c12, *c21, *c22;
	int *c5a4, *c5a4s2, *c5a1, *c5a1s3;
	int *s[10];
	int *p[7];
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
				}
				if (i + 1 <= num / 2 && j + 1 > num / 2) 
				{
					*(a12 + i * num / 2+ (j - num/2)) = *(a1 + i * num + j);
					*(b12 + i * num / 2+ (j - num/2)) = *(b1 + i * num + j);
				}
				if (i + 1 > num / 2 && j + 1 <= num / 2) 
				{
					*(a21 + (i - num / 2) * num / 2 + j) = *(a1 + i * num + j);
					*(b21 + (i - num / 2) * num / 2 + j) = *(b1 + i * num + j);
				}
				if (i + 1 > num / 2 && j + 1 > num / 2) 
				{
					*(a22 + (i - num / 2) * num / 2 + (j - num / 2)) = *(a1 + i * num + j);
					*(b22 + (i - num / 2) * num / 2 + (j - num / 2)) = *(b1 + i * num + j);
				}
			}
		}

		for (i = 0; i < 10; i++)
			s[i] = malloc(sizeof(int) * (num / 2) * (num / 2));
		square_matrix_sub(b12, b22, s[0], num / 2);
		square_matrix_add(a11, a12, s[1], num / 2);
		square_matrix_add(a21, a22, s[2], num / 2);
		square_matrix_sub(b21, b11, s[3], num / 2);
		square_matrix_add(a11, a22, s[4], num / 2);
		square_matrix_add(b11, b22, s[5], num / 2);
		square_matrix_sub(a12, a22, s[6], num / 2);
		square_matrix_add(b21, b22, s[7], num / 2);
		square_matrix_sub(a11, a21, s[8], num / 2);
		square_matrix_add(b11, b12, s[9], num / 2);

		for (i = 0; i < 7; i++)
			p[i] = malloc(sizeof(int) * (num / 2) * (num / 2));
		square_matrix_multiply(a11, s[0], num / 2, p[0]);
		square_matrix_multiply(s[1], b22, num / 2, p[1]);
		square_matrix_multiply(s[2], b11, num / 2, p[2]);		
		square_matrix_multiply(a22, s[3], num / 2, p[3]);
		square_matrix_multiply(s[4], s[5], num / 2, p[4]);
		square_matrix_multiply(s[6], s[7], num / 2, p[5]);
		square_matrix_multiply(s[8], s[9], num / 2, p[6]);


		c11 = malloc(sizeof(int) * (num / 2) * (num / 2));
		//computation C11
		c5a4 = malloc(sizeof(int) * (num / 2) * (num / 2));
		c5a4s2 = malloc(sizeof(int) * (num / 2) * (num / 2));
		square_matrix_add(p[4], p[3], c5a4, num / 2);
		square_matrix_sub(c5a4, p[1], c5a4s2, num / 2);
		square_matrix_add(c5a4s2, p[5], c11, num / 2);
				
                c12 = malloc(sizeof(int) * (num / 2) * (num / 2));	
		//computation C12
		square_matrix_add(p[0], p[1], c12, num / 2);
				
		c21 = malloc(sizeof(int) * (num / 2) * (num / 2));
		//computation C21
		square_matrix_add(p[2], p[3], c21, num / 2);

		c22 = malloc(sizeof(int) * (num / 2) * (num / 2));
		//computation C22
		c5a1 = malloc(sizeof(int) * (num / 2) * (num / 2));
		c5a1s3 = malloc(sizeof(int) * (num / 2) * (num / 2));
		square_matrix_add(p[4], p[0], c5a1, num / 2);
		square_matrix_sub(c5a1, p[2], c5a1s3, num / 2);
		square_matrix_sub(c5a1s3, p[6], c22, num / 2);
		
		for (i = 0; i < num; i++)
			for (j = 0; j < num; j++)
			{
				if (i + 1 <= num / 2 && j + 1 <= num / 2)  *(c + i * num + j) = *(c11 + i * num / 2 + j);
				if (i + 1 <= num / 2 && j + 1 > num / 2)  *(c + i * num + j) = *(c12 + i * num / 2 + (j - num / 2));
				if (i + 1 > num / 2 && j + 1 <= num / 2)  *(c + i * num + j) = *(c21 + (i - num/2) * num / 2 + j);
				if (i + 1 > num / 2 && j + 1 > num / 2)  *(c + i * num + j) = *(c22 + (i - num/2) * num / 2 + (j - num/2));
			}
	}
}
