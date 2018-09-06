// C program to Multiply two numbers
// represented as linked lists
#include <stdio.h>
#include <stdlib.h>

// Linked list Node
struct Node {
	int data;
	struct Node* next;
};

// Function to create a new Node
// with given data
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


// Function to reverse the linked list and return
// its length
int reverse(struct Node** head_ref)
{
	struct Node* prev = NULL;
	struct Node* current = *head_ref;
	struct Node* next;
	int len = 0;
	while (current != NULL) {
		len++;
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
	return len;
}

// Function to make an empty linked list of
// given size
struct Node* make_empty_list(int size)
{
	struct Node* head = NULL;
	while (size--)
		add_node(&head, 0);
	return head;
}

// Multiply contents of two linked lists => store
// in another list and return its head
struct Node* multint(struct Node* first, struct Node* second)
{
	// reverse the lists to muliply from end
	// m and n lengths of linked lists to make
	// and empty list
	int m = reverse(&first), n = reverse(&second);

	// make a list that will contain the result
	// of multiplication.
	// m+n+1 can be max size of the list
	struct Node* result = make_empty_list(m + n + 1);

	// pointers for traverse linked lists and also
	// to reverse them after
	struct Node *second_ptr = second,
		*result_ptr1 = result, *result_ptr2, *first_ptr;

	// multiply each Node of second list with first
	while (second_ptr) {

		int carry = 0;

		// each time we start from the next of Node
		// from which we started last time
		result_ptr2 = result_ptr1;

		first_ptr = first;

		while (first_ptr) {

			// multiply a first list's digit with a
			// current second list's digit
			int mul = first_ptr->data * second_ptr->data
					+ carry;

			// Assigne the product to corresponding Node
			// of result
			result_ptr2 -> data += mul % 10;

			// now resultant Node itself can have more
			// than 1 digit
			carry = mul / 10 + result_ptr2->data / 10;
			result_ptr2->data = result_ptr2->data % 10;

			first_ptr = first_ptr->next;
			result_ptr2 = result_ptr2->next;
		}

		// if carry is remaining from last multiplication
		if (carry > 0) {
			result_ptr2->data += carry;
		}

		result_ptr1 = result_ptr1->next;
		second_ptr = second_ptr->next;
	}

	// reverse the result_list as it was populated
	// from last Node
	reverse(&result);
	reverse(&first);
	reverse(&second);

	// remove if there are zeros at starting
	while (result->data == 0) {
		struct Node* temp = result;
		result = result->next;
		free(temp);
	}

	// Return head of multiplication list
	return result;
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
	struct Node* result = multint(first, second);
	printf("\nResultant list is: \n");
	printList(result);

	return 0;
}
