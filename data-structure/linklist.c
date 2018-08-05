#include<stdio.h>

typedef struct node{
	int data;
	struct node *link
}NODE;

NODE * create_linklist(int value){
	NODE *head = (NODE *)malloc(sizeof(NODE *));
	head->data =  value;
	head->link = '\0';
	return head;
}

void add_node_to_linklist(struct *head){
	int value
	NODE *t = head;
	NODE *p = (NODE *)malloc(sizeof(NODE *));
	while(t->link !='\0'){
		t = t->link;
	}
	printf("Enter a value of node to inserted in linklist\n");
	scanf("%d", &value)
	t->link = p;
	p->data = value;
	p->link = '\0';
}

void remove_given_nodevalue_from_linkllist(struct *head, int value){
	struct *t = head;

	if (t != '\0'){
		while(t->link->data != value){
			t = t->link;
		}

		if (t->link->link != '\0'){
			struct *k = t->link;
			t->link = t->link->link;
			free(k);
		}

		else{//operation to delete node if it's a last node in linklist
			remove_last_node_linklist(struct *head);
		}
	}
	
}


void remove_last_node_linklist(struct *head){
	

}

void main(){

}