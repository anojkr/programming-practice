#include <stdio.h>
#include <stdlib.h>
#define N 10
#include "queue.c"

struct node {
	int data;
	char c;
	//char *p;
	struct node *next;
};


struct adjlist{
	struct node *list[N];
};

struct graph{
	int V;
	int E;
	struct adjlist graph;
};


struct node *get_vertices(char c){

	struct node *t = (struct node *)malloc(sizeof(struct node ));
	t -> c 		= c;
	t -> data 	= 0;
	t -> next	= NULL;
	return t;

}

struct node *get_node(char destionation, int edge_weight){

	struct node *t = (struct node *)malloc(sizeof(struct node ));
	t -> c 		= destionation;
	t -> data 	= edge_weight;
	t -> next	= NULL;
	return t;

}

void add_vertices_graph(struct graph *g){
	int V;
	scanf("%d", &V);
	g -> V = V;

	int i = 0;
	while(V){
		
		char c;
		scanf(" %c", &c);
		struct node *t = get_vertices(c);
		g -> graph.list[i] = t;
		V--; 
		i++;
	
	}

}

struct node * search_vertice(struct graph *g, char source){
	int V = g -> V;
	//printf(" %c\n",source);
	for (int i=0; i < V; i++){
		struct node *t = g -> graph.list[i];
		
		if ( t != NULL &&  t -> c == source){
			return t;
		}
	}
	printf("not found %c", source);

}

void add_edges_graph(struct graph *g){
	int E;
	scanf("%d", &E);
	g -> E = E;

	int i = 0;
	while (E){
		char source;
		char destionation;
		int edge_weight;

		scanf(" %c", &source);
		scanf(" %c", &destionation);
		scanf(" %d", &edge_weight);
		struct node *t = search_vertice(g, source);
		struct node * new_node = get_node(destionation,edge_weight);

		while (t -> next != NULL){
			t = t -> next;
		}

			t -> next = new_node;

			E--;

	}
}


void bfs(struct graph *g){

	int a[26];

	for (int i = 0; i < 26; i++){
		a[i] = 0;
	}


	struct Queue *q = createQueue(); 

	a[g->graph.list[0]->c - 'a'] = 1;

	enQueue(q, g->graph.list[0]->c);

	printf("\n Visted Node : ");
	while (!is_empty(q)){
		
		struct QNode *m = deQueue(q);
		struct node *t = search_vertice(g, m -> key);
		printf(" %c", m -> key );
		
		t = t -> next;
		while( t != NULL){
			if (a[t -> c -'a'] == 0){
					a[ t -> c - 'a'] = 1;
					enQueue(q, t -> c);
			}
			
			t = t -> next;
			
		}

	}

}

void print_ll(struct graph *g){
	for (int i = 0; i < N; i++){
		struct node *t = g -> graph.list[i];
		if (t!=NULL){
			while (t != NULL){
				printf(" %c",t -> c);
				printf(" %d ",t -> data);
				t = t -> next;
			}
		}
		printf("\n");
	}
}



void main(){
	
	struct graph g;
	struct node a,b,c;

	for (int i = 0; i < N; i++){
		g.graph.list[i] = NULL;
	}


	add_vertices_graph(&g);
	add_edges_graph(&g);
//	print_ll(&g);
	bfs(&g);


}
