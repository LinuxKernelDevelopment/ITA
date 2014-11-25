#include <stdio.h>

int arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};

typedef struct sub_arr {
	int low;
	int high;
} mark;

mark find_maximum_array(int[], int, int);

int
main(int argc, char *argv[])
{
	mark result = {0, 0};
	result = find_maximum_array(arr, 0, sizeof(arr)/sizeof(int));
	printf("The lowest of maximum is %d\t, the highest of maximum is %d\n", result.low, result.high);
	return 0;
}

mark find_maximum_array(int arr[], int low, int high)
{
	int i, j;
	mark result;
	int max = 0, tmp = 0, max_left = 0, max_right = 0;
	max = arr[0]; tmp = arr[0];
	for (i = low; i < high; i++) {
	   tmp = arr[i];
	   for (j = i+1; j <= high; j++) {
		tmp = tmp + arr[j];
		if (tmp > max) {
		   max_left = i;
		   max_right = j;
		   max = tmp;
		}
	   }
        }
	result.low = max_left;
	result.high = max_right;
	return result;	
}
