#include<stdio.h>
#include<stdlib.h>

struct graph *create_graph(int item_nodes);
void add_source_node_to_graph(struct graph *g);
int check_source_node_exist(struct graph *g, char source_node);
void add_edges_graph_nodes(struct graph *g, char source_node, char dest_node);

int V=0; //number of vertices in graph

struct node {
	char destination;
	struct node *next;
};

struct adjlist{
	char source;
	struct node *next;
};

struct graph {
	struct adjlist *graph_head[5];
};

struct graph *create_graph(int item_nodes){
	struct graph *g = (struct graph *)malloc(sizeof(struct graph));
	for(int i=0 ; i< item_nodes; i++){
	    g->graph_head[V] = '\0';
	    add_source_node_to_graph(g);
	}
	return g;
}

void add_source_node_to_graph(struct graph *g){
    struct adjlist *l = (struct adjlist *)malloc(sizeof(struct adjlist));
	g->graph_head[V]=l;
	char source_node;
	printf("\n Enter node name to add in graph \n");
    scanf("%c", &source_node);
	g->graph_head[V]->source = source_node;
	g->graph_head[V]->next = '\0';
	V++;
	printf("\n Source node %c added to grap \n", source_node);
	printf("\n Number of nodes in graph are %d \n", V);
}
/*
int check_source_node_exist(struct graph *g, char source_node){
	struct graph *t = g;
	for(int i=0 ; i<V; i++){
		if(source_node == t->graph_head[i]->source)
		{
			return i;
		}
	return -1;
	}
}

void add_edges_graph_nodes(struct graph *g, char source_node, char dest_node){
	struct graph *t = g;
	int i=0;
	int check_value = check_source_node_exist(g, source_node);
	printf("Check vale %d", check_value);
	struct node *p;
	if(check_value != -1){
		p = t->graph_head[check_value]->next;
		while(p->next != '\0'){
			p = p -> next;
		}
		struct node * temp = (struct node *)malloc(sizeof(struct node));
		p->next = temp;
		temp->destination = dest_node;
		temp->next = '\0';
		printf("Edge is added to source node %c to %c", source_node, dest_node);	
		
	}
	else{
		printf("Source node not exist");
	}
}

*/

int main(){
    struct graph *g = create_graph(5);
    
    return 0;
}


