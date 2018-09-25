
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * left;
	struct node * right;
	struct node * parent;
};

struct node * get_node(int data){
	struct node *t = (struct node *)malloc(sizeof(struct node));

	t -> data   = data;
	t -> left   = NULL;
	t -> right  = NULL;
	t -> parent = NULL;	
	
	return t;
}


struct node *insert_node(struct node *root, int data){

	struct node *t = root;
	struct node *temp = NULL;

	if (t == NULL){
		struct node *k = get_node(data);
		return k;
	}
	
	else if( t -> data <= data ){
		 t -> right = insert_node(t -> right, data);
		 t -> right -> parent  = t; 
	}
	
	else if( t->data > data ){
		 t -> left = insert_node(t -> left, data);
		 t -> left -> parent = t;
	}
	
	return t;

}

struct node * bst(struct node *root, int n){

	for (int i = 0; i < n; i++){
		int data;
