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

struct node * add_node(struct node *root, char *p, int data){

	if (root == NULL){
		return get_node(p, data);
	}

	if (root -> data < data){
		root -> right = add_node(root -> right, p, data);

	}

	if (root -> data > data){
		root -> left = add_node(root -> left, p, data);
	}

	return root;

}


int distance_root_to_node(struct node *root, int a){

			if (root == NULL){
				return 0;
			}

			if (root -> data < a){
				return 1 + distance_root_to_node(root -> right, a);
			}

			if (root -> data > a){
				return 1 + distance_root_to_node(root -> left, a);

			}

			if (root -> data == a){
				return 0;
			}
}

int min_distance_btw_nodes(struct node * root, int a, int b){

		if (root == NULL){
			return 0;
		}

		if(root -> data > a && root -> data > b){
				return min_distance_btw_nodes(root -> left, a , b);
				
		}

		if (root -> data < a && root -> data < b){
				return min_distance_btw_nodes(root -> right, a, b);
				
		}

		if (root -> data >= a && root -> data <=b){
				return (distance_root_to_node(root, a) + distance_root_to_node(root, b));
		}


}


struct node * create_bst(struct node **root){
	int n;
	scanf("%d", &n);

	while (n){
		char t[100];
		int item;
		scanf("%d", &item);
		//scanf("%s", t);
		*root = add_node(*root, t, item);
		n--;
	}

}

void preorder(struct node *root){

	if (root == NULL){
		return;
	}

	//printf("%s : ", root -> c);
	printf("%d ", root -> data);
	//printf("%d\n", height(root));
	preorder(root -> left);
	preorder(root -> right);
}

void main(){

	struct node *root = NULL;
	create_bst(&root);
	printf("\n");
	preorder(root);

	int n;
	scanf("%d", &n);

	while (n){
		int a, b;
		scanf("%d", &a);
		scanf("%d", &b);
		(a< b)?printf("%d ",min_distance_btw_nodes(root, a, b)):printf("%d ",min_distance_btw_nodes(root, b, a));
		n--;
	}

	

}
