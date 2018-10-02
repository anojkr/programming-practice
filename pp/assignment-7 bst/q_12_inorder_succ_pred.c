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

void print_inorder_succ_pred(int *a, int item, int n){

	for (int i = 0; i < n; i++){
		if (a[i] == item){
			printf("\nItem = %d\n", a[i]);
			printf("\nInoder predecessor = %d\n", a[i-1]);
			printf("\nInoder Successor = %d\n", a[i+1]);
			return ;
		}
	}

	printf("Item not in tree");


}

void inorder(struct node * root, int *a, int *i){

	struct node *t = root;

	if (t == NULL){
		return;
	}

	inorder(t -> left, a, i);
	a[*i] = t -> data;
	*i = *i + 1;
	inorder(t -> right, a, i);

}

void print_ll(int *t, int n){
	for (int i = 0; i < n; i++){
		printf("%d ", t[i]);
	}
}

void main(){

	struct node * root = NULL;

	int n;
	scanf("%d", &n);

	bst(&root, n);

	int i = 0;
	int arr[100];

	inorder(root, arr, &i);
	//print_ll(arr, n);
	int item;
	scanf("%d", &item);
	print_inorder_succ_pred(arr, item, n);

}