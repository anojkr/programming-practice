#include <stdio.h>
#include <stdlib.h>

struct node {
	
	int data;
	struct node *next;
	struct node *prev;

};

struct node * get_node(int item){
	struct node *t = (struct node *)malloc(sizeof(struct node));
	t -> data = item;
	t -> next = NULL;
	t -> prev = NULL;
	return t;
}

void add_node(struct node **head, int item){
	struct node *t = *head;
	if (*head == NULL){
	
		*head = get_node(item);
	
	}else{
		while (t -> next != NULL){
			t = t -> next;
		}
		struct node *temp = get_node(item);
		t -> next = temp;
		temp -> prev = t;
	}
}

void print_ll(struct node *head){
	
	struct node *t = head;
	struct node *k = head;
	printf("\n");
	
	while (t != NULL){
		printf("%d ", t -> data);
		t = t -> next;

	}

	while(k -> next != NULL){
		k = k -> next;
	}

	printf("\n");
	while (k != NULL){
		printf("%d ", k -> data );
		k = k -> prev;
	}


}

void create_doubly_linklist(struct node **head){
	struct node *t = *head;

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int item;
		scanf("%d", &item);
		add_node(head, item);
	}

}

void main(){
	struct node *head = NULL;
	create_doubly_linklist(&head);
	print_ll(head);
}