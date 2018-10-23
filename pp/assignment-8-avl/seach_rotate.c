#include <stdio.h>
#include <stdlib.h>

struct node {
	char c;
	struct node * left;
	struct node * right;
	struct node * parent;

};

struct node * get_node(char c){

	struct node *t = (struct node *)malloc(sizeof(struct node));
	t -> c = c;
	t -> left  = NULL;
	t -> right = NULL;
	return t;
}


struct node * add_node(struct node *root, char item){

	if (root == NULL){
		return get_node(item);
	}

	if (root -> c < item){
		root -> right = add_node(root -> right, item);
		root -> right -> parent =  root;
	}

	if (root -> c > item){
		root -> left = add_node(root -> left, item);
		root -> left -> parent = root;
	}

	return root;

}

void create_bst(struct node **root){

	int n;
	scanf("%d", &n);

	while(n){

		char c;
		scanf(" %c", &c);
		*root = add_node(*root, c);
		n--;
	}

}

int height(struct node *root){
	if (root == NULL){
		return 0;
	}

	if (root -> left == NULL && root -> right == NULL){
		return 0;
	}

	int l = 1+ height(root -> left);
	int r = 1+ height(root -> right);

	return (l>r)?l:r;

}



struct node * rotate_op(struct node *root, char item){
	if (root == NULL){
		return root;
	}


	if (item == 'r'){
		struct node *t = root -> left;
		root -> left = t -> right;
		t -> right = root;
		root -> parent -> left = t;
		return t;
	}
	if (item == 'l'){
		struct node *m = root -> right;
		root -> right = m  -> left;
		m -> left = root;
		root -> parent -> right = m;
		return m;
	}

}




struct node * search(struct node *root, char item, char rotate){
	if (root == NULL){
		return root;
	}

	if (root ->c < item){
		return search(root -> right, item, rotate);
	}

	if (root -> c > item){
		return search (root -> left, item, rotate);
	}

	if (root -> c == item){
		if (root -> parent != NULL){
							
				rotate_op(root, rotate);
				return NULL;
			}
		 
		if (root -> parent == NULL) {
			root = rotate_op(root, rotate);
		}

		return root;
	}

}

void preorder(struct node *root){

	if (root == NULL){
		return;
	}

	printf("%c ", root -> c);
	preorder(root -> left);
	preorder(root -> right);
}

void main(){

	struct node * root = NULL;
	create_bst(&root);
	char item, rotate;
	scanf(" %c", &item);
	scanf(" %c", &rotate);

	preorder(root);
	struct node *x = search(root, item,  rotate);	

	if (x != NULL){
		root = x;
	}
	printf("\n");
	preorder(root);
	
	


}






















