#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * prev;
	struct node * next;
};

struct node * head_g;

struct node * get_node(){
	struct node *p = (struct node *)malloc(sizeof(struct node));
	p -> next = NULL;
	return p;
}

void add_node( struct node * head, int item ){

	struct node *t = head;

	if ( t == NULL ){
		head_g = get_node();
		head_g -> data = item;
		head_g -> next = NULL;
		head_g -> prev = NULL;
	}
	else {
		while ( t -> next != NULL ){
			t = t -> next;
		}

		struct node * k = get_node();
		t -> next = k;		
		k -> data = item;
		k -> prev = t;
		k -> next = NULL;

	}
}

void print_arr( struct node *p ){
	struct node *t = p;
	printf("\n");
	while ( t != NULL){
		printf("%d\t", t -> data);
		t = t -> next;
	}
	printf("\n");

}

void print_arr_rev( struct node *p ){
	struct node *t = p;
	printf("\n");
	while (t -> next != NULL){
		t = t -> next;
	}
	printf("\n");

	while (t != NULL){
		printf("%d\t", t -> data);
		t = t -> prev;
	}
	printf("\n");
	
}

void search( struct node *head, int item ){

	struct node *t = head;

	while (t != NULL ){
		if (t -> data == item){
			printf("\nItem found\n");
		}
		t = t -> next;
	}

}

void main(){

	FILE *ftr = fopen("test.txt", "r");
	int n;
	fscanf(ftr, "%d", &n);


	for (int i = 0; i < n; i++){
		int item;
		fscanf(ftr, "%d", &item);
		add_node(head_g, item);
	}


	print_arr(head_g);
	print_arr_rev(head_g);
	
	int value;
	fscanf(ftr,"%d", &value);
	search(head_g, value);



}
