#include <stdio.h>
#include <stdlib.h>
//Adelson-Velskii and Landis
struct node {

	int data;
	struct node *left;
	struct node *right;
	struct node *parent;

};

struct node *get_node(int data){
	
	struct node *t = (struct node *)malloc(sizeof(struct node));
	t -> data   = data;
	t -> left   = NULL;
	t -> right  = NULL;
	t -> parent = NULL;
	return t;

}

int height(struct node *root){
	
	struct node *t = root;

	if (t == NULL){
		return 0;
	}

/*	if (t -> left == NULL && t -> right == NULL){
		return 0;
	}
*/
	int l = height(t -> left);
	int r = height(t -> right);

	if (l > r){
		return 1 + l;
	}else {
		return 1 + r;
	}

}

int balance_factor(struct node *root){
	int bf = height (root -> left) - height(root -> right);
	return bf;
}


struct node * rr_rotation(struct node *root){
	struct node *t = root -> right;
	root -> right = t -> left;
	t -> left = root;
	return t;

}

struct node * ll_rotation(struct node *root){

	struct node *t = root -> left;
	root -> left = t -> right;
	t -> right = root;
	return t;


}

struct node * lr_rotation(struct node *root){
	struct node *t = root -> left;
	root -> left = rr_rotation(t);
	return ll_rotation(root);

}

struct node * rl_rotation(struct node *root){
	struct node *t = root -> right;
	root -> right = ll_rotation(t);
	return rr_rotation(root);

}

struct node * balance(struct node *root){
	int bf = balance_factor(root);

	if (bf > 1 ){
		if (balance_factor(root -> left) > 0){
			root = ll_rotation(root);
		}
		else {
			root = lr_rotation(root);
		}
	}

	if (bf <-1){
		if (balance_factor(root -> right) > 0){
			root = rl_rotation(root);
		}else {
			root = rr_rotation(root);
		}
	}

	return root;

}

struct node * add_node(struct node *root, int data){
	

	if (root ==  NULL){
		return get_node(data);
	}

	if (root -> data < data){
		root -> right = add_node(root -> right, data);
		//root -> right -> parent = root;
		root = balance(root);
	}

	if (root -> data > data){
		root -> left  = add_node(root -> left, data);
		//root -> left -> parent = root;
		root = balance(root);
	
	}

	return root;

}


void bst_balanced(struct node **root){

	int n;
	scanf("%d", &n);

	while (n){
		int item;
		scanf("%d", &item);
		*root = add_node(*root, item);		
		n--;
	}


}

void print_ll(struct node *root){

	struct node *t = root;

	if (t ==  NULL){
		return;
	}

	printf("%d ", t -> data);
//	printf("Depth of Node : %d\n", height(t));
	print_ll(t -> left);
	print_ll(t -> right);

}

void main(){
	
	struct node *root = NULL;
	bst_balanced(&root);
	print_ll(root);

}
