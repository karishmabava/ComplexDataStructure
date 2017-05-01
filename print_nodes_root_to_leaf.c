/*Question: For the below example tree, all root-to-leaf paths are: 
10 –> 8 –> 3
10 –> 8 –> 5
10 –> 2 –> 2

			10
          /   \
        8      2
      /  \    /
    3     5  2

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
   int data;
   struct node* left;
   struct node* right;
};

void printArray(int ints[], int len) 
{
  int i;
  for (i=0; i<len; i++) 
  {
    printf("%d ", ints[i]);
  }
  printf("\n");
}    
 
/* utility that allocates a new node with the
   given data and NULL left and right pointers. */  
struct node* newnode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  
  return(node);
}
 
void printPathsUtil(struct node *root, int pathlen[], int level){

	 if(root == NULL){
		return;
	 } else {

	   pathlen[level] = root->data;
	   level++;

	   if(root->left == NULL && root->right == NULL){
		  printArray(pathlen, level);		  
		}	

		printPathsUtil(root->left, pathlen, level);
	    printPathsUtil(root->right, pathlen, level); 
	 }

}

void printPaths(struct node *root){

	int pathlen[1000];
	printPathsUtil(root, pathlen, 0);

}
 
/* Driver program to test above functions*/
int main()
{ 
  
  /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
  struct node *root = newnode(10);
  root->left        = newnode(8);
  root->right       = newnode(2);
  root->left->left  = newnode(3);
  root->left->right = newnode(5);
  root->right->left = newnode(2);
  
  printPaths(root);
  
  return 0;
}
