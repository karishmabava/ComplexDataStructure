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

/* Utility that prints out an array on a line */
void printArray(int ints[], int len)
{
  int i;
  for (i=0; i<len; i++) {
    printf("%d ", ints[i]);
  }
  printf("\n");
}

void printPathsUtil(struct node *root, int path[], int count){

     path[count] = root->data;
	 count++;

	 if(root->left == NULL && root->right == NULL){
		printArray(path, count);
		return;		
	 } else {
		printPathsUtil(root->left, path, count);
		printPathsUtil(root->right, path, count);
	 }

}

void printPaths(struct node *root){

    if(root == NULL){
       return;
    }

    int path[1000] = {0};
    printPathsUtil(root, path, 0);
}

/* Driver program to test mirror() */
int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
 
  /* Print all root-to-leaf paths of the input tree */
  printPaths(root);
 
  return 0;
}

