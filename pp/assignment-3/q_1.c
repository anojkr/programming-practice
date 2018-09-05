/*

Consider a dynamic table with the following properties. 
a. Elements are stored in a dynamic array
b. Capacity is the size of the dynamic array
c. Size is defined is the number of elements stored in the array
Insert elements into dynamic table. Double capacity if size is equal to capacity before 
push_back()

Input: (n, elements)
9
6 7 8 12 4 10 11 1 15

Output: 
capacity = 1; size = 1; elements = 6
capacity = 2; size = 2; elements = 6 7
capacity = 4; size = 3; elements = 6 7 8
capacity = 4; size = 4; elements = 6 7 8 12
capacity = 8; size = 5; elements = 6 7 8 12 4
capacity = 8; size = 6; elements = 6 7 8 12 4 10
capacity = 8; size = 7; elements = 6 
7 8 12 4 10 11
capacity = 8; size = 8; elements = 6 7 8 12 4 10 11 1
capacity = 16; size = 9; elements = 6 7 8 12 4 10 11 1 15

*/



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


void  * dynamic_table_resize( struct node * p ){

	int c = 2 * (p -> capacity);
	p -> capacity = c;

	int s = p -> size;	
	int *temp  = (int *)realloc( p->arr, sizeof(int)*c);
	
	if (temp != '\0'){
		p -> arr = temp;
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
}

void create_array( struct node *p){
	
	int * ptr = (int *)malloc( sizeof(int) );
	p -> capacity = 1;
	p -> size = 0;
	p -> arr = ptr;
	
}


void main(){

	struct node dynamic_table;
	int n;
	scanf("%d", &n);

	create_array( &dynamic_table );

	for ( int i = 1 ; i <= 2*n; i++ ){

		int t = push_back(&dynamic_table);
		if ( t != 0 ){
			print_dynamic_table(&dynamic_table);
		}
		if ( t == 0 ){
			dynamic_table_resize(&dynamic_table);

		}
		if ( dynamic_table.size == n){
			break;
		}
	}

}
