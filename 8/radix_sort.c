#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void RADIX_SORT(int *, int, int);
void insertion_sort(int *, int *, int);

void insertion_sort(int *A, int *tmp, int len)
{
	int i, j, ex, key;
	for (j = 1; j < len; j++) {
		key = tmp[j];
		ex = A[j];
		i = j - 1;
		while (i >= 0 && tmp[i] > key) {
			A[i + 1] = A[i];
			tmp[i + 1] = tmp[i];
			i = i - 1;
		}
		A[i + 1] = ex; 
		tmp[i + 1] = key;
	}
}

void RADIX_SORT(int *A, int len, int d)
{
	int *tmp;
	int i, j, k;
	tmp = malloc(sizeof(int) * len);
	for (i = 1; i <= d; i++) {
		for (k = 0; k < len; k++) printf("%d\t", A[k]);
		printf("\n");
		for (j = 0; j < len; j++) {
			tmp[j] = (int) A[j] % (int)pow(10, i) / (int)pow(10, i - 1);
			//printf("%d\t", tmp[j]);
			
		}
		printf("\n");
		insertion_sort(A, tmp, len);
	}
}

int
main(void)
{
	int i;
	int A[] = { 329, 457, 657, 839, 436, 720, 355};
	RADIX_SORT(A, 7, 3);
	for (i = 0; i < 7; i++) printf("%d\t", A[i]);
	printf("\n");
	return 0;
}
