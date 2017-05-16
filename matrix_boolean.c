/*Question: Given a boolean matrix mat[M][N] of size M X N, modify it such that if a matrix cell mat[i][j] is 1 (or true) then make all the cells of ith row and jth column as 1 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define R 3
#define C 4

/* A utility function to print a 2D matrix */
void printMatrix(bool mat[R][C])
{
    int i, j;
    for (i = 0; i < R; i++)
    {
        for (j = 0; j < C; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
 
void modifyMatrix(bool mat[R][C]){

	bool row[R] = {0};
	bool col[C] = {0};

	int c=0;
	for(int i=0; i<R; i++){
		row[i] = 0;
	}

	for(int i=0; i<C; i++){
		col[i] = 0;
	}

	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(mat[i][j] == 1){
			   row[i] = 1;
			   col[j] = 1;
			}
		}
	}

	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(row[i] == 1 || col[j] == 1){
			   mat[i][j] = 1;
			}
		}
	} 

	printMatrix(mat);
}

/* Driver program to test above functions */
int main()
{
    bool mat[R][C] = { {1, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
    };
 
    printf("Input Matrix \n");
    printMatrix(mat);
	printf("\n"); 
    modifyMatrix(mat);
 
    printf("Matrix after modification \n");
//    printMatrix(mat);
 
    return 0;
}
