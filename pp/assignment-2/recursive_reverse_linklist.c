#include <stdio.h>
#include <stdlib.h>

struct node {
	
	int data;
	struct node *next;

};


struct node * getnode(){

	struct node * t = (struct node *)malloc(sizeof(struct node));
	t -> next = NULL;

	return t;

}

void add_node( struct node ** head, int item ){

	if ( *head == NULL ){
	
		struct node * k =  getnode();
		k -> data = item;
		k -> next = NULL;
		*head = k;

	} else {
	
		struct node *t = *head;
		while ( t -> next != NULL ){
			t = t-> next;
		}
		struct node *newnode = getnode();
		newnode -> data = item;
		newnode -> next = NULL;
		t -> next = newnode;

	}

}

struct node * head_g = NULL;
void reverse_linklist_recursive(struct node *prev, struct node *curr){
	if (curr == NULL){
		head_g = prev;
		return;
	
	} else { 

		reverse_linklist_recursive(curr, curr->next);
		curr -> next = prev;
	}

		
}


void prt_ll( struct node * head ){

	struct node *t = head;
	while (t != NULL){
		printf("%d\t", t -> data);
		t = t-> next;
	}

	printf("\n");

}

void main(){

	int n;
	printf("\nEnter no. items in linklist\n");
	scanf("%d", &n);
	
	int item_1, item_2;
	struct node *head = NULL;


	printf("\nEnter elements in insert in linklist\n");
	
	for (int i = 0; i < n; i++){
		int data;
		scanf("%d", &data);
		add_node(&head, data);
	}  
	
	prt_ll(head);
	reverse_linklist_recursive(NULL, head);
	prt_ll(head_g);
}


