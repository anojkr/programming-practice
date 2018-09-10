#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 26

struct node {
	char data;
	struct node *next;
};


struct node * get_node(){
	struct node *p = (struct node *)malloc(sizeof(struct node));
	return p;
}


void hash_insert(char c, struct node *hash_table[SIZE]){
	int hash_value = c - 'a';
	struct node *t = get_node();
	t -> data = c;
	t -> next = NULL;

	//printf("\nhash_value =  %d\n", hash_value);

	if (hash_table[hash_value] == NULL){
		hash_table[hash_value] = t;
	}
	else{
		struct node *k = hash_table[hash_value];
		while (k -> next != NULL){
			//printf("\n%d\n", k->data);
			k = k -> next;
		}
		k -> next = t;
	}
}

void print_table(struct node *table[SIZE]){

	for (int i = 0; i < SIZE; i++){
		struct node *t = table[i];
			int i = 0;
			while (t != NULL && i == 0){
				printf("%c\t", t -> data);
				t = t -> next;
				i++;
			}
	}
	
	printf("\n");
}

void main(){

	int n;
	scanf("%d", &n);
	
	struct node *hash_table[SIZE];
	while (n){
	
		for (int i = 0; i < SIZE; i++){
			hash_table[i] = NULL;
		}
		
		char c[100];
		scanf("%s", c);
		int l = strlen(c);
		for (int i = 0; i < l ; i++){
			hash_insert(c[i], hash_table);
		}
		print_table(hash_table);
		n--;
	}

}
