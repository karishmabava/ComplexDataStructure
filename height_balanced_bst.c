/* Question: How to determine if the BST is height balanced or not */
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

int max(int a, int b)
{
  return (a >= b)? a: b;
}    
 
/*  The function Compute the "height" of a tree. Height is the
    number of nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(struct node* node)
{
   /* base case tree is empty */
   if(node == NULL)
       return 0;
 
   /* If tree is not empty then height = 1 + max of left
      height and right heights */
   return 1 + max(height(node->left), height(node->right));
} 
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node = (struct node*)
                                malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return(node);
}

bool isBalanced(struct node *root){

	if(root == NULL){
	   return NULL;
    }

    if(abs(height(root->left) - height(root->right)) == 1 &&
	   isBalanced(root->left) &&
	   isBalanced(root->right)){
		
       return true;
	}

   return false;
}
 
int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);
 
    if(isBalanced(root))
      printf("Tree is balanced\n");
    else
      printf("Tree is not balanced\n");    
 
    return 0;
}
