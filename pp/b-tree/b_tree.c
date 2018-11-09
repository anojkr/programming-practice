#include <stdio.h>
#include <stdlib.h>
#define M 4

struct node {
	int id;
	int age;
};

struct keys_data {
	int id;
	struct node *t;
};

struct block {
	int keys;				// Number of keys in block
	int min_keys;			// Minimum number of key allows in block
	struct keys_data k[M];	// value of key or index/search value
	struct block *ptr[M+1];
	int leaf;
};


struct node * get_node(int id, int age){
	struct node *t = (struct node *)malloc(sizeof(struct node));
	t->id = id;
	t->age = age;

	return t;
}

void main() {
	struct block *root = NULL;
	struct block a;
	a.keys = 0;
	a.min_keys = 1
	a.leaf = 1;



}