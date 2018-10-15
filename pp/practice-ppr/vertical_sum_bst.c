#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
		int data;
		int info;
		char c[100];
		struct node *left;
		struct node *right;

};

struct node *get_node(char *c, int item){
		
		struct node *t = (struct node *)malloc(sizeof(struct node));
		
		strcpy(t -> c, c);
		t -> data 	= item;
		t -> left 	= NULL;
		t -> right 	= NULL;
		return t;

}

struct hash_node{
	int data;
	int info;
	struct hash_node *next;
};


struct hash_node * get_hash_node( int data, int info){
	struct hash_node *t = (struct hash_node *)malloc(sizeof(struct hash_node));
	t -> data = data;
	t -> info = info;
	t -> next = NULL;
	return t;
}

struct node * add_node(struct node *root, char *c, int item){

		if (root == NULL){
			return get_node(c, item);
		}

		if (root -> data < item){
			root -> right = add_node(root -> right, c, item);
		}

		if (root -> data > item){
			root -> left = add_node(root -> left, c, item);
		}

		return root;

}

struct node * create_bst(struct node **root, int n){


		while (n){
			int item;
			char c[100];
			scanf("%d", &item);
			*root = add_node(*root, c, item);
			n--;

		}

}


void vertical_sum(struct node *root){

	if (root == NULL){
		return;
	}

	if (root -> left != NULL){
		root -> left -> info = root -> info - 1;
	}

	if (root -> right != NULL){
		root -> right -> info = root -> info + 1;
	}

	vertical_sum(root -> left);
	vertical_sum(root -> right);

}


void vertical_sum_cal(struct hash_node *head[100], struct node * root, int k){

		if (root == NULL){
			return;
		}

		if (root -> info < 0){
			root -> info = root -> info + k;
		}

		if (head[root -> info] == NULL){
			struct hash_node *p = get_hash_node(root -> data, root -> info);
			head[root -> info] = p;
			p -> next =  NULL; 
		}

		else {

			struct hash_node *t = head[root -> info];

			while (t -> next != NULL){
				t = t -> next;
			}
			struct hash_node *p = get_hash_node(root -> data, root -> info);
			t -> next = p;
			p -> next = NULL;
		}

		vertical_sum_cal(head, root -> left, k);
		vertical_sum_cal(head, root -> right, k);
	
} 


void printhash_table(struct hash_node *a[100]){

	for (int i=99 ; i >=0 ; i--){
		if(a[i] != NULL){
			printf("\n");
			struct hash_node *t = a[i];
			int sum = 0;
			while (t != NULL){
				sum = sum + t -> data;
				t = t -> next;
			}
			printf("sum : %d", sum);
		}
	}

}



void main(){
	struct node * root = NULL;
	int n;
	scanf("%d", &n);
	create_bst(&root, n);
	root -> info = 0;
	vertical_sum(root);

	struct hash_node *a[100];

	for (int i = 0; i < 100; i++){
		a[i] = NULL;
	}


	vertical_sum_cal(a, root, n*2);
	printhash_table(a);

}