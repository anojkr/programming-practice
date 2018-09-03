#include <stdio.h>
#include <stdlib.h>

struct node {
	int capacity;
	int size;
	int *arr;
};


int insert_element( struct node *p){

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

		int t = insert_element(&dynamic_table);
		if ( t != 0 ){
			print_dynamic_table(&dynamic_table);
		}
		if ( t == 0 ){
			dynamic_table_resize(&dynamic_table);

		}

	}

}
