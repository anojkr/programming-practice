#include<stdio.h>
#include<stdlib.h>
struct tree {
    int data;
    struct tree *left;
    struct tree *right;
    struct tree *parent;
};

struct tree * newnode(int data){
    struct tree *t = (struct tree *)malloc(sizeof(struct tree));
    t->data = data;
    t->left = NULL;
    t->right = NULL;
    t -> parent = NULL;
    return t;
}

struct tree * insert(struct tree *root,int data){
    if(root == NULL)
        return newnode(data);
    if(data < root->data){
        root->left = insert(root->left,data);
        root->left->parent = root;
        //printf("%d ",root->left->parent->data);
    }
    if(data > root->data){
        root->right = insert(root->right,data);
        root->right->parent = root;
    }
    return root;
}

struct tree * parents(struct tree *root ,int data){
   if(root == NULL)
            return root;
    if (data > root->data)
            return parents(root->right,data);

    if (data < root->data)
            return parents(root->left,data);

    if (data == root->data)
            printf("\n FOUND DATA %d\n", root -> data);
            printf("\n PARENT FOUND DATA %d\n", root -> parent -> data);
            return root;

}

void level_order(struct tree *root, int level){
    struct tree *t = root;

    if (t == NULL){
        return;
    }
    
    if (level == 1){
        printf("%d ", t -> data);
    }
    
    level_order(t->left, level-1);
    level_order(t->right, level-1);
}


void level_operation(struct tree *root, int n){
    struct tree *t = root;
    for (int i = 0;  i < n; i++){
        printf("\n");
        level_order(t, i);
    }

}

void main()
{
    struct tree *root = NULL;
    struct tree *t = NULL;
    int n,a,i;
    scanf("%d",&n);
    int item;
    scanf("%d", &item);
    root = newnode(item);
    for(i=0;i<n-1;i++){
        scanf("%d",&a);
        root = insert(root,a);
    }

    printf("\n");
    level_operation(root, n);

    printf("\nvalue of child=");
    scanf("%d",&a);
    parents(root,a);


}