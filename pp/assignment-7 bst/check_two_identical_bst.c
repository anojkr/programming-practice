#include <stdio.h>
#include <stdlib.h>

struct node {

	int data;
	struct node *left;
	struct node *right;
	struct node *parent;

};

struct node * get_node(int item){
	struct node *t = (struct node *)malloc(sizeof(struct node));
	
	t -> data   = item;
	t -> left   = NULL;
	t -> right  = NULL;
	t -> parent = NULL;

	return t;

}


struct node * insert_node(struct node *root, int item){
	
	struct node *t = root;
	
	if (t == NULL){
		return get_node(item);
	}

	if (t -> data < item){
		t -> right = insert_node(t -> right, item);
		t -> right -> parent = t;
	}

	if (t -> data > item){
		t -> left = insert_node(t -> left, item);
		t -> left -> parent = t;
	}

	return t;

}

struct node * search(struct node *root, int item){
	struct node *t = root;

	if (t == NULL){
		printf("Data Not Found");
		return t;
	}

	if (t -> data < item){
		return search(t -> right, item);
	}

	if (t -> data > item){
		return search(t -> left, item);
	}

	if (t -> data == item){
		printf("Data Found = %d", t -> data);
		return t;
	}

}

void bst(struct node **root, int n){
	struct node *t = *root;
	for (int i = 0 ; i < n ; i++){
		int item;
		scanf("%d", &item);
		*root = insert_node(*root, item);
	}

}

int check_bst_identical(struct node *root1, struct node * root2){
	
	if (root1 == NULL  && root2 == NULL){
		return 1;
	}

	if (root1 -> data == root2 -> data){
	
		check_bst_identical(root1 -> left, root2 -> left);
		check_bst_identical(root1 -> right, root2 -> right);
	
	} else {
	
		return 0;
	
	}

}


void main(){

	struct node * root1 = NULL;

	int n;
	scanf("%d", &n);

	bst(&root1, n);

	struct node * root2 = NULL;
	
	bst(&root2, n);

	int m = check_bst_identical(root1, root2);
	if (m == 0){
		printf("bst not identical");
	} else{
		printf("bst identical");
	}
	
}