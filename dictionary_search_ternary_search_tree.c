#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 400

struct node {

	char data;
	unsigned isEndofString:1;
	struct node *left, *right, *eq;
};

struct node * new_node(char data){
	   struct node *root;
	
	   root = (struct node *)malloc(sizeof(struct node));
	   memset(root, 0, sizeof(struct node));

	  root->data = data;
	  root->isEndofString = 0;
	  root->left = root->right = root->eq = NULL;

	  return root;	
}

int search(struct node *root, char *word){

	if(!root)
		return 0;

	   if(*word < (root)->data){
			return search(root->left, word);
	   } else if(*word > (root)->data){
			return search(root->right, word);
	   } else {
			if(*(word+1) == '\0')
				return root->isEndofString;
			
				return search(root->eq, word+1);
	   } 
}

void insert(struct node **root, char *word){

	 if(!(*root)){
		*root = new_node(*word);
	 } 

	if ((*word) < (*root)->data)
        insert(&( (*root)->left ), word);
 
    // If current character of word is greate than root's character,
    // then insert this word in right subtree of root
    else if ((*word) > (*root)->data)
        insert(&( (*root)->right ), word);
 
    // If current character of word is same as root's character,
    else
    {
        if (*(word+1))
            insert(&( (*root)->eq ), word+1);
 
        // the last character of the word
        else
            (*root)->isEndofString = 1;
    }

		/*	
		if((*word) > (*root)->data){
			insert(&((*root)->right), word);
		} else if((*word) < (*root)->data){
			insert(&((*root)->left), word);
		} else {
			if(*(word+1)){
				insert(&((*root)->eq), word+1);
			} else {
				(*root)->isEndofString = 1;
			}
		} */
}

void traverseTSTUtil(struct node *root, char *buffer, int depth){

	 if(root){

		traverseTSTUtil(root->left, buffer, depth);
		buffer[depth] = root->data;
		if(root->isEndofString){
			buffer[depth+1] = '\0';
			printf("%s\n", buffer);
		}
		
		traverseTSTUtil(root->eq, buffer, depth+1);
		traverseTSTUtil(root->right, buffer, depth);
	 }
}

void traverseTST(struct node *root){

	 char buffer[MAX];
	 traverseTSTUtil(root, buffer, 0);
}

// Driver program to test above functions
int main()
{
    struct node *root = NULL;
 
    insert(&root, "cat");
    insert(&root, "cats");
    insert(&root, "up");
    insert(&root, "bug");
 
    printf("Following is traversal of ternary search tree\n");
    traverseTST(root);
 
    printf("\nFollowing are search results for cats, bu and cat respectively\n");
    search(root, "cats")? printf("Found\n"): printf("Not Found\n");
    search(root, "bu")?   printf("Found\n"): printf("Not Found\n");
    search(root, "cat")?  printf("Found\n"): printf("Not Found\n");
 
    return 0;
}
