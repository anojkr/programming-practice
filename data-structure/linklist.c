#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *link;
}NODE;

NODE * head = '\0';


NODE * add_node_to_linklist(){
	
	NODE *t = head;
	NODE *p = (NODE*)malloc(sizeof(NODE));
	int data;	
	printf("\nEnter a value of node to inserted in linklist\n");
	scanf("%d", &data);

	if(t == '\0'){
		p -> data = data;
		p -> link = '\0';
		head = p;
		return head;
	
	}
	
	while(t -> link != '\0'){
		t = t->link;
	}
	
	p -> data=data;
	p -> link = '\0';
	t -> link = p; 
	return head;

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

void delete_last_node_from_linklist(NODE * head){
	NODE *t = head;
	while(t->link->link != '\0'){
		t = t->link;
	}

	t->link='\0';
}

void print_linklist(NODE *head){
	struct node *t = head;
	printf("\nItems in linklist are as follows -\n");
	while(t!='\0'){
		printf("%d\n", t->data);
		t=t->link;
	}
}

void create_linklist(int items){
	for(int i=0 ; i< items ; i++){
		 add_node_to_linklist();
	}
}

void main(){
	int items;
	printf("\n Enter numbers of items to be inserted in linklist \n");
	scanf("%d", &items);
	create_linklist(items);
	//search_node(head);
	//delete_last_node_from_linklist(head);
	print_linklist(head);

}
