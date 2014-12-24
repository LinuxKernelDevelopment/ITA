#include <stdio.h>
#include <stdlib.h>

typedef struct heap {
	int *arr;
	int *heap_size;
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

    if (l <= *(A.heap_size) && A.arr[l] > A.arr[i])
        largest = l;
    else
	largest = i;

    if (r <= *(A.heap_size) && A.arr[r] > A.arr[largest])
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
    for (i = *(A.heap_size) / 2; i >= 0; i--)
        max_heapify(A, i);
}

int
heap_maximum(HEAP A)
{
    return A.arr[0];
}

int
heap_extract_max(HEAP A)
{
    int max;
    if (*(A.heap_size) < 1) {
        printf("heap underflow");
	return -1;
    }
    max = A.arr[0];
    A.arr[0] = A.arr[*(A.heap_size)];
    *(A.heap_size) = *(A.heap_size) - 1;
    max_heapify(A, 0);
    return max;
}

int
heap_increase_key(HEAP A, int i, int key)
{
    int tmp;
    if (key < A.arr[i]) {
	printf("new key is smaller than current key");
	return -1;
    }
    A.arr[i] = key;
    while (i >= 1 && A.arr[PARENT(i)] < A.arr[i])
    {
        exchange(A.arr[i], A.arr[PARENT(i)], tmp);
	i = PARENT(i);
    }
    return 0;
}

HEAP
max_heap_insert(HEAP A, int key)
{
    int i;
    *(A.heap_size) = *(A.heap_size) + 1;
    A.arr[*(A.heap_size)] = -1111111;
    heap_increase_key(A, *(A.heap_size), key);
    return A;
}

HEAP
heap_delete(HEAP A, int i)
{
    A.arr[i] = A.arr[*(A.heap_size)];
    *(A.heap_size) = *(A.heap_size) - 1;
    max_heapify(A, i);
    return A;
}


void
main(void)
{
    int i;
    int arr[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int *heap_size = malloc(sizeof(int));
    *heap_size = sizeof(arr) / sizeof(int) - 1;
    HEAP A = {arr, heap_size};
    build_max_heap(A);
    heap_increase_key(A, 8, 15);
    for (i = 0; i <= *(A.heap_size); i++)
	printf("%d\t", A.arr[i]);
    printf("\n%d\n", *(A.heap_size));
    heap_extract_max(A);
    printf("%d\n", *(A.heap_size));
    printf("\n");
    for (i = 0; i <= *(A.heap_size); i++)
	printf("%d\t", A.arr[i]);
    printf("\n");
    A = max_heap_insert(A, 16);
    printf("%d\n", *(A.heap_size));
    for (i = 0; i <= *(A.heap_size); i++)
	printf("%d\t", A.arr[i]);
    printf("\n");
    A = heap_delete(A, 3);
    for (i = 0; i <= *(A.heap_size); i++)
	printf("%d\t", A.arr[i]);
    printf("\n");
}
