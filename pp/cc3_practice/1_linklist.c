#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int data;
	char c[100];
	struct node *nxt;
	struct node *prv;
};

struct node * get_node(int data, char *c) 
{
	struct node *t = (struct node *) malloc(sizeof(struct node));
	t->data = data;
	strcpy(t->c, c);
	t->nxt = NULL;
	t->prv = NULL;

	return t;
}

struct node * add_node(struct node *head, int data, char *c)
{
	struct node *t = head;

	if (head == NULL) {
		return get_node(data, c);

	} else {
		while (t->nxt != NULL){
			t = t->nxt;
		}

		struct node *p = get_node(data, c);
		p->nxt = NULL;
		t->nxt = p;
		p->prv = t;
		
		return head;
	}
}


void print_ll(struct node *head) {
	if (head == NULL) {
		return;
	}

	struct node * t = head;
	while (t->nxt != NULL) {
		//printf("%s\n", t->c);
		t = t->nxt;
	}

	while (t!= NULL) {
		printf("%s\n", t->c);
		t = t->prv;
	}

}

void main() 
{
	struct node *head =  NULL;

	int n;
	scanf("%d", &n);

	while (n) {
		char c[100];
		scanf("%s", c);
		int data = strlen(c);
		head = add_node(head, data, c);
		n--;
	}
	print_ll(head);

}


