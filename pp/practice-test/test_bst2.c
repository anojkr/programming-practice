#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int data;
	struct node *l;
	struct node *r;
	struct node * parent;
};

struct STACK {
	int top;
	int S[100];
};

void flush(struct STACK *ST){
	for (int i = 0; i< 100; i++){
		ST->S[i] = 0;
	}	
}

struct node * get_node(int item){
	struct node *t = (struct node *)malloc(sizeof(struct node));
	t -> data = item;
	t -> l = NULL;
	t -> r = NULL;
	return t;
}

struct node * search(struct node * root, int item){
	struct node *t = root;
	if (t == NULL){
		printf("\nDATA NOT FOUND\n");
		return NULL;
	}
	
	if (t -> data == item){
		printf("\nDATA FOUND = %d\n", t->data);
		return t;
	} 

	else {
		if (t-> data < item){
			return search(t -> r, item);
		}

		if (t -> data >= item){
			return search(t -> l, item);
		}
	}

}

struct node * add_node_bst(struct node *root, int item){
	struct node *t = root;

	if (t == NULL)
	{
		struct node *k = get_node(item);
		return k;
	}

	if (t -> data < item){
		t -> r =  add_node_bst(t->r, item);
		t -> r -> parent = t;
	}

	if (t -> data >= item){
		t -> l = add_node_bst(t->l, item);
		t -> l -> parent = t;	
	}
	
	return t;

}


int cn = -1;
int sorted_arr[100];
void inorder(struct node *root){

	struct node *t = root;
	if(t == NULL){
		return;
	}
	inorder(t->l);
	cn++;
	sorted_arr[cn] = t -> data;
	printf("%d ", t->data);
	inorder(t->r);
}



void level_order(struct node *root, int level){
	struct node *t = root;

	if (t == NULL){
		return;
	}
	
	if (level == 1){
		printf("%d ", t -> data);
	}
	
	level_order(t->l, level-1);
	level_order(t->r, level-1);
}


void level_operation(struct node *root, int n){
	struct node *t = root;
	for (int i = 0;  i < n; i++){
		level_order(t, i);
	}

}

int print_inorder_succ_pre(struct node *root, int item, int n){
	struct node *t = root;
	int flag = 0;
	int num = 0;
	for (int i = 0; i < n; i++){
		if ( sorted_arr[i] == item){
			flag = 1;
			num = sorted_arr[i-1];
			printf("Inorder Predecessor = %d\n", num);
			printf("Inorder Successor = %d\n", sorted_arr[i+1]);
		}
	}

	if (flag == 0){
		printf("Item not present");
	}

	return num;
}

// void delete_node(struct node *root, int item, int n){
// 	struct node *t = root;
// 	if (t == NULL){
// 		return;
// 	}

// 	struct node *k = search(root, item);
// 	int inorder_prede  = print_inorder_succ_pre(root, item, n);
// 	k -> data = inorder_prede;
// 	struct node * m = search(root, inorder_prede);
	

// 	if (m -> l == NULL && m -> r == NULL){
// 		m -> parent -> r = NULL;
// 	}

// 	if (m -> l != NULL & m -> r == NULL){
// 		m -> parent -> r = m -> l;
// 	}

	

// }

void delete_node(struct node *root, int item, int n){
	struct node *t = root;
	if (t == NULL){
		return;
	}

	struct node *k = search(root, item);
	struct node *temp = k -> l;

	while (temp -> r != NULL){
		temp = temp -> r;
	}

	k -> data = temp -> data;

	if (temp -> l != NULL){
		temp -> parent -> r = temp -> l;
	}

	if (temp -> l == NULL  && temp -> r == NULL){

		temp -> parent -> l = NULL;
	}
	

}

void all_ancestor_node(struct node * root, int item){

	struct node *t = search(root, item);
	printf("\nAll Ancestor Node \n");

	if (t == NULL){
		return;

	}

	while(t -> parent != NULL){
			printf("%d ", t -> parent -> data );
			t = t -> parent;
	}

	printf("\n");

}


void main(){

	struct node *root = NULL;
	struct STACK ST;
	ST.top = -1;	
	flush(&ST);

	int n;
	scanf("%d", &n);

	struct node a;
	scanf("%d", &(a.data));
	a.l = NULL;
	a.r = NULL;
	a.parent = NULL;
	root = &a;


	
	for (int i = 0; i < n-1; i++){
		int item;
		scanf("%d", &item);
		add_node_bst(root, item);
	}
	

	printf("\nInorder\n");
	inorder(root);

	// printf("\n");
	// int r;
	// scanf("%d", &r);
	// all_ancestor_node(root, r);


	// printf("\n");
	// int k;
	// scanf("%d", &k);
	// print_inorder_succ_pre(root, k, n);


	// printf("\n");
	// int item;
	// scanf("%d", &item);
	// level_order(root, item);

	printf("\n");
	level_operation(root, n);

	printf("\n");
	int d;
	scanf("%d", &d);
	delete_node(root, d, n);

	printf("\n");
	level_operation(root, n);

}
