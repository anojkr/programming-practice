#include <stdio.h>
#include <stdlib.h>
#define N 26


void flush(int *p){
	for (int j = 0; j < N; j++){
                p[j] = 0;
        }

}

int * get_set(){
        int *a = (int *)malloc(N*sizeof(int));
        return a;
}


int * create_set(){
        int *p = get_set();
        int k;
        scanf("%d", &k);
	printf("Value of k = %d", k);
 	flush(p);
	char c;
        for (int i = 0; i < k ; i++){
                //char c;
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


int * union_set(int *k, int *l){

	int *t = get_set();
	int Z=0;
	while (Z<26){

		if (k[Z] == l[Z]){
			printf("%c", Z-'a');
			t[Z] = k[Z];
			Z++;
		} else {
			t[Z] = k[Z];
			Z++;
			t[Z] = l[Z];
			Z++;
		}
	}

	return t;
}

void main(){
        
        int *k = create_set();
	print_ll(k);

	int * m = create_set();
	print_ll(m);

	int * t = union_set(k,m);
	print_ll(t);
}

