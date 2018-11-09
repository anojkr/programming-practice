#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 4
#define MIN 2

int t = MIN + 1;

struct block {
	bool leaf;
	int n_keys;
	int keys[MAX];
	struct block *tp[MAX+1];
};

struct btree {
	struct block *root;
};

struct block * get_block()
{
	struct block *t = (struct block *) malloc(sizeof(struct block));
	
	return t;
}

void flush(struct block *root)
{	
	for (int i = 0; i < MAX; i++) {
		root->keys[i] = 0;
		root->tp[i] = NULL;
	}

}

void print(struct block *root)
{	
	for (int i = 0; i < MAX; i++) {
		printf("%d ", root->keys[i]);
	}
	printf("\n");

	for (int i = 0; i < MAX+1; i++) {
		printf("%p ", root->tp[i]);
	}

}

struct block * b_tree_spit_child(struct block *x, int i)
{
	struct block *z = get_block();
	struct block *y = x->tp[i];

	z->leaf = y->leaf;
	z->n_keys = t-1;

	for (int j = 0; j < t; j++) {
		z->keys[j] = y->keys[j + t];
	}

	if (y->leaf == false) {
		for (int j = 0; j <= t; j++) {
			z->tp[j] = y->tp[j + t];
		}
	}

	y->n_keys = t-1;

	for (int j = x->n_keys + 1; j > i; j--) {
		x->tp[j + 1] = x->tp[j];
	}
	x->tp[i + 1] = z;

	for (int j = x->n_keys; j >= i; j--) {
		x->keys[j + 1] = x->keys[j];
	}

	x->keys[i] = y->keys[i];
	x->n_keys = x -> n_keys + 1;

}

struct block * b_tree_insert_nonfull(struct block *x, int k)
{
	int i = x->n_keys-1;

	if (x->leaf == true) {
		while (i >= 0 && k < x->keys[i]) {
			x->keys[i + 1] = x->keys[i];
			i = i - 1;
		}
		x->keys[i + 1] = k;
		x->n_keys = x->n_keys + 1;
		//DISKWRITE
	} else {
		while (i >= 1 && k < x->keys[i]) {
			i = i - 1;
		}
		i = i + 1;
		//DISKWRITE
		if (x->tp[i]->n_keys == MAX) {
			b_tree_spit_child(x, i);
			if (k > x->keys[i]){
				i = i + 1;
			}
		b_tree_insert_nonfull(x->tp[i], k);
		}

	}
}

struct block * insert_key(struct block *root, int key)
{
	if (root->n_keys == MAX){
		struct block *s =  get_block();
		s->leaf = false;
		s->n_keys = 0;
		s->tp[0] = root;
		b_tree_spit_child(s, 0);
		b_tree_insert_nonfull(s, key);
		return s;
		
	} else {
		b_tree_insert_nonfull(root, key);
		return NULL;
	}


}

void main()
{
	struct btree T;
	T.root = get_block();
	T.root->leaf = true;
	T.root->n_keys = 0;
	int n;
	scanf("%d", &n);

	while (n){
		int item;
		scanf("%d", &item);
		struct block *t = insert_key(T.root, item);
		if (t != NULL){
			T.root = t;
		}
		n--;
	}
	// flush((T.root));
	print((T.root));
}