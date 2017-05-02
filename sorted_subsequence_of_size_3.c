/* Question: Given an array of n integers, find the 3 elements such that a[i] < a[j] < a[k] and i < j < k in 0(n) time. If there are multiple such triplets, then print any one of them.

*/

// Complexity O(n)

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int * find3Numbers(int *arr, int size){
	
	int *result = (int *)malloc(sizeof(int) * size);
	memset(result, 0, sizeof(int) * size);

	int i=1;
	int j=0;
	int temp = 0;
	while(size > 0){
		
		  if(arr[j] < arr[i]){
			 result[i] += 1;
			 result[j] += 1;
			
			// If detected that just visited element is greater than 
			// now visiting element then we will consider the now visiting element		
			 if(arr[temp] > arr[i]){
				result[temp] = 0;
			 }
			 temp = i;
			 i++;
		  } else {

			 i++;
			 j++;
		  }
		size--;
	}

	return result;
}

int main()
{
    int arr[] = {1, 4, 45, 6, 10, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    
	int *result = find3Numbers(arr, n);
    
	for(int i=0; i<n; i++){
		if(result[i] != 0){
		   printf("%d ", arr[i]);
		}
	}

	printf("\n");
	return 0;
}
