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

void preorder(struct node *r) {
	if (r == NULL) {
		return;
	} else {
		printf("%s\n", r->c);
		preorder(r->left);
		preorder(r->right);
	}
}

void main() 
{
	struct node *root = NULL;
	int n;
	scanf("%d", &n);

	while (n) {
		int data;
		char c[100];

		scanf("%s", c);
		data = strlen(c);

		root = add_node(root, data, c);
		n--;
	}

	preorder(root);
}













