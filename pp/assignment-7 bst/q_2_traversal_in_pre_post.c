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
		printf("Data Not Found");
		return t;
	}

	if (t -> data < item){
		return search(t -> right, item);
	}

	if (t -> data > item){
		return search(t -> left, item);
	}

	if (t -> data == item){
		printf("Data Found = %d", t -> data);
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

void inorder(struct node * root){

	struct node *t = root;

	if (t == NULL){
		return;
	}

	inorder(t -> left);
	printf("%d_", t -> data );
	inorder(t -> right);

}

void preorder(struct node * root){

	struct node *t = root;

	if (t == NULL){
		return;
	}

	printf("%d_", t -> data );
	preorder(t -> left);
	preorder(t -> right);

}

void postorder(struct node * root){

	struct node *t = root;

	if (t == NULL){
		return;
	}

	postorder(t -> left);
	postorder(t -> right);
	printf("%d_", t -> data );

}

void main(){

	struct node * root = NULL;

	int n;
	scanf("%d", &n);

	bst(&root, n);

	printf("\npreorder : ");
	preorder(root);
	
	printf("\ninorder : ");
	inorder(root);

	printf("\npostorder : ");
	postorder(root);

}