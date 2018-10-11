#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node {
	char *c;
	int data;
	struct node * left;
	struct node * right;
	struct node * parent;
};

struct node * get_node(char *p, int item){

	struct node *t = (struct node *)malloc(sizeof(struct node));
	t -> c 	    = p;
	t -> data   = item;
	t -> left   = NULL;
	t -> right  = NULL;
	t -> parent = NULL;

	return t;
}

struct node * search(struct node * root){

	struct node *t = root;

	if (t == NULL){
		return NULL;
	}
	
	if (t -> data > item){
		return search(t -> left, item);
	}

	if (t -> data < item){
		return search(t -> right, item);
	}

	if (t -> data == item){
		return t;
	}

}

struct node * add_node(struct node *root, char *p, int item){

	struct node *t = root;

	if (t == NULL){
	
		return get_node(p, item);
	}

	if (t -> data > item){
		t -> left = add_node(t -> left, p, item);
	}

	if (t -> data < item){
		t -> right = add_node(t -> right, p, item);
	}

	return t;
}


char * my_string(int len){

	char *p = (char *)malloc(sizeof(char)*len);
	return p;
}



void bst_create(struct node **root){
	int n;
	scanf("%d", &n);

	while (n){
	
		char c[100];
		scanf("%s", c);
		int item = strlen(c);
		char *p = my_string(item);
		strcpy(p, c);
		*root = add_node(*root, p, item);
		n--;
	}
}

void preorder(struct node *root){
	struct node *t = root;

	if (root == NULL){
		return;
	}

	printf("\n%s", t -> c);
	printf("%d\n", t -> data);
	preorder(t -> left);
	preorder(t -> right);
}

int height (struct node * root){
	struct node *t = root;

	if (t == NULL){
		return 0;
	}
	
	
	int l = height (t -> left);
	int r = height (t -> right);

	if (l < r){
		return 1 + r;
	}else {
		return 1 + l;
	}

}

void main(){
	struct node * root = NULL;
	bst_create(&root);
	preorder(root);
	int h = height(root);
	printf("Height = %d", h);
}
