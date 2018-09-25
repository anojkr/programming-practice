#include <stdio.h>
#include <stdlib.h>

void calculate_hash(int p[26], char a[100]){

	for (int i = 0; i < 20; i++){

		if (a[i] == 'a' || a[i] == 'e'|| a[i] == 'i' || 
				a[i] == 'o' || a[i] == 'u'){
		int hash = a[i] - 'a';
//		printf("%c =  %d", a[i], hash);
//		printf("\n");
		p[hash] = p[hash] + 1;
		}
	
	}

}

void print_ll(int p[26]){
	int c = 0;
	for (int i = 0; i < 26; i++){
		if (p[i] == 1){
			printf("%c ", i+'a');
			c = 1;
		}
	}
	if (c == 0 ){
		printf("NONE");
	}
	printf("\n");
	
}

void main(){

	int n;  
	scanf("%d", &n);

	int hash_table[26];

	
	
	while(n){

		for(int i=0; i<26; i++){
			hash_table[i] = 0;
		}

		char str[100];
		scanf("%s",str);
		calculate_hash(hash_table, str);

		print_ll(hash_table);
		n--;

	}
	


}
