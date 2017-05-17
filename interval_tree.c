#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

struct Interval {
	int low;
	int high;
};

struct node {

	struct Interval *i;
	int max;
	struct node *left, *right;
};

struct node * new_node(struct Interval *i){
	
	struct node *new = (struct node *)malloc(sizeof(struct node));
	memset(new, 0, sizeof(struct node));

	new->i = (struct Interval *)malloc(sizeof(struct Interval));
	memset(new->i, 0, sizeof(struct Interval));

	new->i = i;
	new->left = new->right = NULL;
	new->max = i->high;
	
	return new;
}

struct node * insert(struct node *root, struct Interval *i){

	 if(root == NULL){
		root = new_node(i);
		return root;
	 }

	 int l = root->i->low;
	 if(i->low < l){
		root->left  = insert(root->left, i);
	 } else {
		root->right =  insert(root->right, i);
	 }
	
	 if(i->high > root->max){
		root->max = i->high;
	 }

	 return root; 
}

bool doOverlap(struct Interval *i1, struct Interval *i2){

	 if(i1->low <= i2->high && i2->low <= i1->high){
		return true;
	 }

	 return false;
}

struct Interval * search(struct node *root, struct Interval *i){

	  if(root == NULL){
		 return NULL;
	  }
	
	  if(doOverlap(root->i, i)){
		 return root->i;	
	  }

	  if(root->left != NULL && root->left->max >= i->low){
		 return search(root->left, i);
	  }	

	  return search(root->right, i);
}


void inorder(struct node *root)
{
    if (root == NULL) return;
 
    inorder(root->left);
 
    printf("Low: %d , High: %d, Max: %d\n", root->i->low, root->i->high, root->max);
 
    inorder(root->right);
}
 
// Driver program to test above functions
int main()
{
    // Let us create interval tree shown in above figure
    struct Interval ints[] = {{15, 20}, {10, 30}, {17, 19},
        {5, 20}, {12, 15}, {30, 40}
    };
    int n = sizeof(ints)/sizeof(ints[0]);
    struct node *root = NULL;
    for (int i = 0; i < n; i++)
         root = insert(root, &ints[i]);
 
    printf("Inorder traversal of constructed Interval Tree is\n");
    inorder(root);
 
    struct Interval x = {6, 7};
 
    printf("\nSearching for interval %d , %d\n", x.low, x.high);
    struct Interval *res = search(root, &x);
    if (res == NULL)
        printf("\nNo Overlapping Interval\n");
    else
        printf("\nOverlaps with %d %d\n", res->low, res->high);
    return 0;
}
