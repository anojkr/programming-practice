#include <stdio.h>
#include <stdlib.h>

struct node {

	int data;
	struct node * left;
	struct node * right;
	struct node * parent;

};

struct queue {
	int front;
	int rear;
	int a[100];
};

struct node * get_node(int item){
	
	struct node *t = (struct node *)malloc(sizeof(struct node));
	t -> data   = item;
	t -> left   = NULL;
	t -> right  = NULL;
	t -> parent = NULL;

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
			return search(t -> right, item);
		}

		if (t -> data >= item){
			return search(t -> left, item);
		}
	}

}

struct node * add_node(struct node * root, int item){
	struct node *t = root;
	if (root == NULL){
		return get_node(item);
	}

	if (t -> data > item){
		t -> left  = add_node(t -> left, item);
		t -> left -> parent = t;
	}

	if (t -> data < item){
		t -> right = add_node(t -> right, item);
		t -> right -> parent = t;
	}

	return t;

}

void create_bst(struct node **root){
	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int item;
		scanf("%d", &item);
		*root = add_node(*root, item);
	}

}

void preorder(struct node *root){
	struct node *t = root;
	if(root == NULL){
		return;
	}

	printf("%d ", t -> data);
	preorder(t -> left);
	preorder(t -> right);

}

void delete_opeartion(struct node *k, struct node * root){
	struct node *t = k;
	
	if (t -> left == NULL && t -> right == NULL){
		printf("check-3\n");
			if (root != NULL){
				root -> data = t -> data;
			}
			if (t -> parent ->left != NULL){
				if (t -> parent -> left -> data == t -> data){
					t -> parent -> left = NULL;
				}
			}

			if (t -> parent -> right != NULL){
				if (t -> parent -> right -> data ==  t -> data){
					t -> parent -> right = NULL;
				}
			}

	}

3	if (t -> left == NULL && t -> right != NULL){
		if (root != NULL ){
			root -> data = t -> data;
		}
		t -> parent -> right = t -> right;
		printf("check-1\n");
		return;
	}

	if (t -> right ==  NULL && t -> left != NULL){
		if (root != NULL){
			root -> data = t -> data;
		}
		t -> parent -> left = t -> left;
		printf("check-2\n");
		return;
	}

	return;

}

void delete_node(struct node *root, int item){
	struct node *t = search(root, item);

	if (t == NULL){
		return;
	}

	delete_opeartion(t, NULL);

	if (t -> left != NULL && t-> right != NULL){
		struct node *k = t -> right;

		while (k-> left != NULL){
			k = k -> left;
		}
		delete_opeartion(k , t);
	}

}


void bfs(){

}

void main(){
	struct node * root = NULL;
	create_bst(&root);
	printf("\n");
	preorder(root);

	struct queue Q;
	Q.front = -1;
	Q.rear 	= -1;

	

	// int d;
	// scanf("%d", &d);
	// while(d){
	// 	int item;
	// 	scanf("%d", &item);
	// 	delete_node(root, item);
	// 	d--;
	// }

//	preorder(root);

}
























