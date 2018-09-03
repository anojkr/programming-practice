#include <stdio.h>
#include <stdlib.h>

struct node {
	int capacity;
	int size;
	int *arr;
};


int push_back( struct node *p){

	int index = p -> size;	

	if  ( (p -> size) < (p -> capacity) ){
		
		p -> size = p -> size + 1;
		scanf("%d", &((p -> arr)[index]));	
	
		return ((p -> arr)[index]);

	} else {
		return 0;
	}	
	
}

void delete_by_index(struct node *p, int index ){

	for ( int i = 0; i < (p -> size); i++ ){
		if (i >= index){
			(p -> arr)[i] = (p -> arr)[i+1];
		}
	}
	
	 p -> size = ( p -> size ) - 1;

}

void delete_by_value(struct node *p, int value){
	
	int count = -1;
	for ( int i = 0; i < ( p -> size); i++){
		if ( (p -> arr)[i] == value ){
			count++;
		}
		(p -> arr)[i-count] = (p -> arr)[i+1];
	}
	
	int item = p->size - count-1;
	printf("\n");
	for (int k = 0; k < item; k++){
		printf("%d\t", (p -> arr)[k]);
	}

	printf("\n");
}


void print_dynamic_table(struct node *p){
	printf("\n");

	printf("Capacity = %d\t", p -> capacity);	
	printf("Size = %d\t"	, p -> size);
	printf("Elements =\t");

	for ( int i = 0; i < (p -> size); i++){
		printf("%d\t", (p -> arr)[i]);
		
	}

printf("\n");
	return ;
}

void create_array( struct node *p, int c, int n){
	
	int * ptr = (int *)malloc( sizeof(int)*c );
	p -> capacity = c;
	p -> size = 0;
	p -> arr = ptr;
	
}


void main(){

	struct node dynamic_table;
	int c;
	int n;
	
	int pop_call;
	scanf("%d", &c);
	scanf("%d", &n);


	create_array( &dynamic_table, c, n );
	for (int i = 0; i < n ; i++){
		push_back(&dynamic_table);
	}
	
	
	int index;
	scanf("%d", &index);
	int value;
	scanf("%d", &value);

	print_dynamic_table(&dynamic_table);
	delete_by_index(&dynamic_table, index);
	print_dynamic_table(&dynamic_table);
	delete_by_value(&dynamic_table, value);


}
