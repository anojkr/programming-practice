#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* newNode(int data)
{
	struct Node* new_node =
		(struct Node*)malloc(sizeof(struct Node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

struct Node * getnode(){
	struct Node * t = (struct Node *)malloc(sizeof(struct Node));
	t -> next = NULL;
	return t;
}

void add_node( struct Node ** head, int item ){

	if ( *head == NULL ){
	
		struct Node *k =  getnode();
		k -> data = item;
		k -> next = NULL;
		*head = k;

	} else {
	
		struct Node *t = *head;
		while ( t -> next != NULL ){
			t = t-> next;
		}
		struct Node *newnode = getnode();
		newnode -> data = item;
		newnode -> next = NULL;
		t -> next = newnode;

	}

}

long multint(struct Node * first, struct Node * second)
{
    int num1 = 0, num2 = 0;

    // Generate numbers from linked lists
    while (first || second)
    {
        if (first)
        {
            num1 = num1*10 + first->data;
            first = first->next;
        }
        
        if (second)
        {
            num2 = num2*10 + second->data;
            second = second->next;
        }
    }

    // Return multiplication of
    // two numbers
    return num1*num2;
}

// A utility function to print a linked list
void printList(struct Node* Node)
{
	while (Node != NULL) {
		printf("%d", Node->data);
		if (Node->next)
			printf("->");
		Node = Node->next;
	}
	printf("\n");
}

// Driver program to test above function
int main(void)
{
	struct Node* first = NULL;
	struct Node* second = NULL;
    int t = 1;

	printf("\nEnter first number\n");
	while (t){
	    int item;
	    printf("enter number\n");
	    scanf("%d", &item);
	    add_node(&first, item);
	    printf("\nEnter -1 to stop or 1 continue\n");
	    scanf("%d", &t);
	    if (t == -1){
			break;
		}
	}
	

printf("\nEnter second number\n");
int k = 1;
while(k){
    int item_2;
    printf("enter number\n");
    scanf("%d", &item_2);
	add_node(&second, item_2);
    printf("\nEnter -1 to stop to 1 continue\n");
	scanf("%d", &k);
	if (k == -1){
		break;
	}
}
	printf("First List is: ");
	printList(first);

	printf("\nSecond List is: \n");
	printList(second);

	// Multiply the two lists and see result
	printf("Result = %d",multint(first, second));

	return 0;
}
