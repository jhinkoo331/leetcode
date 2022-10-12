#include<stdio.h>


int search(int* nums, int numsSize, int target) {
	int left = 0;
	int right = numsSize - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		int midVal = nums[mid];
		if (midVal == target) {
			return mid;
		} else if (midVal > target) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return -1;
}

int main() {
	int arr1[] = {1,2,3};
	int arr2[] = {1,2,3,6,8,9};
	int arr3[] = {1};
	printf("%d", search(arr1, 3, 2));
	printf("%d", search(arr2, 6, 7));
	printf("%d", search(arr3, 1, 1));
	printf("%d", search(arr3, 1, 100));
	return 0;
}
