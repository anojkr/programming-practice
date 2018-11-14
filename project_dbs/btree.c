#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define btoa(x) ((x)?"true":"false")
#define t 3

struct data {
	bool present;
	char name[50];
	char sex[5];
	int age;
};

struct node {
	int n;
	bool leaf;
	int keys[2*t];
	struct data d[2*t];
	struct node * C[2*t + 1];
};

void parse(char insert_query[1000], char *token[100]) 
{
	char *pch;

	for (int k = 0; k < 100; k++) {
		token[k] = NULL;
	}

	scanf(" %[^\n]s", insert_query);

	pch = strtok(insert_query, " ");

	int i = 0;
	while (pch != NULL) {
		token[i] = pch;
		pch = strtok (NULL, " ");
		i++;
	}
	token[i+1] = NULL;
	
	// int z = 0;
	// while (token[z] != NULL) {
	// 	printf("%s\n",token[z]);
	// 	z++;
	// }
}

FILE * disk_write(struct node *x) 
{
	FILE *p = fopen("record.dat", "wb+");
	if (p == NULL) { 
        printf("\nError opening file\n"); 
        exit (1); 
    } else {
    	struct node a;
    	fwrite(x, 1, sizeof(a), p);
    }      
}

void pointer_flush(struct node *r)
{	
	for (int i = 0; i < (2*t + 1); i++) {
		r->C[i] = NULL;
		r->d[i].present = false;
	}
}


void file_print(struct node *root, FILE *file)
{	
	if (root == NULL) {
		return;
	}

	//printf("%s\n", btoa(root->leaf));
	
	for (int i = 1; i <= root->n; i++) {
		fprintf(file, "%d", root->keys[i]);
		fprintf(file, " %d", root->d[i].age);
		fprintf(file, " %s", root->d[i].sex);
		fprintf(file, " %s\n", root->d[i].name);
	}

	for (int i = 1; i <= ((root->n) + 1); i++) {
		//printf("%p ", root->C[i]);
		file_print(root->C[i], file);
	}


}

void print_ll(struct node *root)
{	
	if (root == NULL) {
		return;
	}
	//printf("%s\n", btoa(root->leaf));
	for (int i = 1; i <= root->n; i++) {
		printf("%d ", root->keys[i]);
		if (root->d[i].present != false) {
			printf(" %s", root->d[i].name);
			printf(" %s", root->d[i].sex);
			printf(" %d\n", root->d[i].age);
		}
	}

	for (int i = 1; i <= ((root->n) + 1); i++) {
		//printf("%p ", root->C[i]);
		print_ll(root->C[i]);
	}
}

struct data * get_data(char name[50], int age, char sex[5])
{
	struct data *p = (struct data *) malloc(sizeof(struct data));
	strcpy(p->sex, sex);
	strcpy(p->name, name);
	p->age = age;

	return p;
}

struct node * create_btree()
{
	struct node *p = (struct node *) malloc(sizeof(struct node));
	p->leaf = true;
	p->n = 0;
	pointer_flush(p);
	return p;
}

struct node * get_node()
{
	struct node *p = (struct node *) malloc(sizeof(struct node));
	pointer_flush(p);
	return p;
}

struct node * btree_split_child(struct node *x, int i) 
{	
	struct node *z = get_node();
	struct node *y = x->C[i];
	z->leaf = y->leaf;
	z->n = t-1;

	for (int j = 1; j <= t-1; j++) {
		z->keys[j] = y->keys[j + t];
		z->d[j] = y->d[j + t];
	}

	if (y->leaf == false) {
		for (int j = 1; j <= t; j++) {
			z->C[j] = y->C[j + t];
		}
	}
	y->n = t-1;

	for (int j = x->n + 1; j >= (i + 1); j--) {
		x->C[j + 1] = x->C[j];
	}
	x->C[i + 1] = z;

	for (int j = x->n; j >= i; j--) {
		x->keys[j + 1] = x->keys[j];
		x->d[j + 1] = x->d[j];
	}
	x->keys[i] = y->keys[t];
	x->d[i] = y->d[t];
	x->n = x->n + 1;
	disk_write(y);
	disk_write(z);
	disk_write(x);

}

struct node * btree_insert_nonfull(struct node *x, int k, struct data d)
{
	int i = x->n;

	if (x->leaf == true) {
		while (i >= 1 && k < x->keys[i]) {
			x->keys[i + 1] = x->keys[i];
			x->d[i + 1] = x->d[i];
			i = i - 1;
		}
		x->keys[i + 1] = k;
		x->d[i + 1] = d;
		x->n = x->n + 1;
		disk_write(x);

	} else {
		while (i >= 1 && k < x->keys[i]) {
			i = i - 1;
		}
		i = i + 1;
		//disk_read(x->C[i]);
		if (x->C[i]->n == (2*t)-1) {
			btree_split_child(x, i);
			if (k > x->keys[i]) {
				i = i + 1;
			}
		}
		btree_insert_nonfull(x->C[i], k, d);
	}
}

struct node * btree_insert_node(struct node *root, int k, struct data d){
	struct node *r = root;

	if (r->n == ((2*t)-1)) {
		struct node *s = get_node();
		s->leaf = false;
		s->n = 0;
		s->C[1] = r;

		btree_split_child(s, 1);
		btree_insert_nonfull(s, k, d);

		return s;
	} else {
		btree_insert_nonfull(r, k, d);
		return NULL;
	}

}

struct node * btree_search(struct node *x, int k){
	int i = 1;
	while (i <= x->n && k > x->keys[i]) {
		i = i + 1;
	}

	if (i <= x->n && k == x->keys[i]) {
		printf("\nKEY NAME SEX AGE\n");		
		if (x->d[i].present != false) {
			printf("%d ", x->keys[i]);
			printf("%s ", x->d[i].name);
			printf("%s ", x->d[i].sex);
			printf("%d \n\n", x->d[i].age);
		}
		return x;
	} else if(x->leaf == true) {
		return NULL;
	} else {
		return btree_search(x->C[i], k);
	}
}

/*
	SQL DATABASE OPERATION CODE
*/

struct node * sql_insert(struct node *r)
{
	printf("\nEnter SQL QUERY\n");
	printf("FORMAT: INSERT INTO TABLE KEY AGE SEX NAME\n");
		char insert_query[1000];
		char *token[1000];
		parse(insert_query, token);

		int res = strcmp(token[0], "INSERT");
		if (res == 0) {
			int item;
			struct data d;
			d.present = true;

			sscanf(token[3], "%d", &item);
			sscanf(token[4], "%d", &d.age);
			strcpy(d.sex, token[5]);
			strcpy(d.name, token[6]);

			return btree_insert_node(r, item, d);
		}
}

void sql_search(struct node *r)
{
	printf("\nEnter SQL QUERY");
	printf("\nFORMAT: SELECT FROM TABLE KEY\n");
	
	char insert_query[1000];
	char *token[100];
	parse(insert_query, token);

	int res = strcmp(token[0], "SELECT");	
	if (res == 0) {
		int key = atoi(token[3]);
		btree_search(r, key);
	}
}

void sql_all(struct node *r)
{
	printf("\nEnter SQL QUERY");
	printf("\nFORMAT: SELECT * FROM TABLE\n");
	
	char insert_query[1000];
	char *token[100];
	parse(insert_query, token);

	int res = strcmp(token[1], "*");
	if (res == 0) {
		print_ll(r);
	}
}

struct node * readline_parse(char insert_query[1000], char *token[1000], struct node **r) 
{
    char *pch;
    for (int k = 0; k < 100; k++) {
        token[k] = NULL;
    }

    pch = strtok(insert_query, " ");

    int i = 0;
    while (pch != NULL) {
        token[i] = pch;
        pch = strtok (NULL, " ");
        i++;
    }
    token[i+1] = NULL;
   	
   	int z = 0;
	while (z != 4) {
	    	
	    	struct data d;
	    	d.present = true;
	     	int item;

	     	item = atoi(token[z]);
	     	z++;
	     	
	     	d.age = atoi(token[z]);
	     	z++;
	     	
	     	strcpy(d.sex, token[z]);
	     	z++;
	     	
	     	strcpy(d.name, token[z]);
	     	z++;

	     	//printf("%d %d %s %s\n", item, d.age, d.sex, d.name);
	     	
	     	struct node *ptr = btree_insert_node(*r, item, d);
	     	if (ptr != NULL) {
	     		*r = ptr;
	     	}
	     	return ptr;
	}
   	
}

void readline_data(struct node **r)
{
	FILE* file = fopen("q2.txt", "r"); /* should check the result */
    char line[256];
    char *token[1000];
   
    while (fgets(line, sizeof(line), file)) {
        readline_parse(line, token, r);
    }
    fclose(file);

}

void main()
{	
	struct node *root = create_btree();

	printf("\nEnter 1 to build new btree");
	printf("\nEnter 2 to construct existing btree\n");
	int choice_2;
	scanf("%d", &choice_2);

	switch(choice_2){
		case 1: printf("\n");
				int n;
				scanf("%d", &n);
				while (n) {
						int item;
						struct data d;

						d.present = true;

						scanf("%d", &item);
						scanf("%d", &d.age);
						scanf("%s", d.sex);
						scanf("%s", d.name);

						struct node *ptr = btree_insert_node(root, item, d);
						if (ptr != NULL){
							root = ptr;
						}
						n--;
					}
					break;

		case 2: printf("\n");
				readline_data(&root);

	}


	printf("\n1 ----- Add item to btree");
	printf("\n2 ----- Search item in btree");
	printf("\n3 ----- Print btree");
	printf("\n4 ----- Stop all operations\n\n");
	
	int choice;	
	while (choice != 4){
	printf("Enter operation\n");
	scanf("%d", &choice);
		switch (choice) {
			case 1: printf("\n");
					struct node *ptr = sql_insert(root);
					if (ptr != NULL){
						root = ptr;
					}
					break;
			
			case 2: printf("\n");
					sql_search(root);
					break;

			case 3: printf("\n");
					sql_all(root);
					break;
		}
	}

	FILE *file = fopen("q2.txt", "w");
	file_print(root, file); 

}