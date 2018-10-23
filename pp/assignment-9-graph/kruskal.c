#include <stdio.h>
#include <stdlib.h>

struct node {

	int weight;
	char source;
	char dest;
	struct node * next;

};

struct graph {

	int v;
	int e;
	struct node *list[100];
	
};

struct node *get_vertices(char source){
	
	struct node *t = (struct node *)malloc(sizeof(struct node));
	t -> source = source;
	t -> weight = 0;
	t -> dest = '0';
	t -> next = NULL;
	return t;

}

struct node *get_edges(struct graph *g , char source, char dest, int weight){
	struct node *t = (struct node *)malloc(sizeof(struct node));
	t -> source = source;
	t -> dest   = dest;
	t -> weight = weight
	t -> next = NULL;
	return t;

}

void add_vertices(struct graph *g, char v, int i){
	g -> list[i] = get_vertices(v);
	return;
}

void add_edges(struct graph *g, char s, char d, int w){
	
	for (int i = 0 ; i < g -> v; i++){
		if (g -> list[i] == s){
			struct node *m = g->list[i];
			while (m -> next != NULL){
				m = m -> next;
			}		
			m -> next = get_edges(g, s, d, w);
		}
	}
	

}

void main(){

	struct node *root = NULL;
	struct graph g;
	scanf("%d", &(g.v));
	//scanf("%d", &(g.e));	
	int n = g.v;
	int m = g.e;
	int i = 0;

	
	for (int k = 0 ; k < g.v ; k++){
		g.list[k] = NULL;
	}
	
	
	while (n){
		char item;
		scanf(" %c", &item);
		add_vertices(&g, item, i);
		i++;
		n--;
	
	}

	while (m){
		char s,d;
		int w;
		scanf(" %c", &s);
		scanf(" %c", &d);
		scanf("%d", &w);
		add_vertices(&g, s, d, w);
		m--;
	}

	for (int k = 0 ; k < g.v ; k++){
		printf("%c ", g.list[k] -> source);
	}
}

