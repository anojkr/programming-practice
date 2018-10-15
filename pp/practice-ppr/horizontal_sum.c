#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
		int data;
		char c[100];
		struct node *left;
		struct node *right;
};

struct node *get_node(char *c, int item){
		
		struct node *t = (struct node *)malloc(sizeof(struct node));
		
		strcpy(t -> c, c);
		t -> data 	= item;
		t -> left 	= NULL;
		t -> right 	= NULL;

		return t;
}

struct node * add_node(struct node *root, char *c, int item){

		if (root == NULL){
			return get_node(c, item);
		}

		if (root -> data < item){
			root -> right = add_node(root -> right, c, item);
		}

		if (root -> data > item){
			root -> left = add_node(root -> left, c, item);
		}

		return root;
}

struct node * create_bst(struct node **root){

		int n;
		scanf("%d", &n);

		while (n){
			int item;
			char c[100];
			scanf("%d", &item);

			*root = add_node(*root, c, item);
			n--;

		}

}


int height_tree(struct node *root){
	if (root == NULL){
		return 0;
	}

	int l = 1 + height_tree(root -> left);
	int r = 1 + height_tree(root -> right);

	return (l>r)?l:r;
}	

void h_sum(struct node *root, int l, int *sum){

	if (root == NULL){
		return;
	}

	if (l == 0){
		*sum = *sum + root -> data;
	}

	h_sum(root -> left,l-1, sum);
	h_sum(root -> right,l-1, sum);


}

void horizontal_sum(struct node *root){
		int h = height_tree(root);

		for (int i = 0; i < h ; i++){
			int sum = 0;
			h_sum(root, i, &sum);
			printf("%d ",sum );
		}

}



void main(){
	struct node * root = NULL;
	create_bst(&root);
	horizontal_sum(root);

}