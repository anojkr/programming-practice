
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
		struct node *k = get_node(data);
		return k;
	}
	
	else if( t -> data <= data ){
		 t -> right = insert_node(t -> right, data);
		 t -> right -> parent  = t; 
	}
	
	else if( t->data > data ){
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

void inorder(struct node *root){
	
	if (root == NULL){
		return;
	}
	
//	if (root->parent != NULL){
		//printf("\nParent = %d\n", root->parent->data);
//	}
	
	inorder(root -> left);
	printf("%d ", root -> data);
	inorder(root -> right);
}

void preorder(struct node *root){
	
	if (root == NULL){
		return;
	}
	
//	if (root->parent != NULL){
		//printf("\nParent = %d\n", root->parent->data);
//	}
	printf("%d ", root -> data);
	preorder(root -> left);
	preorder(root -> right);
}

struct node * search_node(struct node *root, int data){

	if (root == NULL){
		printf("n\n");
		return root;
	}

	if (root -> data == data){
		printf("y\n");
		return root;
	}

	if (root -> data > data){
		return search_node(root -> left, data);
	}

	if (root -> data <= data){
		return search_node(root -> right, data);
	}
}

void search_operation(struct node *root){
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		int item;
		scanf("%d", &item);
		search_node(root, item);
	}
}


void count_leaves(struct node *root, int *count, int *sum){

	if (root == NULL){
		return;
	}	

	if (root -> left == NULL && root -> right == NULL){
		//printf("\nleaf node %d\n", root->data);
		*count = *count + 1;
		*sum = *sum + root -> data;
	}

	count_leaves(root -> left, count, sum); 
	count_leaves(root -> right, count, sum); 
		
}


void main(){
	struct node *root = NULL;
	int n;
	scanf(" %d", &n);
	
	int data;
	scanf(" %d", &data);
	root  = get_node(data);
	
	bst(root, (n-1));
	printf("\n");
	inorder(root);

	printf("\n");
	preorder(root);

	printf("\n");
//	search_operation(root);
//	printf("\ncheck\n");

	int count =0;
	int sum = 0;
	count_leaves(root, &count, &sum);
	printf("\n Leaves in Tree = %d\n Sum of leaves node = %d", count, sum);
}
