#include <stdio.h>
#include <stdlib.h>
#define N 26


int * get_set(){
        int *a = (int *)malloc(N*sizeof(int));
        return a;
}


int * create_set(){
        int *p = get_set();
        int k;
        scanf("%d", &k);
	printf("Value of k = %d", k);
        for (int j = 0; j < N; j++){
                p[j] = 0;
        }

        for (int i = 0; i < k ; i++){
                char c;
                scanf(" %c", &c);
                int d = c - 'a';
                p[d] = 1;

        }

        return p;
 
}

void print_ll(int *k){

        printf("\n");
        for (int i = 0; i < N; i++){
                if (k[i] == 1){
                        printf("%c ", 'a'+i);
                }
        }



}

void flush(int *p){
	for (int j = 0; j < N; j++){
                p[j] = 0;
        }

}

void union_set(int *k, int *l){
	while (N!=26){
		if (k[N] == l[N]){

		}
	}
}

void main(){
        
        int *k = create_set();
	print_ll(k);
}

