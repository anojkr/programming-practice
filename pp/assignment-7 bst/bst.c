
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
		temp = get_node(data);
		return temp;
	}
	if( t -> data <= data ){
		 t -> right = insert_node(t -> right, data);
		 t -> right -> parent  = t; 
	}
	if( t->data > data ){
		 t -> left = insert_node(t -> left, data);
		 t -> left -> parent = t;
	}
	return t;

}

struct node * bst(struct node *root, int n){

	for (int i = 0; i < n; i++){
		int data;
		scanf("%d", &data);
		insert_node(root, data);
	}

}

void print_ll(struct node *root){
	if (root == NULL){
		return;
	}
	if (root->parent != NULL){
	printf("\nParent = %d\n",
			root->parent->data);
	}
	printf("%d ", root -> data);
	print_ll(root -> left);
	print_ll(root -> right);
}



void main(){
	struct node *root = NULL;
	
	int n;
	scanf(" %d", &n);
	
	int data;
	scanf(" %d", &data);
	root  = get_node(data);
	//printf("\nroot data = %d", root-> data);
	bst(root, (n-1));
	printf("\n");
	print_ll(root);
}
