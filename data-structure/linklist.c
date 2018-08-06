#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *link;
}NODE;

NODE *head;

NODE * create_linklist(){
	int value;
	printf("\nEnter a value of node to inserted in linklist\n");
	scanf("%d", &value);
	struct node *head = (struct node *)malloc(sizeof(struct node));
	head->data =  value;
	head->link = '\0';
	printf("\nLinklist is created\n");
	return head;
}

void add_node_to_linklist(NODE *head){
	int value;
	NODE *t = head;
	NODE *p = (NODE*)malloc(sizeof(NODE));
	while(t->link !='\0'){
		t = t->link;
	}
	printf("\nEnter a value of node to inserted in linklist\n");
	scanf("%d", &value);
	t->link = p;
	p->data = value;
	p->link = '\0';
}


void search_node(NODE *head){
	int i=0;
	int value;
	struct node *t = head;
	printf("\n Enter number you need to search in linklist\n");
	scanf("%d", &value);
	while(t!='\0'){
		i++;
		if(t->data == value){
			printf("\n %d exits in linklist at node postion %d\n",value, i );
			return;
		}
		t=t->link;
		
	}
	printf("\n %d not exits in linklist\n",value);

}

// void remove_given_nodevalue_from_linkllist(struct *head, int value){
// 	struct *t = head;

// 	if (t != '\0'){
// 		while(t->link->data != value){
// 			t = t->link;
// 		}

// 		if (t->link->link != '\0'){
// 			struct *k = t->link;
// 			t->link = t->link->link;
// 			//free(k);
// 		}

// 		//else{//operation to delete node if it's a last node in linklist
// 			//remove_last_node_linklist(struct *head);
// 		//}
// 	}
// }
	



void print_linklist(NODE *head){
	struct node *t = head;
	printf("\nItems in linklist are as follows -\n");
	while(t!='\0'){
		printf("%d\n", t->data);
		t=t->link;
	}
}

void main(){
	head = create_linklist();
	print_linklist(head);
	search_node(head);

}