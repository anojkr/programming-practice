#include <stdio.h>
#include <stdlib.h>

struct node {

	int data;
	struct node *left;
	struct node *right;
	struct node *parent;

};

struct STA {
	int top;
	int S[100];
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

void print_root_to_leave_path(struct node * root, struct STA * stack){

	struct node *t = root;

	if (t == NULL){
		return;
	}

	(stack -> top)++;
	stack -> S[stack -> top] = t -> data;

	if (t -> left ==  NULL && t -> right == NULL){
		printf("\n");
		for (int i = 0; i <= stack -> top; i++) {
			printf("%d ",stack -> S[i]);
		}
	}

	print_root_to_leave_path(t -> left, stack);
	print_root_to_leave_path(t -> right, stack);
	stack -> S[stack -> top] = -1;
	(stack -> top)--;

}

void main(){

	struct node * root = NULL;
	struct STA stack;
	stack.top = -1;

	int n;
	scanf("%d", &n);

	bst(&root, n);
	print_root_to_leave_path(root, &stack);

}