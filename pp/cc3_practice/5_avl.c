#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct node {	
	int data;
	char c[100];
	struct node *left;
	struct node *right;
	struct node *parent;
};

struct node * get_node(int data, char *c)
{
	struct node *t = (struct node *) malloc(sizeof(struct node));
	t->data = data;
	strcpy(t->c, c);
	t->left   = NULL;
	t->right  = NULL;
	t->parent = NULL;

	return t;
}


int height(struct node *root){
	if (root == NULL){
		return 0;
	}

	int l = 1 + height(root->left);
	int r = 1 + height(root->right);

	return (l>r)?l:r;

}

struct node * rotate_ll(struct node *r) {
	if (r != NULL) {
		struct node *t = r->left;
		r->left = t->right;
		t->right = r;

		return t;
	}
}

struct node * rotate_rr(struct node *r) {
	if (r != NULL) {
		struct node *t = r->right;
		r->right = t->left;
		t->left = r;

		return t;
	}
}

struct node * rotate_lr(struct node *r){
	if (r != NULL) {
		struct node *t = r->left;
		r->left = rotate_rr(t);
		return rotate_ll(r); 
	}

}

struct node * rotate_rl(struct node *r){
	if (r != NULL) {
		struct node *t = r->right;
		r->right = rotate_ll(t);
		return rotate_rr(r);
	}
}

int bf(struct node *r){
	if (r != NULL){
		return height(r->left) - height(r->right);
	}
}

struct node * balance(struct node *r){

	if (bf(r) > 1) {
		if (bf(r->left) > 0) {
			r = rotate_ll(r);
		} else {
			r = rotate_lr(r);
		}
	}

	if (bf(r) < -1) {

		if (bf(r->right) > 0) {
			r = rotate_rl(r);
		} else {
			r = rotate_rr(r);
		}
	}

	return r;
}

struct node * add_node(struct node *r, int data, char *c)
{
	if (r == NULL) {
		return get_node(data, c);
	} 

	if (r->data < data) {
		r->right = add_node(r->right, data, c);
		r->right->parent = r;
		r = balance(r);
	}

	if (r->data > data) {
		r->left = add_node(r->left, data, c);
		r->left->parent = r;
		r = balance(r);
	}

	return r;
}

void preorder(struct node *r) {
	if (r == NULL) {
		return;
	} else {
		printf("%d ", r->data);
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
		scanf("%d", &data);
		//data = strlen(c);
		root = add_node(root, data, c);
		n--;
	}

	preorder(root);
}