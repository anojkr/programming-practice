#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct stack {
	int top;
	int arr[SIZE];
};

void push(struct stack *S, int item){
	if ( (S -> top) < SIZE ){
		
		(S -> top)++;
		S -> arr[ (S -> top) ] = item;
	
	}else {

		printf("\nOverflow\n");
	
	}
}

int pop(struct stack *S){
	if (S -> top >= 0 ){
	
		int item = S -> arr[ (S->top) ];
		(S -> top)--;
		return item;
	
	} else {
	
		printf("\nUnderflow\n");
	
	}

}

int is_empty(struct stack *S){
		if ((S -> top) < 0){
			return 1;
		} else {
			return 0;
		}

}


int top(struct stack *S){
	if (!is_empty(S)){
		return S -> arr[S->top];
	}

}

void insert(struct stack *S, int item){
	if (!is_empty(S)){

		int y = top(S);	
		if (item > y){
			pop(S);
			insert(S, item);
			push(S, y);

		} else {
			push(S, item);

		}

	} else {
		push(S, item);
	}
}

void sort(struct stack *S){
	if (!is_empty(S)){
		int x = pop(S);
		sort(S);
		insert(S, x);
	} else {
		return;
	}
}

void print_ll(struct stack *S){
	printf("\n");
	int i = S -> top;
	while (i>-1){
		printf("%d ", S->arr[i]);
		i--;
	}
	printf("\n");
}

void main(){
	struct stack S;
	S.top = -1;

	int n;
	scanf("%d", &n);

	while(n){
		int item;
		scanf("%d", &item);
		push(&S, item);
		n--;
	}

	printf("\nStack Status\n");
	print_ll(&S);

	printf("\nSorted Stack\n");
	sort(&S);
	print_ll(&S);

}
