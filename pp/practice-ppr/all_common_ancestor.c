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


void find_common_ancestors(struct node *root, int a, int b){
		if (root == NULL){
			return;
		}

		if (root -> data < a && root -> data < b){
				//printf("%s\n",t -> c );
				printf("%d ", root -> data);
				return find_common_ancestors(root -> right, a, b);
		}

		if (root -> data > a && root -> data > b){
				//printf("%s\n",t -> c );
				printf("%d ", root -> data);
				return find_common_ancestors(root -> left, a, b);
		}

		if (root -> data >= a && root -> data <= b){
				if (root -> data != a || root -> data != b){
					printf("%d ", root -> data);
				}
				return;
		}

}

void all_common_ancestor(struct node *root){
	int n;
	scanf("%d", &n);

	while (n){
		int s;
		int d;
		
		scanf("%d", &s);
		scanf("%d", &d);

		(s<d)? find_common_ancestors(root, s , d):find_common_ancestors(root, d , s);	

		n--;
	}
}

void main(){
	struct node * root = NULL;
	create_bst(&root);
	all_common_ancestor(root);

}