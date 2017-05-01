#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node* left, *right;
};
/* returns maximum of two integers */
int max(int a, int b)
{
  return (a >= b)? a: b;
}  

struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}

int height(struct node *root){

	if(root == NULL){
	   return 0;
	}

	return 1 + max(height(root->left), height(root->right));
}

int diameter(struct node *root){

   int ldiameter;
   int rdiameter;
   int lheight;
   int rheight;

   if(root == NULL){
	  return 0;
   }	

   ldiameter = diameter(root->left);
   rdiameter = diameter(root->right);   

   lheight = height(root->left);
   rheight = height(root->right);

   return max((1+lheight+rheight), max(ldiameter, rdiameter)); 

}
 
/* Driver program to test above functions*/
int main()
{
 
  /* Constructed binary tree is 
            1
          /   \
        2      3
      /  \
    4     5
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
 
  printf("Diameter of the given binary tree is %d\n", diameter(root));
 
  return 0;
}

