#include<stdio.h>
#include<stdlib.h>
 
/* A binary tree tNode has data, pointer to left child
   and a pointer to right child */
struct node
{
   int data;
   struct node* left;
   struct node* right;
};

void MorrisTraversal(struct node *root){

	 if(root == NULL){
		return;
	 }

	 struct node *curr=root, *pre=NULL;

	 while(curr != NULL){
		   
		   if(curr->left == NULL){	
			  printf("%d ", curr->data);
			  curr = curr->right;
		   } else {
				pre = curr->left;
		   		while(pre->right != NULL && pre->right != curr){
					  pre = pre->right;
				}

				if(pre->right == NULL){
			   		pre->right = curr;
					curr = curr->left;
				} else {
			   		pre->right = NULL;
			   		printf("%d ", curr->data);
			   		curr = curr->right;
				}
			}
	 }

}

struct node* newtNode(int data)
{
  struct node* tNode = (struct node*)
                       malloc(sizeof(struct node));
  tNode->data = data;
  tNode->left = NULL;
  tNode->right = NULL;
 
  return(tNode);
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
  struct node *root = newtNode(1);
  root->left        = newtNode(2);
  root->right       = newtNode(3);
  root->left->left  = newtNode(4);
  root->left->right = newtNode(5); 
 
  MorrisTraversal(root);
 
  return 0;
}
