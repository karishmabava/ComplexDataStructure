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




/* Given a binary tree, printInorder() prints out its
   inorder traversal*/
void printInorder(struct node* node)
{
  if (node == NULL)
    return;
 
  /* first recur on left child */
  printInorder(node->left);
 
  /* then print the data of node */
  printf("%d ", node->data);
 
  /* now recur on right child */
  printInorder(node->right);
}
 
/* Helper function that allocates a new node
 with the given data and NULL left and right
 pointers. */
struct node* newNode(int data)
{
  struct node* node =
      (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
void increment(struct node *root, int diff){

	if(root->left != NULL){
       root->left->data += diff;
       increment(root->left, diff);
    } else if (root->right != NULL){
       root->right->data += diff;
       increment(root->right, diff);
    }

}

void convertTree(struct node *root){

	int left_data = 0;
    int right_data = 0;
	int diff;
	if((root == NULL) || (root->left == NULL && root->right == NULL)){
	   return;
	} else {
	   convertTree(root->left);
       convertTree(root->right);
	   
	   if(root->left != NULL)
		  left_data = root->left->data;

	   if(root->right != NULL)
		  right_data = root->right->data;

	   diff = (left_data + right_data)  - root->data;
	   
	   if(diff > 0){
		  root->data += diff;
	   } 

	   if(diff < 0){
	      increment(root, -diff);
	   }

	}
}
 
/* Driver program to test above functions */
int main()
{
  struct node *root = newNode(50);
  root->left        = newNode(7);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left  = newNode(1);
  root->right->right = newNode(30);
 
  printf("\n Inorder traversal before conversion ");
  printInorder(root);
  printf("\n"); 
  convertTree(root);
 
   printf("\n Inorder traversal after conversion ");
   printInorder(root);
   printf("\n");
  
   return 0;
}

