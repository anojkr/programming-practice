#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int data;
	struct node * next;
};

struct store {
	struct node * node_link;
};

struct store arr[100];

struct node * create_linklist(int c){
	struct node *head = (struct node *)malloc(sizeof(struct node));
	head -> data = c;
	head -> next = NULL;
	return head;
}

void add_node_last(struct node * head , int c){
	struct node *t =head;

	struct node *p = (struct node *)malloc(sizeof(struct node));
	while ( t->next != NULL ){
		t = t -> next;
	}
		t ->next = p;
		p -> next = NULL;
		p -> data = c;
	
}
void p_array(struct node * head){
	struct node * t = head;
	while ( t != NULL){
		printf("%d\n", t->data);
		t = t -> next;
	}
}

int i = 0;
void reverse(struct node * head, int k){
	struct node * n = NULL;
	struct node * p = NULL;
	struct node * c = head;
	int count = 0;
	while (count < k){
		n = c -> next;
		c -> next = p;
		p = c;
		c = n;
		c++;
	}

	arr[i].node_link = c;
	i++;

	

}


void reverse_group(struct node *head, int k, int size){

	for (int i=0 ; i<size ; i++){
		int l = 0;
		struct node *t = head;
		reverse(t, k);
		while (l=k & t != NULL){
			l++;
			t = t -> next;
		}

	}
}

void print_group(struct store arr[]){

	for (int i=0 ; i< 100; i++){
		printf("%d", arr[i]->data);
	}
}

void main(){

	struct node * head = create_linklist(1);
	add_node_last(head, 2);
	add_node_last(head, 3);
	add_node_last(head, 4);
	add_node_last(head, 5);
	add_node_last(head, 6);
	add_node_last(head, 7);
	add_node_last(head, 8);
	add_node_last(head, 12);	
	add_node_last(head, 7);
	//p_array(head);
	reverse_group(head, 4, 10);
	print_group(arr);

}


