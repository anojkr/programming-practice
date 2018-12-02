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

struct node * get_node(int data, char *c) {
	struct node *t = (struct node *) malloc(sizeof(struct node));
	t->data = data;
	strcpy(t->c, c);
	t->left = NULL;
	t->right = NULL;
	t->parent = NULL;
}

struct node * add_node(struct node *r, int data, char *c) 
{
	if (r == NULL) {
		return get_node(data, c);
	}

	if (r->data < data) {
		r->right = add_node(r->right, data, c);
		r->right->parent = r;
	}

	if (r->data > data) {
		r->left = add_node(r->left, data, c);
		r->left->parent = r;
	}

	return r;
}

struct node * search(struct node *r, int data){
	if (r == NULL) {
		return r;
	}

	if (r->data > data) {
		return search(r->left, data);
	}

	if (r->data < data) {
		return search(r->right, data);
	}

	if (r->data == data) {
		return r;
	}

}

void preorder(struct node *r) {
	if (r == NULL) {
		return;
	} else {
		printf("%d\n", r->data);
		preorder(r->left);
		preorder(r->right);
	}
}

struct node * rotate_rr(struct node *r){
	if (r == NULL){
		return r;
	} else {
		struct node *t = r->left;
		
	}
}

struct node * rotate(struct node *r) {
	int data;
	scanf("%d", &data);

	struct node *t = search(r, data);

}

void main() 
{
	struct node *root = NULL;
	int n;
	scanf("%d", &n);

	while (n) {
		int data;
		char c[100];

		scanf("%d", &data);
		//data = strlen(c);

		root = add_node(root, data, c);
		n--;
	}

	preorder(root);

	rotate(r);
}













