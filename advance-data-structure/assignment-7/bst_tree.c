#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
}NODE;

NODE *root;

NODE * create_root_node(int value){
	NODE * r= (NODE *)malloc(sizeof(NODE));
	r->data = value;
	r->left = '\0';
	r->right= '\0';
	return r;
}

NODE * search_node(NODE * root, int value){
	if (root == '\0'){
		printf("%d not exist in the BST\n", value);
		return root;
	}
	if (root->data == value){
		printf("%d exist in the BST\n", value);
		return root;
	}
	if (root->data < value){
		return search_node(root->right, value);
	}

	if (root->data > value){
		return search_node(root->left, value);
	}

}

NODE * insert_node_to_bst(NODE *t, int value){

	if (t=='\0'){
		return create_root_node(value);
	}
	if(t->data < value){
		t->right = insert_node_to_bst(t->right, value);
	}
	
	if(t->data > value){
		t->left = insert_node_to_bst(t->left, value);
	}
	return t;

}

void inorder(NODE *root){
    if(root == NULL){
    		return;
    }

    inorder(root->left);
    printf("%d ->", root->data);
    inorder(root->right);
}

void preorder(NODE *root){
    if(root == NULL){
    		return;
    }
    printf("%d ->", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(NODE *root){
	if(root == NULL){
    		return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ->", root->data);

}

void main(){
	int data, n, value, search_item;
	printf("\nEnter element to create root node\n");
	scanf("%d", &data);
	root = create_root_node(data);

	printf("\nEnter number of nodes to be added in BST\n");
	scanf("%d", &n);

	for(int i=0; i<n; i++){
	printf("Enter value to be inserted in BST\n");
	scanf("%d",&value);
	insert_node_to_bst(root, value);
	}

	printf("Enter value to be search in BST\n");
	scanf("%d",&search_item);
	search_node(root, search_item);
	// printf("\n Inorder BST\n");
	// inorder(root);
	// printf("\n Postorder BST\n");
	// preorder(root);
	// printf("\n Preorder BST\n");
	// postorder(root);
}
