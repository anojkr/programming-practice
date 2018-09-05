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

void  dynamic_table_reduce( struct node * p ){
	
	if ( p -> capacity != 0 ){	
		int c = (p -> capacity)/2;
		p -> capacity = c;

		int s = p -> size;	
		int *temp  = (int *)realloc( p->arr, sizeof(int)*c);
	
		if (temp != '\0'){
			p -> arr = temp;
		}
	}
	
}

void pop_back( struct node *p ){
	if ( p -> size >0){
		int s = p -> size;
		(p -> arr)[s-1] = 0;
		(p -> size) = (p -> size) - 1;
	}

	if ( p->size <= 0 ){
		printf("Dynamic table underflow");
	}

	if ( (p -> size) <= ( (p -> capacity)/4) ){
		dynamic_table_reduce(p);
	}
	
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
	
	scanf("%d", &pop_call);
	print_dynamic_table(&dynamic_table);

	while (pop_call){
		
		pop_back(&dynamic_table);
		print_dynamic_table(&dynamic_table);
		pop_call--;
	}


	



}
