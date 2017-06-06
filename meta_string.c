/* Given two strings, the task is to check whether these strings are meta strings or not. Meta strings are the strings which can be made equal by exactly one swap in any of the strings. Equal string are not considered here as Meta strings.

Examples:

Input : A = "geeks" 
        B = "keegs"
Output : 1
By just swapping 'k' and 'g' in any of string, 
both will become same.

Input : A = "rsting"
        B = "string
Output : 0


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line denoting string A and the second line denoting string B.

Output:
For each test case in a new line print 1 if A and B are meta strings, else print 0.

Constraints:
1<=T<=100
1<=Length of strings<=1000

Example:
Input:
2
geeks
keegs
geeks
geeks

Output:
1
0 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define index(c) ((int)c - (int)'a')

bool meta_string(char *str1, char *str2){
    int m = strlen(str1);
    int n = strlen(str2);
    int count =0;
    // int hash[m] = {0};
    int *hash = (int *)malloc(sizeof(int) * m);
    memset(hash, 0, sizeof(int) * m);
    
    if(m != n){
        return false;
    }
    
    for(int i=0; i<m ; i++){
        hash[index(str1[i])]++;
    }
    
    for(int j=0; j<n; j++){
        if(hash[index(str2[j])] != 0 && str1[j] != str2[j]){
            count++;
        }
        
        if(hash[index(str2[j])] == 0){
            return false;
        }
    }

	/* If only once swap is required then the count should have been incremented twice only */    
    if(count = 2){
        return true;
    }
    
    return false;
}

int main() {
	//code
	char *str1 = "geeks";
	char *str2 = "keegs";
	
	if(meta_string(str1, str2)){
	    printf("Yes they are meta string\n");
	} else {
	    printf("No they are not meta string\n");
	}
	
	return 0;
}
