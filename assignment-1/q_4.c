#include <stdio.h>
#include <stdlib.h>
#include"insertion_sort.c" 
#include"set.c" 
int N;


void unique_value_row(int a[][N]){
	int b[N];
	printf("\nUnique value each row in matrix\n");
	for ( int i = 0; i < N; i++){
		printf("\n");
		for ( int j = 0; j < N; j++){
			b[j] = a[i][j];
		}
		insertionSort(b, N);
		printf("\n");
		distinct(b, N);
	}
	printf("\n");
}


void unique_value_coloumn(int a[][N]){
	int b[N];
	printf("\nUnique value each colomn in matrix\n");
	for ( int i = 0; i < N; i++){
		printf("\n");
		for ( int j = 0; j < N; j++){
			b[j] = a[j][i];
		}
		insertionSort(b, N);
		//printArray(b, N);
		printf("\n");
		distinct(b, N);
	}
	printf("\n");
}


void unique_value_matrix(int a[][N]){
	int size = N*N;
	int b[size];
	int k;
	printf("\nUnique value in matrix\n");
	k = 0;
	for ( int i = 0; i < N; i++){
		printf("\n");
		for ( int j = 0; j < N; j++){
			b[k] = a[i][j];
			k++;
		}
	}
	insertionSort(b, size);
	distinct(b, size);
	printf("\n");
}



void matrix_input(){
	int a[N][N];
	for ( int i = 0; i < N; i++){
		for ( int j = 0; j < N; j++){
			scanf("%d", &a[i][j]);
		}
	}

	printf("\nElements of 2-D array\n\n");
	for ( int i = 0; i < N; i++){
		for ( int j = 0; j < N; j++){
			printf("%d \t", a[i][j]);
		}
		printf("\n");
	}

	unique_value_row(a);
	unique_value_coloumn(a);
	unique_value_matrix(a);

}

void main(){
	printf("\nEnter size of matrix\n");
	scanf("%d", &N);

	matrix_input( N );
}