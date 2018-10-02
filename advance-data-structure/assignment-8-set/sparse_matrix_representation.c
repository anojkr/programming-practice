#include <stdio.h>
#include <stdlib.h>

struct node {
	int row_location;
	int col_location;
	int data;
};

void main(){
	int size;
	int m,n;
	scanf("%d %d", &m, &n);
	int a[m][n];

	struct node arr[m*n];

	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			scanf("%d", &(a[i][j]));
			if (a[i][j]!=0){
				size++
			}
		}
	}

	int t = 0;
	printf("[\n");
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			printf(" %d", (a[i][j]));
			if (a[i][j] !=0 & t < size){
				arr[t].row_location = i;
				arr[t].col_location = j;
				arr[t].data = a[i][j];
				t++;	
			}

		}
		printf("\n");
	}
	printf("]\n");


	printf("Row  : ");
	for (int i = 0; i < size; i++){
		printf("%d ",arr[i].row_location);
	}
	printf("\nCol  : ");

	for (int i = 0; i < size; i++){
		printf("%d ",arr[i].col_location);
	}

	printf("\nData : ");
		for (int i = 0; i < size; i++){
		printf("%d ",arr[i].data);
	}

}