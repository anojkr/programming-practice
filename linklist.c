#include<stdio.h>
#include<stdlib.h>

struct node //declaring structure format
{
	int data;
	struct node *link;
};

struct node *front, *rear;
//node pointer to queue front and rear

struct node * create_queue(int data){
	//function to create queue
	struct node *head =  (struct node *)malloc(sizeof(struct node));
	head->data = data;
	head->link = '\0';
	return head;
}

void add_node_queue(int data){
	//function to add node to queue on rear end
	struct node *t =  (struct node *)malloc(sizeof(struct node));
	while(rear->link!='\0'){
		rear = rear->link;
	}

	t->data = data;
	rear->link = t;
	rear = t;
}

void remove_node_from_queue(){
	//functiont to remove node from queue from front end
	struct node *t= front;
	front= front->link;
	printf("%d is deleted from queue\n",t->data );
	free(t);
}

void print_queue(struct node *t){
	while(t!='\0'){
		printf("Element in queue %d\n", t->data);
		t=t->link;
	}
}

int main(){

	front = create_queue(5);
	rear= front;

	add_node_queue(10);
	add_node_queue(20);
	add_node_queue(30);
	add_node_queue(40);
	print_queue(front);

	remove_node_from_queue(front);
	remove_node_from_queue(front);
	print_queue(front);
	return 0;

}