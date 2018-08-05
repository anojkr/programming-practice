#include<stdio.h>
#include<stdlib.h>

typedef struct node //declaring structure format
{
	int data;
	struct node *link;
} NODE;


NODE *front, *rear;
//node pointer to queue front and rear


NODE * create_queue(int data){
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
	//function to remove node from queue from front end

	if (front !='\0'){
		struct node *t= front;
		front= front->link;
		printf("%d is deleted from queue\n",t->data );
		free(t);
	}
}

void print_queue(struct node *t){
	printf("\nElement in queue\n");
	while(t!='\0'){
		printf("%d \n", t->data);
		t=t->link;
	}
}

int main(){
	int n, d;
	printf("\nEnter number of items to be inserted in queue\n");
	scanf("%d", &n);

	for (int i=0; i<n;i++){
		int data;
		printf("\nEnter item to be inserted in queue\n");
		scanf("%d", &data);
		if (i==0){
				front = create_queue(data);
				rear= front;
		}
		else{
			add_node_queue(data);
		}
	}

	print_queue(front);


	printf("\nEnter number of items to be deleted in queue\n");
	scanf("%d", &d);
	if(d<=n){
		for (int i=0; i<d;i++){
			remove_node_from_queue(front);
		}
			print_queue(front);
	}
	else{
		printf("Delete operation overflow\n");
	}



}