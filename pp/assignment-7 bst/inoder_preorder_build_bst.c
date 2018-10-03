#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node * left ;
    struct node * right;
};
struct node * newnode(int d){
    struct node * nn = (struct node *)malloc(sizeof(struct node));
    nn->data = d;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}
void preorder(struct node * r){
    if(r){
        printf("%d ",r->data);
        preorder(r->left);
        preorder(r->right);
    }
}
int search(int in[],int start,int end,int xdata){
    for(int i=start;i<=end;i++){
        if(in[i]==xdata){
            return i;
        }
    }
}
struct node * buildtree(int in[],int post[],int start,int end,int* p){
    if(start>end){
        return NULL;
    }
    struct node * x = newnode(post[*p]);
    (*p)--;
    if(start==end){
        return x;
    }
    int index = search(in,start,end,x->data);
    x->right = buildtree(in,post,index+1,end,p);
    x->left = buildtree(in,post,start,index-1,p);
    return x;
}

int main()
{
    int in[]={4,8,2,5,1,6,3,7};
    int post[]={8,4,5,2,6,7,3,1};
    int n = sizeof(in)/sizeof(int);
    printf("%d",n);
    int p = n-1;
    struct node * root = buildtree(in,post,0,n-1,&p);
    printf("\npreorder is :\n");
    preorder(root);
   return 0;
}