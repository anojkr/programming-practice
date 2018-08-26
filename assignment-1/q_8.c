#include <stdio.h>
#include <stdlib.h>
int N;

void matrix_operation(int a[N][N]){
	int b[N];
	int flag = 1;

	for ( int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if ( i == j ){
				b[i] = 0;
				

				if ((j-1) >= 0){
					b[i] = b[i] + a[i][j-1];
				}


				if((i-1) >= 0){
					b[i] = b[i] + a[i-1][j];
				}  

				if((i+1) < N){
					b[i] = b[i] + a[i+1][j];
				}  

				if((j+1) < N){
					b[i] = b[i] + a[i][j+1];
				}

			}

			if( b[i] != a[i][j]){
				flag = 0;
			}
		}
	}

	if( flag == 0){
		printf("\nNO\n");
	}else{
		printf("\nYES\n");
	}
}

void matrix_input(){
	int a[N][N];
	printf("\nEnter elements of 2-D array\n\n");
	for ( int i = 0; i < N; i++){
		for( int j = 0; j < N; j++){
			scanf("%d", &a[i][j]);
		}
	}

	printf("\nElements of 2-D array\n\n");
	for (int m = 0; m < N; m++){
		for (int t = 0; t < N; t++){
			printf("%d \t", a[m][t]);
		}
		printf("\n");
	}
	
	matrix_operation( a );
}

int main(){
	printf("\nEnter size of matrix\n");
	scanf("%d", &N);

	matrix_input( N );
}
