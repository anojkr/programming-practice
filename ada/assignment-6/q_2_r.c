#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};


struct Node * getnode(){
	struct Node * t = (struct Node *)malloc(sizeof(struct Node));
	t -> next = NULL;
	return t;
}

void add_node( struct Node ** head, int item ){

	if ( *head == NULL ){
	
		struct Node *k =  getnode();
		*head = k;
		k -> data = item;
		k -> next = *head;

	} else {
	
		struct Node *t = *head;
		while ( t -> next != *head ){
			t = t-> next;
		}
		struct Node *newnode = getnode();
		t -> next = newnode;
		newnode -> data = item;
		newnode -> next = *head;

	}

}

int count(struct Node * head){
	int c=0;
	struct Node *t = head;
	while (t -> next != head){
		t = t-> next;
		c++;
	}
	return c+1;
}

long multint(struct Node * first, struct Node * second)
{
    int num1 = 0, num2 = 0;
    struct Node *f = first;
    struct Node *s = second;

    int c_1 = count(f);
    int c_2 = count(s);

   // printf("fisrst count %d", c_1); 
   // printf("second count %d", c_2);


    for(int i=0; i<c_1; i++){
    	    num1 = num1*10 + f->data;
            f = f->next;
 
    }

    printf("%d\n", num1);


    for(int i=0; i<c_2; i++){
    	    num2 = num2*10 + s->data;
            s = s->next;
 
    }


    printf("%d", num2);
    printf("\nNOW result = %d \n", num1*num2);
    return num1*num2;
}

void printList(struct Node *head)
{	struct Node *t = head;
	while (t -> next!= head) {
		printf("%d", t->data);
		if (t -> next)
			printf("->");
		t = t -> next;
	}
	printf("%d", t->data);
	printf("\n");
}

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
	printf("Result = %ld",multint(first, second));

	return 0;
}

