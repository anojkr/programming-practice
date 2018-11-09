#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define btoa(x) ((x)?"true":"false")
#define t 3

//#define min 2
//#define max 5

int m_k = 5; 		//maximum keys btree node can hold
int m_p = 6; 		//maximum child pointer a btree node can hold

struct node {
	int n;
	bool leaf;
	int keys[5];
	struct node *c[6];
};

void pointer_flush(struct node *root, int MAX)
{	
	for (int i = 0; i <= MAX; i++) {
		root->c[i] = NULL;
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

struct node * get_node(){
	struct node *p = (struct node *) malloc(sizeof(struct node));
	p->leaf = false;
	p->n = 0;
	pointer_flush(p, m_p);

	return p;
}
struct node * create_btree(){
	struct node *p = (struct node *) malloc(sizeof(struct node));
	p->leaf = true;
	p->n = 0;
	
	pointer_flush(p, m_p);

	return p;
}

struct node * btree_split_child(struct node *x, int inx)
{
	struct node *z = get_node();
	struct node *y = x->c[inx];

	z->leaf = y->leaf;
	z->n = t-1;

	for (int j = 0; j < t; j++) {
		z->keys[j] = y->keys[j + t];
	}

	if (y->leaf == false) {
		for (int j = 0; j <= t; j++) {
			z->c[j] = y->c[j + t];
		}
	}

	y->n = t-1;

	for (int j = x->n + 1; j > (inx); j--) {
		x->c[j + 1] = x->c[j];
	}
	x->c[inx+1] = z;

	for (int j = x->n; j >= inx; j--) {
		x->keys[j + 1] = x->keys[j];
	}
	x->keys[inx] = y->keys[t-1];
	x->n = x->n + 1;

}

struct node * btree_insert_nonfull_node(struct node *x, int k) 
{
	int i = x->n-1;

	if (x->leaf == true) {
		while (i >= 0 && k < x->keys[i]) {
			x->keys[i+1] = x->keys[i];
			i = i - 1;
		}
		x->keys[i + 1] = k;
		x->n = x->n + 1;
	} else {
		while (i>=0 && k < x->keys[i]) {
			i = i - 1;
		}
		i = i + 1;
		if (x->n == m_k) {
			btree_split_child(x, i);
			if (k > x->keys[i]){
				i = i + 1;
			}
		}
		btree_insert_nonfull_node(x->c[i], k);
	}
}

struct node * btree_insert_node(struct node *r, int key)
{
	if (r->n == m_k) {
		struct node *s = get_node();
		s->leaf = false; 
		s->n = 0;
		s->c[0] = r;

		btree_split_child(s, 0);
		btree_insert_nonfull_node(s, key);
		return s;

	} else {
		btree_insert_nonfull_node(r, key);
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
		struct node *tp = btree_insert_node(root, item);
		if (tp != NULL) {
			root = tp;
		}
		n--;
	}

	// print(root);
	// print(root->c[0]);
	// print(root->c[1]);
	// print(root->c[2]);
	printf("%d\n", root->n);
	printf("%d\n", root->c[0]->n);
	printf("%d\n", root->c[1]->n);
	//printf("%d\n", root->n)
}