#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct node * get_node(struct node *root, int data){
	struct node *t  = (struct node *)malloc(sizeof(struct node));
	t -> data 	= data;
	t -> left 	= NULL;
	t -> right 	= NULL;

	return t;

}

struct node *search(struct node *root, int data){
	struct node *t = root;

	if (t == NULL){
		return NULL;
	}

	if (t -> data < data){
		return search( t -> right, data );
	}

	if (t -> data > data){
		return search( t -> left, data );
	}

	if (t -> data == data){
		return t;
	}

}

struct node * add_node(struct node * root, int data){
	
	struct node *t = root;

	if (t == NULL){
		return get_node(root, data);
	}

	if (t -> data < data){
		t -> right = add_node(t -> right, data);
	}

	if (t -> data > data){
		t -> left = add_node(t -> left, data);
	}

	return t;

}

struct node * merger_operation(struct node * root, int data){
	
	struct node *t = root;

	if (t == NULL){
		return get_node(root, data);
	}

	if (t -> data == data){
		printf("Cannot merge");
		return NULL;
	}
	if (t -> data < data){
		t -> right = add_node(t -> right, data);
	}

	if (t -> data > data){
		t -> left = add_node(t -> left, data);
	}

	return t;

}

void create_bst(struct node **root){
	int n;
	scanf("%d", &n);
	while(n){
		int item;
		scanf("%d", &item);
		*root = add_node(*root, item);
		n--;
	}
}


void union_all (struct node ** root1, struct node *root2){
		if (root2 == NULL){

			return;
		}	

		*root1 = add_node(*root1, root2 -> data);
		union_all(root1, root2 -> left);
		union_all(root1, root2 -> right);
}


void merge(struct node **root1, struct node *root2){
		if (root2 == NULL){

			return;
		}	

		*root1 = merger_operation(*root1, root2 -> data);
		merge(root1, root2 -> left);
		merge(root1, root2 -> right);

}

void preorder(struct node * root){
	struct node *t = root;

		if (t == NULL){
			return;
		}

		printf("%d ", t -> data);
		preorder(t -> left);
		preorder(t -> right);

}

void main(){

	struct node *root1 = NULL;
	struct node *root2 = NULL;

	create_bst(&root1);
	printf("\n");
	preorder(root1);
	
	create_bst(&root2);
	printf("\n");
	preorder(root2);
	

	merge(&root1, root2);
	// union_all(&root1, root2);
	printf("\n");
	preorder(root1);

}