/* Level order travesal */

#include <stdio.h>
#include <stdlib.h>
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left, *right;
};
 
int max(int a, int b){

	if(a > b){
		return a;
	}

	return b;
}

int height(struct node *root){
	
	if(root == NULL){
		return 0;
	}

	return 1 + max(height(root->left), height(root->right));

}

void printLevelUtil(struct node *root, int level){

	 if(root == NULL){
		return;
	 }
	
	 if(level == 1){
		printf("%d ", root->data);	
	 	return;
	 } else if(level > 1){ 	
	 	printLevelUtil(root->left, level-1); 
	 	printLevelUtil(root->right, level-1);
	 }
}

void printLevelOrder(struct node *root){

	 if(root == NULL){
		return;
	 }

	 int h = height(root);
	 for(int i=1; i<=h; i++){
		 printLevelUtil(root, i);
	 }
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
 
/* Driver program to test above functions*/
int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
 
    printf("Level Order traversal of binary tree is \n");
    printLevelOrder(root);
 
    return 0;
}
