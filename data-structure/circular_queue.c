#include<stdio.h>

int SIZE, front=0, rear=0;
//int QUEUE[];


int is_full(){
// is_full() is function to check for Queue is full or not
	rear = (rear+1)%SIZE;
	if( front == rear) {
		printf("QUEUE is full cannot perform en_queue operation\n");
		if (rear == 0 ){
			rear = SIZE-1;
		}

		else {
			rear = rear-1;
		}

		return 1;
	}

	return 0;
}

int is_empty(){
// is_empty() is here to check for Queue is empty or not
	if (rear == front) {
		printf("QUEUE is empty cannot perform de_queue operation\n");
		return 1;
	}
	return 0;

}

void en_queue(int value, int *P){
// en_queue() is function to add element in circular queue
	if (is_full() != 1){
		printf("%d : inserted in queue\n", value );
		P[rear] = value;
	}
}

int de_queue(int *P){
//de_queue() is function to remove element from circular queue
	if(is_empty() != 1){
		front = (front + 1)%SIZE;
		int value = P[front];
		P[front] = -1;
		printf("De_Queue value from queue = %d\n", value );
		return value;
	}

	return 0;

}

void print_arry(int *P){
	//function to print value present in queue
	for(int i=0; i<SIZE; i++){
		printf("QUEUE value %d \n", P[i]);
	}
}


void insert_value_in_queue(int t, int *P){
	// function to perform t-times enqueue operation to performed
	if (t<=SIZE){
		int s[t];
		for(int i=0; i<t; i++){
			printf("Enter value to be inserted in queue\n");
			scanf("%d", &s[i]);
			en_queue(s[i], P);
		}
	}

	else{
		printf("QUEUE operation overflow\n");
	}
}


void remove_value_from_queue(int t, int *P){
	// function to perform t-times de_queue operation
	if(t<=SIZE){
		for (int i=0; i<t; i++){
			if (de_queue(P) == 0){
				break;
			}
		}
	}
	else{
		printf("QUEUE operation overflow\n");

	}
}



void main(){
	printf("Enter QUEUE size\n");
	scanf("%d", &SIZE);
	int QUEUE[SIZE], ti, n_items;
	printf("Enter number of en_queue operation to be performed\n");
	scanf("%d", &n_items);
	insert_value_in_queue(n_items, QUEUE);

	//print_arry(QUEUE);
	printf("Enter number of times de_queue to be performed \n");
	scanf("%d", &ti);
	remove_value_from_queue(ti, QUEUE);

	print_arry(QUEUE);
}