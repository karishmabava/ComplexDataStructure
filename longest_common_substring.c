#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int max_ele(int a, int b){

	if(a > b){
		return a;
	} else {
		return b;
	}
}

int longest_common_substring(char *str1, char *str2){

	int m = strlen(str1);
	int n = strlen(str2);
	int max = 0;
	int temp[m+1][n+1];

	for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
			temp[i][j] = 0;
		}
	}

	for(int i=1; i<m; i++){
		for(int j=1; j<n; j++){
			if(str1[i-1] == str2[i-1]){
			   temp[i][j] = temp[i-1][j-1] + 1;
			} else {
			   temp[i][j] = max_ele(temp[i-1][j], temp[i][j-1]);
			}
			if(temp[i][j] > max){
			   max = temp[i][j];
			}
		}
	}

	return max;
}

int main(){

	char *str1 = "abcdaf";
	char *str2 = "zbcdf";

	int len = longest_common_substring(str1, str2);

	printf("Longest common substring is %d\n", len);

	return 1;
}
