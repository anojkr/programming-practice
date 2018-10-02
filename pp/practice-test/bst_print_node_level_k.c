#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * left;
	struct node * right;
	struct node * parent;
};
int n;


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

struct node * bst(struct node **root, int n){

	for (int i = 0; i < n; i++){
		int data;
		scanf("%d", &data);
		*root = insert_node(*root, data);
		printf("\n%d\n", (*root) -> data );
	}

}

void preorder(struct node *t, int level){
	
	if (t == NULL){
		return;
	}
	if (level == 1){
		printf("%d ", t->data );
	}
	preorder(t->left, level-1);
	preorder(t->right, level-1);

}



void main(){
	struct node *root = NULL;
	scanf("%d", &n);

	
	bst(&root, (n));


	int level;
	scanf("%d", &level);

//	printf("\nInorder\n");
//	preorder(root, level);

}
