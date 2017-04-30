
/* Question: Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.

Insert
Remove
Replace
All of the above operations are of equal cost.
*/
// Complexity O(m * n)
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int min_util(int a, int b){
	
	if(a > b){
		return b;
	}

	return a;
}

int min(int a, int b, int c){

	return min_util(min_util(a,b), c);

}

int editDistance(char *str1, char *str2, int m, int n){

	// If both strings have 0 length then simply return 0;
	if(m == 0 && n == 0){
	   return 0;
	}

	// If the string 2 is 0 then return str1 and vice versa
	if(n==0){
		return m;
	}
	if(m == 0){
	   return n;
	}

	// If the last characters are same then recurvise reverse
	if(str1[m-1] == str2[n-1]){
	   return editDistance(str1, str2, m-1, n-1);
	}

	
    // If last characters are not same, consider all three
    // operations on last character of first string, recursively
    // compute minimum cost for all three operations and take
    // minimum of three values.
	return 1 + min(editDistance(str1, str2, m, n-1), // Insert
				   editDistance(str1, str2, m-1, n), // Remove
				   editDistance(str1, str2, m-1, n-1)); // Replace;

}

int main(){

	char *str1 = "sunday";
	char *str2 = "saturday";

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	int k = editDistance(str1, str2, len1, len2);

	printf("Minimum operations needed is %d\n", k);

    return 1;
}

