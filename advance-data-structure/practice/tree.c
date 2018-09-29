#include <stdio.h>
#include <stdlib.h>


struct node {

		int data;
		struct node *parent;
		struct node *left;
		struct node *right;

};

struct node * newnode( int item ){
	
			struct node *t = (struct node *)malloc( sizeof( struct node ) );
	
			t -> data  = item;
			t -> left  = NULL;
			t -> right = NULL;
	
			return t;

}	

int deep_right_delete(struct node * root){

		struct node *t;
		struct node *k;
		if ((root -> right -> right) == NULL){
			if (root -> right -> left == NULL){
					t = root -> right;
					root -> right = NULL;
					return t->data;
			}
			else if(root -> right -> left != NULL){
					t = root -> right -> left;
					k = root -> right;
					root -> right = t;
					k -> left = NULL;
					return k->data;
			}

		}

		deep_right_delete(root -> right);

}

struct node *head_g = NULL;
void search_node(struct node *root, int data){
		struct node *t = root;
		
		if (t == NULL){
			return ;
		}

		if(t->data == data){
			head_g = t;
		}

		search_node(t -> left, data);
		search_node(t -> right, data);
}

struct node * delete_node(struct node *root, int data){
			int t = deep_right_delete(root);
			search_node(root, data);
			if (head_g !=  NULL){
				head_g -> data = t;
			} else {

				printf("Node not in tree");
			}
}


void print_ll( struct node * root){
		struct node *t = root;
		if (t == NULL){
			return;
		}
		printf("%d ", t->data );
		print_ll(t -> left);
		print_ll(t -> right);
}

void main(){

	struct node *root = NULL;

	root = newnode(1);
	root -> left  = newnode(2);
	root -> right = newnode(3);
	root -> left -> left = newnode(4);
	root -> left -> right = newnode(5);
	root -> right -> left = newnode(6);
	root -> right -> right = newnode(7);
	printf("\nPre-order Traversal\n");
	print_ll(root);

	delete_node(root, 2);
	printf("\nPre-order Traversal\n");
	print_ll(root);
	printf("\n");

}