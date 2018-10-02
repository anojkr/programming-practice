#include <stdio.h>
#include <stdlib.h>

struct node {
	
	int data;
	struct node * left;
	struct node * right;

};


struct node * newnode(int item){
	struct node *t = (struct node *)malloc(sizeof(struct node ));
	t -> left  = NULL;
	t -> right = NULL;
	t -> data  = item; 
	return t;
}

struct node * bst_tree( struct node * root, int item){
		if (root == NULL){
			root = newnode(item);
			return root;
		}

		if (root -> data > item){
			root -> left = bst_tree(root -> left, item);
		}

		if (root -> data <= item){
			root -> right = bst_tree(root -> right, item);
		}

		//return root;

}


void inorder( struct node *t){
	if (t == NULL){
		return;
	}

	inorder(t -> left);
	printf("%d ", t -> data);
	inorder(t -> right);

}

void preorder( struct node *t){
	if (t == NULL){
		return;
	}
	printf("%d ", t -> data);
	preorder(t -> left);
	preorder(t -> right);

}

void postorder( struct node *t){
	if (t == NULL){
		return;
	}

	postorder(t -> left);
	postorder(t -> right);
	printf("%d ", t -> data);

}

void preorder_stack( struct node *t, int n){
	stack[n];

	


}

void main(){
	struct node *root = newnode(1);

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		int item;
		scanf("%d", &item);
		bst_tree(root, item);
		
	}


}