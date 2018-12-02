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

int height(struct node *r) {

	if (r != NULL){
		int left  = 1 + height(r->left); 
		int right = 1 + height(r->right);

		return (left>right?left:right);
	}

}

int distance(struct node *r, int a) {
	if (r == NULL){
		return 0;
	} 

	if (r->data < a){
		return 1 + distance(r->right, a);
	}

	if (r->data > a){
		return 1 + distance(r->left, a);
	}

	if (r->data == a) {
		return 0;
	}
}

int min_dis(struct node *r, int a, int b){

	if (r == NULL){
		return 0;
	}

	if (r->data > a && r->data > b) {
		return min_dis(r->left, a, b);
	}

	if (r->data < a && r->data < b ) {
		return min_dis(r->right, a, b);
	}

	if (r->data >= a && r->data <= b) {
		int len = distance(r, a) + distance(r, b);
		printf("test = %d\n", len);
		return len;
	}

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
		printf("%d\n", r->data);
		preorder(r->left);
		preorder(r->right);
	}
}

void swap(int *a, int *b){
	if (*a > *b) {
		int t = *a;
		*a = *b;
		*b = t;
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

	int a;
	int b;
	scanf("%d %d", &a, &b);

	//swap(&a, &b);
	min_dis(root, a, b);
}













