#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	t->nxt = NULL;
	t->prv = NULL;
	strcpy(t->c, c);

	return t;
}

struct node * add_node(struct node *head, int data, char *c)
{
	if (head == NULL) {
		return get_node(data, c);

	} else {
		struct node *t = head;
		while (t->nxt != NULL) {
			t = t->nxt;
		}
		struct node *p = get_node(data, c);
		t->nxt = p;
		p->prv = t;
		p->nxt = NULL;

		return head;
	}
}

struct node * create_linklist (struct node **head) {
	int n;
	scanf("%d", &n);

	while (n) {
		int data;
		char c[100];

		scanf("%s", c);
		*head = add_node(*head, data, c);
		n--;
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
	struct node *head = NULL;

	create_linklist(&head);
	print_ll(head);
}