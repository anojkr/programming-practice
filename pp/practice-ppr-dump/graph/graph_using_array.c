#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void build_undirected_graph(int a[1000][1000], int v, int e){


	for (int i = 0; i < e; i++) {
		
		char source;
		char dest;
		int weight;

		scanf(" %c", &source);
		scanf(" %c", &dest);
		scanf("%d", &weight);
		int t = source - 'A';
		int k = dest - 'A';
		
		a[t][k] = weight; 
		a[k][t] = weight; 

	}

}


void flush_matrix(int a[1000][1000]){

	for (int i = 0; i < 1000; i++){
		for (int j = 0; j < 1000 ; j++){
				a[i][j] = -1;
		}
	}
}

void print_graph(int a[1000][1000]){
	for (int i = 0; i < 1000; i++){
		for (int j = 0; j < 1000 ; j++){
				if (a[i][j] != -1){
					printf("\nSource : %c --> ", i + 'A');
					printf("%c : ", j + 'A');
					printf("%d\n", a[i][j]);
				}
		}
	}

}

void main(){
		int a[1000][1000];
		flush_matrix(a);

		int v;
		int e;
		scanf("%d", &v);
		scanf("%d", &e);

		build_undirected_graph(a, v, e);
		print_graph(a);

}