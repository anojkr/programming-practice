#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {

	int data;
	char c[100];
	struct node *left;
	struct node *right;
	struct node *parent;
};

struct node * get_node(int data, char p[100]){
	
	struct node *t = (struct node *)malloc(sizeof(struct node));
	strcpy(t -> c, p);

	t -> data   = data;
	t -> left   = NULL;
	t -> right  = NULL;
	t -> parent = NULL;

	return t;
}


struct node * add_node(struct node * root, int item, char p[100]){

	if (root == NULL){
		return get_node(item, p);
	}

	if (root -> data < item){

		root -> right = add_node(root -> right, item, p);
		root -> right -> parent = root;
	}

	if (root -> data >= item){
		
		root -> left = add_node(root -> left, item, p);
		root -> left -> parent = root;
	}

	return root;

}


void create_bst(struct node **root){

	int n;
	scanf("%d", &n);

	while (n){
		char  t[100];
		scanf("%s", t);

		int len = strlen(t);
		*root = add_node(*root, len, t);
		n--;
	}

}

void print_ll(struct node *root){

	if (root == NULL){
		return;
	}

	printf("%d ", root -> data);
	print_ll(root -> left);
	print_ll(root -> right);

}

void main (){
	struct node *root = NULL;
	create_bst(&root);
	print_ll(root);
}





















