#include <stdio.h>
#include <stdio.h>
int n;

void dfs(int a[n][n], int *vis, int i, int n){
	vis[i] = 1;
	printf("%d\n", i);
	for (int j = 0; j < n; j++){
		if (vis[j] == 0 && a[i][j] == 1){
			vis[j] = 1;
			dfs(a, vis, j, n);
		}
	}
}

void main(){

	//int n;
	scanf("%d", &n);


	int a[n][n];
	int vis[n];

	for (int i = 0; i < n; i++) {
		vis[i] = 0;
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		if (vis[i] == 0) {
			dfs(a, vis, i, n);
		}
	}



}