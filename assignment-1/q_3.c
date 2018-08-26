#include <stdio.h>
#include <stdlib.h>
int m, n;

void matrix_transpose(int a[][n], int *p, int *q){
	int r = *p;
	int c = *q;
	//printf("values %d%d\n",k,l );

	int t[c][r];
	for ( int i = 0; i < r; i++ ){
		for (int j = 0; j < c; j++){
			t[j][i] = a[i][j];
		}
	}

	printf("\nElements of 2-D array\n\n");
	for (int x = 0; x < c; x++){
		for (int y = 0; y < r; y++){
			printf("%d \t", t[x][y]);
		}
		printf("\n");
	}

}

void main(){
	//int m, n;
	printf("Enter matrix size : rows, colomn \n");
	scanf("%d %d",&m ,&n);
	
	int a[m][n];

	printf("\nEnter matrix element\n");
	for ( int i = 0; i < m; i++ ){
		for (int j = 0; j < n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	
	matrix_transpose(a, &m, &n);
}