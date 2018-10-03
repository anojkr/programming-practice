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


struct node *root = NULL
void build_tree(int *in, int *post, start, end, int p){

	if (start > end){
		return
	}
	
	*root = insert_node(root, )

}


void main(){
    
    int in[]={4,8,2,5,1,6,3,7};
	int post[]={8,4,5,2,6,7,3,1};
	int p = n-1;
	int size = sizeof(in)/sizeof(in[0]);
	int start = 0;
	int end = SIZE-1;
	build_tree(in, post, start, end, p)

}