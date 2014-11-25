#include <stdio.h>

int arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
int fake[] = {};

typedef struct sub_arr {
	int low;
	int high;
	int sum;
} mark;

mark find_max_crossing_subarray(int[], int, int, int);
mark find_maximum_subarray(int[], int, int);


int
main(int argc, char *argv[])
{
	mark result;
	result = find_maximum_subarray(fake, 0, sizeof(fake)/sizeof(int));
	printf("The lowest of maximum is %d\t, the highest of maximum is %d\n", result.low, result.high);
	return 0;
}

mark find_max_crossing_subarray(int arr[], int low, int mid, int high)
{
	int left, left_sum, right_sum, i, j, max_left, max_right, sum;
	left_sum = -1111;
	sum = 0;
	for (i = mid; i >= low; i--) {
		sum = sum + arr[i];
		if (sum > left_sum) {
			left_sum = sum;
			max_left = i;
		}
	}
	right_sum = -1111;
	sum = 0;
	for (j = mid + 1; j <=high; j++) {
		sum = sum + arr[j];
		if (sum > right_sum) {
			right_sum = sum;
			max_right = j;
		}
	}
	mark result;
	result.low = max_left;
	result.high = max_right;
	result.sum = left_sum + right_sum;
	return result;
}

mark find_maximum_subarray(int arr[], int low, int high)
{
	mark result, mark_left, mark_right, cross;
	int mid;
	if (arr == NULL) {
		result.low = 0;
		result.high = 0;
		result.sum = 0;
		return result;
	}
	if (high == low) {
		result.low = low;
		result.high = high;
		result.sum = arr[low];
		return result;
	} else {
		mid = (low + high) / 2;
		mark_left = find_maximum_subarray(arr, low, mid);
		mark_right = find_maximum_subarray(arr, mid+1, high);
		cross = find_max_crossing_subarray(arr, low, mid, high);
		if (mark_left.sum >= mark_right.sum && mark_left.sum >= cross.sum)
			return mark_left;
		else if (mark_right.sum >= mark_left.sum && mark_right.sum >= cross.sum)
			return mark_right;
		else
			return cross;
	}
	
}
