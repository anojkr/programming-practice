#include <stdio.h>
#include <stdlib.h>

struct node {

	int data;
	struct node *left;
	struct node *right;

};


struct node * get_node(int data)
{

		struct node *t = (struct node *)malloc(sizeof(struct node));
		
		t -> data 	= data;
		t -> left 	= NULL;
		t -> right 	= NULL;
		
		return t;

}

int test_bst(struct node *root){

		if (root == NULL){
			return 1;
		}

		if (root -> left != NULL){

			if (root -> left -> data > root -> data ){
				return 0;
			}
		}

		if (root -> right != NULL){

			if (root -> right -> data < root -> data){
				return 0;
			}
		}

		return test_bst(root -> left) & test_bst(root -> right);
	
}

void main(){

	struct node *root = NULL;
	root = get_node(10);
	root -> left = get_node(5);
	root -> left -> left = get_node(8);
	root -> right =	get_node(15);
	root -> right -> right = get_node(20);
	if (test_bst(root) == 0){
		printf("NOT BST");
	}


} 