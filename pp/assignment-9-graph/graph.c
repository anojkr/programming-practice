#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node {
	char source[100];
	char dest[100];
	int weight;
	struct node *next;
};

struct graph {
	int vertices;
	int edges;
	struct node *list[100];
};


struct node * get_node(char *s, char *d, int weight){
	struct node *t = (struct node *)malloc(sizeof(struct node));
	strcpy(t -> source, s);
	strcpy(t -> dest, d);
	t -> weight = weight;
	t -> next = NULL;

	return t;
}


void insertionSort(int arr[], int n) 
{ 
   int i, key, j; 
   for (i = 1; i < n; i++) 
   { 
       key = arr[i]; 
       j = i-1; 
  
       /* Move elements of arr[0..i-1], that are 
          greater than key, to one position ahead 
          of their current position */
       while (j >= 0 && arr[j] > key) 
       { 
           arr[j+1] = arr[j]; 
           j = j-1; 
       } 
       arr[j+1] = key; 
   } 
} 

void print_graph(struct graph *g){
	for (int i = 0; i < 100; i++){
		struct node *t = g -> list[i];
		if (t != NULL){
			printf("\n%s --> ", t -> source);
			while (t != NULL){
				printf("%s ", t -> dest);
				printf(" %d, ", t -> weight);
				t = t -> next;
			}
		}
	}
}

int hash_func(char *s){
	int i = 1;
	int hash = s[0];
	while (s[i] != '\0'){
		hash = hash + s[i]*10;
		i++;
	}

	int hash_value = hash%97;
	return hash_value;
}

void add_edges_to_graph(struct graph *g, int V, int E, char type, struct node *arr){

	while (E){
		char s[100];
		char d[100];
		int w;

		scanf("%s", s);
		scanf("%s", d);
		scanf("%d", &w);

		int index_value_s = hash_func(s);
		int index_value_d = hash_func(d);

		struct node *t = g -> list[index_value_s];
	
		if (t == NULL){

			g -> list[index_value_s] = get_node(s, d, w);
		

		}

		if (t != NULL){
			while (t -> next != NULL){
				t = t -> next;
			}
			t -> next = get_node(s, d, w);
		} 

		struct node *ud = g -> list[index_value_d];
		
		if (type == 'u' && ud == NULL){

			g -> list[index_value_d] = get_node(d, s, w);
	
		} 

		if (type == 'u' && ud != NULL){
			while (ud -> next != NULL){
				ud = ud -> next;
			}
			struct node *z = get_node(d, s, w);
			ud -> next = z;

		}

		E--;
		
	}

}

void create_graph(struct graph *g, int V, int E, char type){
	add_edges_to_graph(g, V, E, type);
	print_graph(g);
}



void main(){
	struct graph a;
	struct graph *g;
	g = &a;




	for (int i = 0; i < 100; i++){
		g -> list[i] =  NULL;
	}

	int V;
	int E;

	scanf("%d", &V);
	scanf("%d", &E);

	g -> vertices = V;
	g -> edges = E;

	struct node sort_array[E];

	create_graph(g, V, E, 'u', sort_array);

	
}

// 5
// 7
// ALLAHABAD BANARAS 1
// ALLAHABAD DELHI 5
// ALLAHABAD CALCULT 4
// BANARAS DELHI 2
// BANARAS EAST 6
// DELHI EAST 7
// DELHI CALCULT 3