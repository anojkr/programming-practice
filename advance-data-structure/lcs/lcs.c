#include <stdio.h>
#include <string.h>


void lcs(char *a, char *b, int a_l, int b_l){
		int table[a_l + 1][b_l + 1];

		for (int i = 0 ; i <=  a_l; i++ ){
			for (int j = 0; j <= b_l; j++){
				table[i][j] = 0;
			}
		}

		for (int i = 0 ; i <=  a_l; i++ ){
			for (int j = 0; j <= b_l; j++){
				if (i == 0 || j == 0){
					table[i][j] = 0;
				}
				if (i > 0 && j > 0 && a[i-1] == b[j-1]){
					table[i][j] = 1 + table[i-1][j-1];
				}
				if (i > 0 && j > 0 && a[i-1] != b[j-1])
				{
					table[i][j] = (table[i-1][j]>table[i][j-1])?table[i-1][j]:table[i][j-1];
				}
			}
		}
		
		for (int i = 0 ; i <=  a_l; i++ ){
			for (int j = 0; j <= b_l; j++){
				printf("%d ",table[i][j]);
			}
			printf("\n");
		}

		printf("Longest common subsequence = %d\n", table[a_l][b_l]);

}

void main(){
	char a[] = "XMJYAUZ";
	char b[] = "MZJAWXU";

	lcs(a,b, strlen(a), strlen(b));
}