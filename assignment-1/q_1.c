#include <stdio.h>
#include <math.h>

void min_value_x(float diagonal_sum, float no_diagonal_element){

    printf("\n\nDiagonal sum = %f 					\n", 	diagonal_sum);
    printf("\nNumber of non-diagonal element = %f   \n", 	no_diagonal_element);
    
    float r 	= diagonal_sum/no_diagonal_element;
    int result  = ceil(r);

    if (no_diagonal_element*result > diagonal_sum){

    	    printf("\nMinimum value X = %d \n", result);

    } else {

    		printf("\nNo such element is found\n");

    }
}

int matrix_input(int N){
	int d[N];
	float diagonal_sum;
	float no_diagonal_element;

	diagonal_sum = 0;
	no_diagonal_element = ( ( N * N ) - N );

	for(int i = 0; i < N; i++){
		scanf("%d", &d[i]);
	}

	printf("\nDiagonal element of 2-D array\n");
	for(int i = 0; i < N; i++){
		printf(" %d \t", d[i]);
	}
	
	for(int i = 0; i < N; i++){
        diagonal_sum = diagonal_sum + d[i];
    }

    min_value_x(diagonal_sum, no_diagonal_element);
}



int main(){
	int N;//SIZE OF MATRIX
	
	printf("Enter size of square matrix\n");
	scanf("%d", &N);
	
	matrix_input( N );
}