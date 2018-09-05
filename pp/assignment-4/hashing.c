#include <stdio.h>
#include <stdlib.h>
#define SIZE  10

struct node {
	
	int data;
	struct node * next;

};

struct node * get_node(){
	
	struct node *t = (struct node *)malloc(sizeof(struct node));
	return t;

}

int calculate_hash(int num){
	
	int r = num % SIZE;
	return r;

}


void add_node_to_hash(struct node  *arr[], int index, int num){

	if (arr[index] == NULL){
	
		struct node *t = get_node();
		t -> data = num;
		t -> next = NULL;
		arr[index] = t;

	} else {
		
		struct node *t = arr[index];
		while (t -> next != NULL){		
			t = t -> next;
		}

		struct node *temp = get_node();
		temp -> data = num;
		temp -> next = NULL;
		t -> next = temp;
	

	}
}


void hashing_by_chaining(struct node * arr[], int num){

	int hash_index_num = calculate_hash(num);
	add_node_to_hash(arr, hash_index_num, num);
	

}

void delete_node_chaining(struct node *arr[], int num){

	int hash_index_num =  calculate_hash(num);
	struct node *t = arr[hash_index_num];
	struct node * temp;
	
	if (t -> data == num){	
		temp = t;
		arr[hash_index_num] = t -> next;
		free(temp);

	} else {
	
		while(t -> next != NULL){
			if (t -> next -> data == num ){
				temp = t -> next;
				t -> next = t -> next -> next;
				free(temp);
				return;
			}
	
			t = t -> next;
	
		}

		printf("\nElement not found\n");
	}


}


void search_number(struct node *arr[], int num){

	int hash_index_num = calculate_hash(num);
	struct node * t = arr[hash_index_num];
	
	if (t != NULL){
		
		while (t != NULL){
			if (t -> data == num){
				printf("\nElement %d is found\n", num);
				return;
			}
			t = t -> next;
		}

		printf("\nElement not found\n");

	} else {

		printf("\nElement not found\n");

	}

}

void print_hash(struct node *arr[]){

	for (int i=0; i <SIZE; i++){
		struct node *t = arr[i];
		printf("\nINDEX = %d  ELEMENTS\t", i);
		while (t != NULL){
			printf("%d \t", t -> data);
			t = t -> next;
		}		
	}
	printf("\n");

}

void main(){

	struct node * a[SIZE];

	for ( int i = 0; i < SIZE; i++ ){
		a[i] = NULL;
	}

	int n;
	scanf("%d", &n);

	for ( int i = 0 ; i < n; i++){
		int num;
		scanf("%d", &num);
		hashing_by_chaining(a, num);
	}

	print_hash(a);
	printf("\n");

	int d;
	scanf("%d", &d);
	for (int i = 0; i < d; i++){
		int d_num;
		scanf("%d", &d_num);
		delete_node_chaining(a, d_num);
	}

	print_hash(a);
	printf("\n");

	int s;
	scanf("%d", &s);
	search_number(a, s);


}
