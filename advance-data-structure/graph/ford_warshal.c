#include <stdio.h>

int V;
void ford_warshall(int a[][V], int P[][V], int V){

	for (int k=0; k<V; k++){
		int b[V][V];
		for (int i=0; i<V; i++){
			for (int j=0; j<V; j++){
				if (a[i][j] > a[i][k] + a[k][j]){
					b[i][j] = a[i][k] + a[k][j];
					P[i][j] = P[k][j];
				}else {
					b[i][j] = a[i][j];
				}
			}
		}
		
		for (int i=0; i<V; i++){
			for (int j=0; j<V; j++){
				a[i][j] = b[i][j];
			}
		}
	}

}

void setup_path(int a[][V], int P[][V]){

		for(int i = 0; i < V; i++){
			for (int j=0; j<V; j++){
				if (i == j || a[i][j] == 100){
					P[i][j] = 0;
				} else {
					P[i][j] = i+1;
				}
			}
	}
}

void main(){

	scanf("%d", &V);
	int a[V][V];
	int p[V][V];

	for(int i = 0; i < V; i++){
		for (int j=0; j<V; j++){
			scanf("%d", &a[i][j]);
		}
	}

	setup_path(a, p);

	ford_warshall(a, p, V);

	printf("All pair shortest path\n");
	for (int i=0; i<V; i++){
			for (int j=0; j<V; j++){
				printf("%d ", a[i][j]);
			}
			printf("\n");
	}

	printf("Path trace\n");

	for (int i=0; i<V; i++){
			for (int j=0; j<V; j++){
				printf("%d ", p[i][j]);
			}
			printf("\n");
	}
}