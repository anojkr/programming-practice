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

void level_order(struct node * root, int level){

	struct node *t = root;

	if (t == NULL){
		return;
	}

	if (level == 1){
		printf("%d ", t -> data );
	}

	level_order(t -> left, level-1);
	level_order(t -> right, level-1);

}

void level_operation(struct node *root, int n){
	struct node * t = root;

	for(int i = 1; i < n; i++){
		printf("\n");
			level_order(root, i);
	}

}

void main(){

	struct node * root = NULL;

	int n;
	scanf("%d", &n);

	bst(&root, n);
	level_operation(root, n);

}