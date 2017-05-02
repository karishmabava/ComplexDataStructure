/* Question: Write a program that converts a given tree to its Double tree. To create Double tree of the given tree, create a new duplicate for each node, and insert the duplicate as the left child of the original node.

So the tree…

 			1
          /   \
        2      3
      /  \
    4     5 

 would become 

				1
			  /  \
			 1    3
			/	 /
		   2	3
		  /
		 2
	    /
	   4
      /
     4
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
 
/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct node* node)
{
  if (node == NULL)
    return;
  printInorder(node->left); 
  printf("%d ", node->data);
  printInorder(node->right);
}
 
void doubleTree(struct node *root){

	 struct node *temp;

     if(root == NULL){
		return;
	 } else {

		doubleTree(root->left);
	    doubleTree(root->right);
	    temp = root->left;
		root->left = newNode(root->data);
	    root->left->left = temp;
	 }

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
  
  printf("Inorder traversal of the original tree is \n");
  printInorder(root);
 
  doubleTree(root);
   
  printf("\n Inorder traversal of the double tree is \n");  
  printInorder(root);
  printf("\n");
    
  return 0;
}


