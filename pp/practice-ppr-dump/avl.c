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

struct node * get_node(char *p, int data){
	struct node *t = (struct node *)malloc(sizeof(struct node ));
	t -> data = data;
	strcpy(t -> c, p);
	t -> left = NULL;
	t -> right = NULL;
	t -> parent = NULL;
}

int height(struct node *root){

	if (root != NULL){

		int l = 1+height(root -> left);
		int r = 1+height(root -> right);
		return (l>r)?l:r;

	}

}

int bal_fact(struct node *root){
	if (root == NULL){
		return 0;
	}
	int l = height(root -> left);
	int r = height(root -> right);
	return l-r;
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

struct node *lr_rotation(struct node *root){
	struct node *t = root -> left;
	root -> left = rr_rotation(t);
	return ll_rotation(root);

}

struct node *rl_rotation(struct node *root){
	struct node *t = root -> right;
	root -> right = ll_rotation(t);
	return rr_rotation(root);
}




struct node * balance(struct node *root){
	int bf = bal_fact(root);

	if (bf > 1){
		if ( bal_fact(root -> left) > 0){
			root = ll_rotation(root);
		}else {
			root = lr_rotation(root);
		}

	}

	if (bf < -1){
		if (bal_fact(root -> right) > 0){
			root = rl_rotation(root);
		}else{
			root = rr_rotation(root);
		}
	}

	return root;

}


struct node * add_node(struct node *root, char *p, int data){

	if (root == NULL){
		return get_node(p, data);
	}

	if (root -> data < data){
		root -> right = add_node(root -> right, p, data);
		root = balance(root);
	}

	if (root -> data > data){
		root -> left = add_node(root -> left, p, data);
		root = balance(root);
	}

	return root;

}

struct node * create_bst(struct node **root){
	int n;
	scanf("%d", &n);

	while (n){
		char t[100];
		scanf("%s", t);
		*root = add_node(*root, t, strlen(t));
		n--;
	}

}

void preorder(struct node *root){

	if (root == NULL){
		return;
	}

	printf("%s : ", root -> c);
	printf("%d :", root -> data);
	printf("%d\n", height(root));
	preorder(root -> left);
	preorder(root -> right);
}

void main(){

	struct node *root = NULL;
	create_bst(&root);
	printf("\n");
	preorder(root);

}
