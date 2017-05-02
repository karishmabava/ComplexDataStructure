/* Question: Write an efficient C program to find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum. */

// Complexity O(n)
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int max(int a, int b){

	if(a > b){
		return a;
	}

	return b;
}

int maxSubArraySum(int *arr, int n){

	int curr_max = arr[0];
	int max_so_far = arr[0];
	for(int i=1; i<n; i++){
		curr_max = max(arr[i], (curr_max + arr[i]));
		max_so_far = max(curr_max, max_so_far);
	}

	return max_so_far;
}

int main()
{
   int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
   int n = sizeof(a)/sizeof(a[0]);
   int max_sum = maxSubArraySum(a, n);
   printf("Maximum contiguous sum is %d\n", max_sum);
   return 0;
}
