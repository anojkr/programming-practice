#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int count = 0;
void dfs(int arr[n][n], int vis[n], int parent[n], int index){
	vis[index] = 1;
//	printf("%d ", index);
	
	for (int i = 0 ; i < n; i++) {
		if (arr[index][i] == 1 && vis[i] == 1) {
			count++;
		}
		if (vis[i] == 0 && arr[index][i] == 1) {
			parent[i] = index;
			vis[i] = 1;
			dfs(arr, vis, parent, i);
		} 
	
	}
}

void test(){

	int arr[n][n];
	int visited[n];
	int parent[n];

	for (int i = 0; i < n; i++){
		visited[i] = 0;
		parent[i] = -1;
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);	
		}
	}
		
	for (int i = 0; i < n; i++){
		count = 0;
		dfs(arr, visited, parent, i);
				
		printf("%d", count);
	}

}

void main()
{
	scanf("%d", &n);
	test();
//	printf("%d", count);
	//dfs(arr, visited, 0);
}
