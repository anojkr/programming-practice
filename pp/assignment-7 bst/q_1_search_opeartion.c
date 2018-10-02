#include <stdio.h>
#include <stdlib.h>

struct node {

	int data;
	struct node *left;
	struct node *right;
	struct node *parent;

};

struct node * get_node(int item){
	struct node *t = (struct node *)malloc(sizeof(struct node));
	
	t -> data   = item;
	t -> left   = NULL;
	t -> right  = NULL;
	t -> parent = NULL;

	return t;

}


struct node * insert_node(struct node *root, int item){
	
	struct node *t = root;
	
	if (t == NULL){
		return get_node(item);
	}

	if (t -> data < item){
		t -> right = insert_node(t -> right, item);
		t -> right -> parent = t;
	}

	if (t -> data > item){
		t -> left = insert_node(t -> left, item);
		t -> left -> parent = t;
	}

	return t;

}

struct node * search(struct node *root, int item){
	struct node *t = root;

	if (t == NULL){
		printf("\nn");
		return t;
	}

	if (t -> data < item){
		return search(t -> right, item);
	}

	if (t -> data > item){
		return search(t -> left, item);
	}

	if (t -> data == item){
		printf("\ny");
		return t;
	}

}

void bst(struct node **root, int n){
	struct node *t = *root;
	for (int i = 0 ; i < n ; i++){
		int item;
		scanf("%d", &item);
		*root = insert_node(*root, item);
	}

}

void print_ll_preorder(struct node * root){

	struct node *t = root;

	if (t == NULL){
		return;
	}

	printf("%d ", t -> data );
	print_ll_preorder(t -> left);
	print_ll_preorder(t -> right);

}

void main(){

	struct node * root = NULL;

	int n;
	scanf("%d", &n);

	bst(&root, n);
	print_ll_preorder(root);

	int s;
	scanf("%d", &s);
	for (int i = 0; i < s; s++){
		int item;
		scanf("%d", &item);
		search(root, item);
	}

}