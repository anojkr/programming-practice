#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define btoa(x) ((x)?"true":"false")
#define MAX 4
#define MIN 2

//int degree = 4; //Maximun no. of keys in btree node.
int child = MAX + 1; //Maximum no. of child pointer in btree node.

struct node {
	bool leaf;
	int n;
	int keys[MAX];
	struct node *c[MAX + 1];
};

void pointer_flush(struct node *root)
{	
	for (int i = 0; i <= MAX; i++) {
		root->c[i] = NULL;
	}

}

struct node * get_node(){
	struct node *ptr = (struct node *) malloc(sizeof(struct node));
	ptr->leaf = false;
	ptr->n = 0;
	pointer_flush(ptr);
	return ptr;
}

struct node * btree_split_child(struct node *x, int i)
{	
	struct node *z = get_node();
	struct node *y = x->c[i];

	z->leaf = y->leaf;
	z->n = MIN;

	for (int j = 0; j < MIN; j++) {
		z->keys[j] = y->keys[j + MIN];
	}

	if (y->leaf == false) {
		for (int j = 0; j<= MIN; j++) {
			z->c[j] = y->c[j + MIN];
		}
	}

	y->n = MIN;

	for (int j = x->n; j > 0; j--) {
		x->c[j + 1] = x->c[j];
	}
	x->c[i+1] = z;

	for (int j = x->n; j >= i; j--) {
		x->keys[j + 1] = x->keys[j];
	}

	x->keys[i] = y->keys[i];
	x->n = x->n + 1; 
}

struct node * btree_insert_nonfull_node(struct node *x, int key)
{	
	int i = (x -> n) - 1; // No. of keys in btree node from index 0 to n-1; 

	if (x->leaf == true){
		while (i >=0 && key < x->keys[i]){
			x->keys[i + 1] = x -> keys[i]; 
			i = i - 1;
		}
		x->keys[i + 1] = key;
		x->n = x->n + 1;

	} else {
		while (i >=0 && key < x->keys[i]){
			i = i - 1;
		}
		i = i + 1;

		if (x->c[i]->n == MAX) {
			btree_split_child(x, i);
			if (key > x->keys[i]){
				i = i + 1;
			}
		}
		btree_insert_nonfull_node(x->c[i], key);
	}
}


struct node * insert_node_btree(struct node *x, int key)
{
		if (x->n == MAX){
			struct node *s = get_node();
			s->leaf = false;
			s->n = 0;
			s->c[0] = x;
			btree_split_child(s, 0);
			btree_insert_nonfull_node(s, key);
			return s;

		} else {
			btree_insert_nonfull_node(x, key);
			return NULL;
		}
}

void print(struct node *root)
{	

	printf("%s\n", btoa(root->leaf));
	for (int i = 0; i < root->n; i++) {
		printf("%d ", root->keys[i]);
	}
	printf("\n");

	for (int i = 0; i < root->n+1; i++) {
		printf("%p ", root->c[i]);
		// print(root->c[i]);
	}

}

void main()
{
	struct node tree;
	struct node *root = &tree;
	root->leaf = true;
	root->n = 0;

	pointer_flush(root);

	int n;
	scanf("%d", &n);

	while (n) {
		int item;
		scanf("%d", &item);
		struct node *t = insert_node_btree(root, item);
		if (t != NULL) {
			root = t;
		}
		n--;
	}
	print(root);
	print(root->c[0]);
	print(root->c[1]);
	print(root->c[2]);
	print(root->c[3]);
	print(root->c[4]);
}