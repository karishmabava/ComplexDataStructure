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
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}

bool isSumProperty(struct node *root){

  int left_data = 0;
  int right_data = 0;

  if(root == NULL || (root->left == NULL && root->right == NULL)){
 	 return true;
  } else {
	 if(root->left){
		left_data = root->left->data;
	 }

	 if(root->right){
	    right_data = root->right->data;
     }

	 if((root->data == left_data + right_data) &&
		(isSumProperty(root->left)) &&
	    (isSumProperty(root->right))){
	     return true;
	 }
  } 

	return false;
}
 
/* Driver program to test above function */
int main()
{
  struct node *root  = newNode(10);
  root->left         = newNode(8);
  root->right        = newNode(2);
  root->left->left   = newNode(3);
  root->left->right  = newNode(5);
  root->right->right = newNode(2);
  if(isSumProperty(root))
    printf("The given tree satisfies the children sum property \n");
  else
    printf("The given tree does not satisfy the children sum property \n");
 
  return 0;
}
