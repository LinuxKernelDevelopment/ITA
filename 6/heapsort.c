#include <stdio.h>

typedef struct heap {
	int *arr;
	int heap_size;
} HEAP;

#define PARENT(i)	i / 2
#define	LEFT(i)		2 * i
#define	RIGHT(i)	2 * i + 1
#define exchange(a, b, tmp) tmp = a; a = b; b = tmp;

void max_heapify(HEAP, int);
void build_max_heap(HEAP);

void 
max_heapify(HEAP A, int i)
{
    int l, r, largest, tmp;
    l = LEFT(i) + 1;
    r = RIGHT(i) + 1;

    if (l <= A.heap_size && A.arr[l] > A.arr[i])
        largest = l;
    else
	largest = i;

    if (r <= A.heap_size && A.arr[r] > A.arr[largest])
	largest = r;

    if (largest != i)
    {
        exchange(A.arr[i], A.arr[largest], tmp);
	max_heapify(A, largest);
    }
}

void 
build_max_heap(HEAP A)
{
    int i;
    for (i = A.heap_size / 2; i >= 0; i--)
        max_heapify(A, i);
}

HEAP heapsort(int *arr, int size)
{
    int i, tmp;
    HEAP A = { arr, size};
    build_max_heap(A);
    for (i = size; i >= 1; i--)
    {
        exchange(A.arr[0], A.arr[i], tmp);
	A.heap_size--;
	max_heapify(A, 0);
    }
    return A;
}

void
main(void)
{
    int i;
    int arr[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    HEAP A = heapsort(arr, sizeof(arr) / sizeof(int) - 1);
    for (i = 0; i < sizeof(arr) / sizeof(int); i++)
	printf("%d\t", A.arr[i]);
    printf("\n");

}
