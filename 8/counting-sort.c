#include <stdio.h>
#include <stdlib.h>

void counting_sort(int *, int, int *, int);

void counting_sort(int *A, int Alength, int *B, int k)
{
	int *C;
	int i, j;
	C = malloc(sizeof(int) * (k + 1));
	for (i = 0; i < k; i++)
		C[i] = 0;
	for (j = 1; j <= Alength; j++)
		C[A[j]] = C[A[j]] + 1;

	for (i = 1; i < k; i++)
		C[i] = C[i] + C[i-1];

	for (j = Alength; j >= 1; j--) {
		B[C[A[j]]] = A[j];
		C[A[j]] = C[A[j]] - 1;
	}

}

int main(void)
{
	int A[] = { -1, 2, 5, 3, 0, 2, 3, 0, 3};
	int *B;
	B = malloc(sizeof(A));
	counting_sort(A, sizeof(A) / sizeof(int) - 1, B, 7);
	int i;
	for (i = 0; i < 9; i++)
		printf("%d\t", B[i]);
	printf("\n");
	return 0;
}
