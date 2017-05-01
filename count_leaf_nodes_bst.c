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

int getLeafCount(struct node *root){

	if(root == NULL){
		return 0;
	}

	if(root->left == NULL && root->right == NULL){
	   return 1;
	}

	return (getLeafCount(root->left) + getLeafCount(root->right));
}
 
/*Driver program to test above functions*/ 
int main()
{
  /*create a tree*/ 
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);    
   
  /*get leaf count of the above created tree*/
  printf("Leaf count of the tree is %d\n", getLeafCount(root));
   
  return 0;
}

