/* Question: Given a binary tree, write a function to get the maximum width of the given tree. Width of a tree is maximum of widths of all levels.

Let us consider the below example tree.
 				 1
               /   \
             2      3
           /  \      \
          4    5      8
                    /   \
                   6     7

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
 
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}

int max(int a, int b){

	if(a > b){
	   return a;
	}

	return b;
}

int height(struct node *root){
	
	if(root == NULL){
	   return 0;
	} else {
		return 1 + max(height(root->left), height(root->right));
	}
}


void getMaxWidthUtil(struct node *root, int *count, int level){

	if(root == NULL){
		return;
	} else {
		count[level]++;
	    level++;
	    getMaxWidthUtil(root->left, count, level);
		getMaxWidthUtil(root->right, count, level);
	}

}

int getMax(int arr[], int n)
{
   int max = arr[0];
   int i;
   for (i = 0; i < n; i++)
   {
       if (arr[i] > max)
          max = arr[i];
   }
   return max;
}

int getMaxWidth(struct node *root){

    int tree_height = height(root);
	int *count = (int *)malloc(sizeof(int) * tree_height);
	memset(count, 0, sizeof(int) * tree_height);

	getMaxWidthUtil(root, count, 0);

	return getMax(count, tree_height);
}


/* Driver program to test above functions*/
int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->right = newNode(8);    
  root->right->right->left  = newNode(6);    
  root->right->right->right  = newNode(7);      
 
  /*
   Constructed bunary tree is:
          1
        /  \
       2    3
     /  \     \
    4   5     8 
              /  \
             6   7
  */ 
  printf("Maximum width is %d \n", getMaxWidth(root));  
  return 0;
}

