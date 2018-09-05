#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char string[100];
	struct node * next;
};


struct node * create_linklist(char c[]){
	struct node *head = (struct node *)malloc(sizeof(struct node));
	//head -> string = c;
	strcpy(head->string, c);
	head -> next = NULL;
	return head;
}

void add_node_last(struct node * head , char c[]){
	struct node *t =head;

	struct node *p = (struct node *)malloc(sizeof(struct node));
	strcpy( p->string, c);
	//p -> string = c;
	while ( t->next != NULL ){
		t = t -> next;
	}
		t ->next = p;
		p -> next = NULL;
		//p -> string = c;
	
}
void print_array(struct node * head){
	struct node * t = head;
	while ( t != NULL){
		printf("%s\n", t->string);
		t = t -> next;
	}
}
void main(){

	struct node * head = create_linklist("I AM");
	add_node_last(head, "ANOJ");
	add_node_last(head, "KUMAR");
	add_node_last(head, "IIITA");
	add_node_last(head, "ALLAHABAD");
	print_array(head);

}
