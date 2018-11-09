#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define btoa(x) ((x)?"true":"false")

// int c_min = t;
// int c_max = (2 * t);

// int k_min = t - 1;
// int k_max = (2 * t) - 1;

int t = 3;

struct node {
	int n;
	bool leaf;
	int keys[6];
	struct node * C[7];
};

void pointer_flush(struct node *r)
{	
	for (int i = 0; i <= 2*t; i++) {
		r->C[i] = NULL;
	}
}

void print(struct node *root)
{	
	printf("\n");
	printf("%s\n", btoa(root->leaf));
	for (int i = 1; i <= root->n; i++) {
		printf("%d ", root->keys[i]);
	}
	printf("\n");

	for (int i = 1; i <= root->n+1; i++) {
		printf("%p ", root->C[i]);
		// print(root->c[i]);
	}
	printf("\n");

}

struct node * create_btree()
{
	struct node *p = (struct node *) malloc(sizeof(struct node));
	p->leaf = true;
	p->n = 0;
	pointer_flush(p);
	return p;
}

struct node * get_node()
{
	struct node *p = (struct node *) malloc(sizeof(struct node));
	pointer_flush(p);
	return p;
}

struct node * btree_split_child(struct node *x, int i) 
{	
	struct node *z = get_node();
	struct node *y = x->C[i];
	z->leaf = y->leaf;
	z->n = t-1;
	for (int j = 1; j < t; j++) {
		z->keys[j] = y->keys[j+t];
	}
	if (y->leaf == false) {
		for (int j = 1; j <= t; j++) {
			z->C[j] = y->C[j+t];
		}
	}
	y->n = t-1;

	for (int j = x->n + 1; j > i; j--) {
		x->C[j+1] = x->C[j];
	}
	x->C[i+1] = z;

	for (int j = x->n; j >= i; j--) {
		x->keys[j+1] = x->keys[j];
	}
	x->keys[i] = y->keys[t];
	x->n = x->n + 1;

}

struct node * btree_insert_nonfull(struct node *x, int k)
{
	int i = x->n;
	if (x->leaf == true) {
		while (i>=1 && k < x->keys[i]) {
			x->keys[i+1] = x->keys[i];
			i = i - 1;
		}
		x->keys[i + 1] = k;
		x->n = x->n + 1;
	} else {
		while (i>=1 && k < x->keys[i]) {
			i = i - 1;
		}
		i = i + 1;
		if (x->C[i]->n == (2*t)-1) {
			btree_split_child(x, i);
			if (k > x->keys[i]) {
				i = i + 1;
			}
		}
		btree_insert_nonfull(x->C[i], k);
	}
}

struct node * btree_insert_node(struct node *root, int k){
	struct node *r = root;
	if (r->n == ((2*t)-1)) {
		struct node *s = get_node();
		s->leaf = false;
		s->n = 0;
		s->C[1] = r;
		btree_split_child(s, 1);
		btree_insert_nonfull(s, k);

		return s;
	} else {
		btree_insert_nonfull(r, k);
		return NULL;
	}

}

void main()
{
	struct node *root = create_btree();
	int n;
	scanf("%d", &n);

	while (n) {
		int item;
		scanf("%d", &item);
		struct node *ptr = btree_insert_node(root, item);
		if (ptr != NULL){
			root = ptr;
		}
		n--;
	}
	print(root);
	for (int j=0; j<=7; j++) {
		if (root->C[j]!= NULL){
			print(root->C[j]);
		}
	}

}