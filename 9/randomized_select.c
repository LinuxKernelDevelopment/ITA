#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define	exchange(a, b, tmp) do { tmp = a; a = b; b = tmp; } while(0)

/*void quicksort(int *, int, int);*/
int partition(int *, int, int);
int randomized_partition(int *, int, int);
int randomized_select(int *, int, int, int);
/*void randomized_quicksort(int *, int, int);*/

/*void quicksort(int *A, int p, int r)
{
	int q;
	if (p < r) {
		q = partition(A, p, r);
		quicksort(A, p, q - 1);
		quicksort(A, q + 1, r);	
	}
}

void randomized_quicksort(int *A, int p, int r)
{
	int q;
	if (p < r) {
		q = randomized_partition(A, p, r);
		randomized_quicksort(A, p, q-1);
		randomized_quicksort(A, q+1, r);
	}
}*/

int partition(int *A, int p, int r)
{
	int x, i, j, tmp;
	x = A[r];
	i = p - 1;
	for (j = p; j < r; j++) {
		if (A[j] <= x) {
			i = i + 1;
			exchange(A[i], A[j], tmp);
		}
	}
	exchange(A[i + 1], A[r], tmp);
	return i + 1;
}

int randomized_partition(int *A, int p, int r)
{
	int i, tmp;
	srand((unsigned)time(NULL));
	i = rand() % (r - p) + p;
	exchange(A[i], A[r], tmp);
	return partition(A, p, r);
}

int randomized_select(int *A, int p, int r, int i)
{
	int q, k;
	if (p == r)
		return *(A + p);
	q = randomized_partition(A, p, r);
	k = q - p + 1;
	if (i == k)
		return *(A + q);
	else if (i < k)
		return randomized_select(A, p, q - 1, i);
	else
		return randomized_select(A, q + 1, r, i - k);
}

int
main(void)
{
	int i;
	int a[] = {13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11};
	printf("%d\n", randomized_select(a, 0, sizeof(a) / sizeof(int) - 1, 5));
	randomized_partition(a, 0, sizeof(a) / sizeof(int) - 1);
	for (i = 0; i < sizeof(a) / sizeof(int); i++)
		printf("%d\t", a[i]);
	printf("\n");
	/*int arr[] = {271, 812, 289, 819, 439, 812, 837, 934, 983, 283, 382, 348, 594};
	randomized_quicksort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	for (i = 0; i < sizeof(arr) / sizeof(int); i++) 
		printf("%d\t", arr[i]);
	printf("\n");*/
	return 0;
}
