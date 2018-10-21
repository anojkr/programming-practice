#include <stdio.h>
#include <stdlib.h>

struct node {
    
        int data;
        struct node *left;
        struct node *right;
    
};

struct node * get_node(int item){
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t -> data  = item;
    t -> left  = NULL;
    t -> right = NULL;
    return t;
}


struct node * search(struct node *root, int item){
    if (root == NULL){
        return NULL;
    }
    if (root != NULL){
        if(root -> data == item){
            return root;
        } 

        struct node * found = search(root -> left, item);
        if ( found != NULL){
            return found;
        } else {
            found = search(root -> right, item);
        }
        return found;
    }
}

void  add_node(struct node *root , int parent, int child, char l_r){
            
        struct node *t = get_node(child);
        struct node *k = search(root, parent);

        if (l_r == 'R'){
            k -> right = t;
         
        } else {

             k -> left = t;
        }
               
}

void mirror(struct node *root){
    if (root == NULL){
        return;
    }

    if (root -> left == NULL && root -> right == NULL){
        return;
    }

    mirror(root -> left);
    mirror(root -> right);

    struct node *t = root -> left;
    root -> left = root -> right;
    root -> right = t; 

}



struct node * clone(struct node * root1, struct node *root2){
    
    if (root1 == NULL){
        return root1;
    }

    root2 = get_node(root1 -> data);
    root2 -> left  = clone(root1 -> left, root2 -> left);
    root2 -> right = clone(root1 -> right, root2 -> right);

    return root2;

}

int create_tree(struct node *root, int n){

    while (n-1){
        int parent;
        int child;
        char l_r;
        scanf("%d", &parent);
        scanf("%d", &child);
        scanf(" %c", &l_r);
        add_node(root, parent, child, l_r);
        n--;

    }
   
}

void preorder(struct node *root){

    if (root == NULL){
        return;
    }

    printf("%d ", root -> data);
    preorder(root -> left);
    preorder(root -> right);

}



void  second_search(struct node *root1, struct node *root2, int item){
    
    if (root1 == NULL || root2 == NULL){
        
        if (root1 == NULL && root2 ==  NULL){
            return;
        }

        if (root1 != NULL && root2 ==  NULL && root1 -> data == item){
            printf("in-1\n");
            return;
        }

        if (root1 == NULL && root2 !=  NULL){
            printf("ou-1\n");
            return;
        }
        return;
    }

    
    if (root1 != NULL){
        if(root1 -> data == item && root2 != NULL){
            printf("%d\n", root2 -> data);
            return;
        } 
        second_search(root1 -> left, root2-> left, item);
        second_search(root1 -> right, root2-> right, item);
    }
}

void second_part(struct node *root1, struct node *root2, int n2){
    while (n2){
        int item;
        scanf("%d", &item);
        second_search(root1, root2, item);
        n2--;
    }


}

void main(){

        struct node *root1 = NULL;

        int n1;
        scanf("%d", &n1);
        
        int n2;
        scanf("%d", &n2);  
        
        root1 = get_node(1);
        create_tree(root1, n1);
        printf("\n");
        //preorder(root1);

        struct node *root2 = NULL;
        root2 = clone(root1, root2);
        mirror(root2);

        // printf("\n");
        //preorder(root2);

        second_part(root1, root2, n2);

}