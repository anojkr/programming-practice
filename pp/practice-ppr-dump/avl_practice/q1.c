#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int data;
	char c[100];
	struct node *left;
	struct node *right;
};

struct node * get_node(char *p, int item){
	
	struct node *t = (struct node *)malloc(sizeof(struct node));
	strcpy(t -> c, p);
	t -> data  = item;
	t -> left  = NULL;
	t -> right = NULL;

	return t;
}

int max(int a, int b){
	return (a>b)?a:b;
}

int height(struct node *root){
	if (root == NULL){
		return 0;
	}

	int l = 1 + height(root -> left);
	int r = 1 + height(root -> right);

	return max(l,r);

}

int balance_factor(struct node *root){
	if (root != NULL){

		int bf = height(root -> left) - height(root -> right);
		return bf;

	}

}

struct node *rr_rotation(struct node *root){
	if (root != NULL){
			struct node *t = root -> right;
			root -> right  = t -> left;
			t -> left = root;
			return t;
	}


}

struct node *ll_rotation(struct node *root){
	if (root != NULL){
			struct node *t = root -> left;
			root -> left = t -> right;
			t -> right = root;
			return t;
	}


}

struct node *lr_rotation(struct node *root){
	if (root != NULL){
			struct node *t = root -> left;
			t -> left = rr_rotation(t);
			return ll_rotation(root);
	}



}

struct node *rl_rotation(struct node *root){
		if (root != NULL){
				struct node *t = root -> right;
				root -> right = ll_rotation(t);
				return rr_rotation(root);
		}
}

struct node * balance(struct node *root){
	if (root != NULL){


		int bf = balance_factor(root);

		if (bf > 1){
			if (balance_factor(root -> left)>0){
				root = ll_rotation(root);
			}else {
				root = lr_rotation(root);
			}
		}

		if (bf < -1){
			if (balance_factor(root -> right) > 0){
				root = rl_rotation(root);
			} else {
				root = rr_rotation(root);
			}

		}
		
	}


	return root;

}

struct node *add_node(struct node *root, char *p, int item){

		if (root == NULL){
			return get_node(p, item);
		}

		if (root -> data > item){
			root -> left = add_node(root -> left, p, item);
			root = balance(root);
		}

		if (root -> data < item){
			root -> right = add_node(root -> right, p, item);
			root = balance(root);
		}

		return root;

}


void create_bst(struct node **root){
		int n;
		scanf("%d",&n);

		while(n){

			int item;
			char c[100];
			scanf("%d", &item);
			*root = add_node(*root, c, item);
			n--;
		}

}

void preorder(struct node *root){
	if (root == NULL){
		return;
	}

	printf("%d ", root -> data);
	preorder(root -> left);
	preorder(root -> right);

}

void main(){

	struct node *root = NULL;
	create_bst(&root);

	printf("\n");
	preorder(root);
}

























