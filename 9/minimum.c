#include <stdio.h>
#include <stdlib.h>

typedef struct Arr {
	int *arr;
	int *length;
} Array;

int minimum(Array);

int minimum(Array a)
{
	int min, i;
	min = a.arr[0];
	for (i = 1; i < *(a.length); i++)
		if (min > a.arr[i])
			min = a.arr[i];
	return min;
}

int
main(void)
{
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 19, -123};
	Array a;
	a.arr = array;
	a.length = malloc(sizeof(int));
	*(a.length) = sizeof(array) / sizeof(int);
	printf("%d\n", minimum(a));
	return 0;

}
