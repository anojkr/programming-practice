#include <stdio.h>
#include <stdlib.h>
int N;

void check_result(int r[], int c[]){
	for( int i = 0; i < N; i++){
		for ( int j = 0; j < N; j++){
			if (r[i] == c[j]){
				printf("\nRow : %d\nColumn: %d\n",i+1 ,j+1);
				break;
			}
		}
	}

}

void matrix_row_sum(int a[][N]){
	int r[N];
	int c[N];

	for ( int i = 0; i < N; i++){
		r[i] = 0;
		c[i] = 0;
		for ( int j = 0; j < N; j++){
			r[i] = r[i] + a[i][j];
			c[i] = c[i] + a[j][i];
		}
	}

	printf("\nSum of each row\n");
	for( int k = 0; k < N; k++){
			printf("%d\t", r[k]);
	}
	printf("\n");

	printf("\nSum of each column\n");
	for( int k = 0; k < N; k++){
			printf("%d\t", c[k]);
	}

	check_result(r, c);
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

	matrix_row_sum(a);

}

void main(){
	printf("\nEnter size of matrix\n");
	scanf("%d", &N);
	matrix_input(N);
}