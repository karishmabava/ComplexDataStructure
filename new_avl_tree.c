#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h> 

// An AVL tree node
struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
    int count;
};

int max(int a, int b){

	if(a>b){
		return a;
	}

	return b;
}

struct node *minValue(struct node *root){

	if(root == NULL){
		return root;
	}

	struct node *curr=root;
	while(curr->left != NULL){
		  curr = curr->left;
	}

	return curr;
}

int height(struct node *root){

	if(root == NULL){
		return 0;
	}
	
	return root->height;
}

void preOrder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d(%d) ", root->key, root->count);
        preOrder(root->left);
        preOrder(root->right);
    }
}

struct node * new_node(int key){
		
       struct node *root = (struct node *)malloc(sizeof(struct node));
	   memset(root, 0, sizeof(struct node));
	
	   root->key = key;
	   root->left = root->right = NULL;
	   root->height = 0;
	   root->count = 1;

	   return root;
}

struct node * delete_binary_search_tree(struct node *root, int key){

	 struct node *temp;

	 if(root == NULL){
		return root;
	 }

	 if(key < root->key){
		root->left = delete_binary_search_tree(root->left, key);
	 } else if(key > root->key){
		root->right = delete_binary_search_tree(root->right, key);
	 } else {

			 // When the bottom leaf only have right child.
			 if(root->left == NULL){
			    struct node *temp = root->right;
			    free(root);
			    return temp;		   
			 } else if(root->right == NULL){
			    struct node *temp= root->left;
			    free(root);
			    return temp;	
			 } else {
			  	struct node *temp = minValue(root);
				root->key = temp->key;
				root->right = delete_binary_search_tree(root->right, temp->key);
	      
		     }
	 }	 
	 return root;
}

int get_balance(struct node *root){

    if(root == NULL){
       return 0;
    }
   
    return (height(root->left) - height(root->right));
}

struct node *leftRotate(struct node *root){

       struct node *x = root->right;
       struct node *y = x->left;

       // Rotation
       x->left = root;
       root->right = y;

      // updating height
      root->height = max(height(root->left), height(root->right)) + 1;
      x->height = max(height(x->left), height(x->right)) + 1;

      return x;
}

struct node *rightRotate(struct node *root){

     struct node *x = root->left;
     struct node *y = x->right;

     // Rotation
     x->right = root;
     root->left = y;

    //updating height
    root->height = max(height(root->left), height(root->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

	return x;
}

struct node * delete(struct node *root, int key){

	  if(root == NULL){
		 return root;
	  }

	 if(root->key == key){
         if(root->count > 1){
			(root->count)--;
		 }
	 }
	   root = delete_binary_search_tree(root, key); 
	 // If the root only had one node
	 if(root == NULL){
		return NULL;
	 }

	 root->height = max(height(root->left), height(root->right)) + 1;

	 int balance = get_balance(root);

	// Left left case
	if(balance > 1 && get_balance(root->left) <= 0){
		return rightRotate(root);
	}

	// right right case
	if(balance < -1 && get_balance(root->right) >= 0){
		return leftRotate(root);
	}
	
	// Left right case
	if(balance > 1 && get_balance(root->left) > 0){
	   root->left = leftRotate(root->left);
	   return rightRotate(root);
	}

	// right left case
	if(balance < -1 && get_balance(root->right) < 0){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;	
}

struct node * insert(struct node *root, int key){

	   if(root == NULL){
		  root = new_node(key);
		  return root;
	   }

	   if(key == root->key){
		  (root->count)++;
		   return root;
	   }

	   if(key < root->key){
		  root->left = insert(root->left, key);
	   } else {
		  root->right = insert(root->right, key);
	   }
	
	   root->height = max(height(root->left), height(root->right)) + 1;

	  int balance = get_balance(root);	   
		
	  // Left left case
	  if(balance > 1 && key < root->left->key){
		 return rightRotate(root);
	  }

	  // right right case
	  if(balance < -1 && key > root->right->key){
		 return leftRotate(root);
	  }

	  // Left right case
	  if(balance > 1 && key > root->left->key){
		 root->left = leftRotate(root->left);
		 return rightRotate(root);
	  }

	  // Right left case
	  if(balance < -1 && key < root->right->key){
		 root->right = rightRotate(root->right);
		 return leftRotate(root);
	  }

	return root;
}

int main()
{
  struct node *root = NULL;
 
  /* Constructing tree given in the above figure */
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 9);
    root = insert(root, 7);
    root = insert(root, 17);
 
    printf("Pre order traversal of the constructed AVL tree is \n");
    preOrder(root);
	printf("\n"); 
    root = delete(root, 9);
 
    printf("\nPre order traversal after deletion of 10 \n");
    preOrder(root);
 
    return 0;
}
