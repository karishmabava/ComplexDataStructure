/* Question: Given a binary tree and a number, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals the given number. Return false if no such path can be found.

 Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
 
For example, in the above tree root to leaf paths exist with following sums.

21 –> 10 – 8 – 3
23 –> 10 – 8 – 5
14 –> 10 – 2 – 2

So the returned value should be true only for numbers 21, 23 and 14. For any other number, returned value should be false.
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

bool hasPathSum(struct node *root, int sum){

	bool ans=0;
    int subSum = 0;

	if(root == NULL){
	   return false;
	} else {
	   subSum = sum - root->data;
		
	   if(subSum == 0 && root->left == NULL && root->right == NULL){
          return 1;
	   }
      
       return (hasPathSum(root->left, subSum) || hasPathSum(root->right, subSum));
	}
}

struct node* newnode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
 
/* Driver program to test above functions*/
int main()
{
 
  int sum = 21;
 
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
 
  if(hasPathSum(root, sum))
    printf("There is a root-to-leaf path with sum %d\n", sum);
  else
    printf("There is no root-to-leaf path with sum %d\n", sum);
 
  return 0;
}
