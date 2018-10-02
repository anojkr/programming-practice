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

void preorder(struct node *root){
	struct node *t = root;
	
	if(t == NULL){
		return;
	}
	
	printf("%d ",t->data);
	preorder(t -> l);
	preorder(t -> r);

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



void postorder(struct node *root){

	struct node *t = root;
	if(t == NULL){
		return;
	}
	postorder(t->l);
	postorder(t->r);
	printf("%d ", t->data);
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

int count_leaves(struct node *root, int *sum){
	struct node *t = root;

	if (t == NULL){
		return 0;
	}

	if ( t-> l == NULL && t -> r == NULL){
		*sum = *sum + (t -> data);
		return 1;
	}

	int l = count_leaves(t -> l, sum);
	int r = count_leaves(t -> r, sum);
	return l+r;

}


void path_to_leaves(struct node *root, struct STACK *stack){
		struct node *t = root;
	
		if(t == NULL){

			return;

		}
		
		(stack -> top)++;
		stack -> S[stack -> top] = t -> data;
		
		if (t -> l == NULL && t -> r == NULL){
			printf("\n");
			for (int i = 0; i <= (stack -> top); i++){
				printf("%d ", stack -> S[i]);
			}
		}
		
 		path_to_leaves(t->l, stack);
		path_to_leaves(t->r, stack);
		(stack -> top)--;

}


void mirror_tree(struct node *root){
	struct node *t = root;
	if (t == NULL){
		return;
	}

	mirror_tree(t -> l);
	mirror_tree(t -> r);
	struct node *k = t -> l;
	t -> l = t -> r;
	t -> r = k;

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
	
	printf("\n");
	preorder(root);

	printf("\n");
	inorder(root);

	printf("\n");
	postorder(root);


	printf("\n");
	level_operation(root, n);

	
	int sum = 0;
	printf("\n");
	int k = count_leaves(root, &sum);
	printf("No. OF Leaves = %d \n Leaves sum %d", k , sum);

	path_to_leaves(root, &ST);


	printf("\n");
	int item;
	scanf("%d", &item);
	search(root, item);


	all_ancestor_node(root, item);
	print_inorder_succ_pre(root, item, n);

	// printf("\n");
	// mirror_tree(root);
	// preorder(root);



}
