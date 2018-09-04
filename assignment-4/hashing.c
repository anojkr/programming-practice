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


void hashing_by_chaning(struct node * arr[], int num){
	int hash_index_num = calculate_hash(num);
//	printf("\nHash index %d, %d\n", hash_index_num, num );
	add_node_to_hash(arr, hash_index_num, num);
	

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
		hashing_by_chaning(a, num);
	}

	print_hash(a);
}
