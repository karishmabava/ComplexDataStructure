/* Question: Given a sequence, find the length of the longest palindromic subsequence in it. For example, if the given sequence is “BBABCBCAB”, then the output should be 7 as “BABCBAB” is the longest palindromic subseuqnce in it. “BBBBB” and “BBCBB” are also palindromic subsequences of the given sequence, but not the longest ones.
*/

// Complexity O(n^2)
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>


int max(int a, int b){
	
	if(a > b)
	   return a;

	return b;
}

// Recursive fucntion to find the longest length of palindrome
int longestPalindromeSubsequence(char *str, int start, int len){

	if(len == 0)
	   return 0;

	if(len == 1)
	   return 1;

	// If there are only two characters and they both are same Base case
	if(str[start] == str[start + len - 1]){
	   return 2 + longestPalindromeSubsequence(str, start+1, len-2);
	} else {
		return max(longestPalindromeSubsequence(str, start+1, len-1),
			   longestPalindromeSubsequence(str, start, len-1));
	}
}

int main(){

	char *str = "agbdba";

	int len = strlen(str);

	int k = longestPalindromeSubsequence(str, 0, len);

	printf("Length is %d\n", k);
    return 1;
}

