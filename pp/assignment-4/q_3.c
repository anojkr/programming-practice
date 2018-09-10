#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculate_hash( char *s ){
	
	int hash = 0;
	int i = 1;
	
	while (*s){
		hash = hash + (*s)*i;
		i++;
		s++;
	}

	return hash%599;
}


void main(){

	char *table[599];	
	
	int n;
	scanf("%d", &n);

	for (int i = 0 ; i < 599; i++){

		table[i] = NULL;
	}

	for ( int i = 0; i < n; i++){
			
		char s[100];
		scanf("%s", s);

		int l = strlen(s);
		int hash_value  = calculate_hash(s);
		
		char *p = (char *)malloc(l+1);
		
		strcpy(p,s);
		table[hash_value] = p; 
	
	}


	int count = 0;
	
	for ( int i = 0; i < 599 ; i++ ) {

		if( table[i] != NULL){
			count++;
		}		
	}

	printf("%d\n", count);

}
