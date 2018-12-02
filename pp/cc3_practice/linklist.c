#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int data;
	char c[100];
	struct node * nxt;
};

struct node * get_node(int data, char *c) 
{
	struct node *t = (struct node *) malloc(sizeof(struct node));
	t->data = data;
	strcpy(t->c, c);
	t->nxt = NULL;
}

void print_ll(struct node * head) 
{
	struct node *t = head;
	while (t != NULL) {
		printf("%s ", t->c);
		printf("%d\n", t->data);
		t = t->nxt;
	}	
}

struct node * add_node(struct node *head, int data, char *c)
{
	struct node *t = head;
	if (head == NULL) {
		return get_node(data, c);
	} else {
		while (t->nxt != NULL) {
			t = t->nxt;
		}
		struct node *tmp = get_node(data, c);
		t->nxt = tmp;
		return head;
	}
}
void main() 
{
	struct node *head = NULL;
	int n;
	scanf("%d", &n);
	while (n) {
		int data;
		char c[100];
		scanf("%s", c);
		data = strlen(c);
		head = add_node(head, data, c);
		n--;
	}
	print_ll(head);
}
