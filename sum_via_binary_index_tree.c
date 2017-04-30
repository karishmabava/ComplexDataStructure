/* Question: Range query by Binary index tree:  Fenwick tree */

// Solution: Please watch youtube video by Tushar
// Complexity O(n)
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

// Adding values to the elements in the binary index tree
void updateTree(int *bi, int n, int index, int val){

	/* We have index in bittree based on 1 but arr is based on zero.
	 * in fenwick tree we dont fill anything in 0 node.
	 */	
	index = index + 1;
	
	while(n>=index){
		bi[index] = bi[index] + val;
		index += index&(-index);
	} 
}

// Sum function to get sum from binary index tree
// This function presumes that we ve preprocessed the binary index tree
int getSum(int *bi, int index){

	int sum=0;
	
	// Same reason for +1 as state above
	index = index+1;

	while(index > 0){
		  sum += bi[index];
		  index -= index&(index);
	}

	return sum;
}


int main(){
	
	int n;
	printf("Enter the number of elements");
	scanf("%d", &n);

	int *arr = (int *)malloc(sizeof(int) * n);
	memset(arr, 0, sizeof(int) * n);

	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	// Initializing binary index tree
	int *bi = (int *)malloc(sizeof(int) * n);
	memset(bi, 0, sizeof(int) * n);

	for(int i=0; i<n; i++){
		updateTree(bi, n, i, arr[i]);
	}

	int sum = getSum(bi, 3);

	printf("Sum is %d\n", sum);
	return 1;
}

