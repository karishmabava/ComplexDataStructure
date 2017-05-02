/* Question We have discussed Overlapping Subproblems and Optimal Substructure properties in Set 1 and Set 2 respectively.

Let us discuss Longest Increasing Subsequence (LIS) problem as an example problem that can be solved using Dynamic Programming.
The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order. For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}.
longest-increasing-subsequence

More Examples:

Input  : arr[] = {3, 10, 2, 1, 20}
Output : Length of LIS = 3
The longest increasing subsequence is 3, 10, 20

Input  : arr[] = {3, 2}
Output : Length of LIS = 1
The longest increasing subsequences are {3} and {2}

Input : arr[] = {50, 3, 10, 7, 40, 80}
Output : Length of LIS = 4
The longest increasing subsequence is {3, 7, 40, 80}
*/

// Complexity O(nlogn)
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

int longestSubsequenceUtil(int arr[], int size, int pos, int lastNum){

	int t1 = 0;
	if(pos == size){
		return 0;
	}

	if(arr[pos] > lastNum){
	   t1 =  1 + longestSubsequenceUtil(arr, size, pos+1, arr[pos]);
	}

	int t2 =  longestSubsequenceUtil(arr, size, pos+1, lastNum);

	return max(t1, t2);
}


int longestSubsequence(int arr[], int size){

	int maxLen = 0;
	for(int i=0; i<size; i++){
		int len = longestSubsequenceUtil(arr, size, i, arr[i]);
			if(len > maxLen){
			   maxLen = len;
		    }
	}

	return maxLen;
}

int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of lis is %d\n", longestSubsequence( arr, n ) );
    return 0;
}
