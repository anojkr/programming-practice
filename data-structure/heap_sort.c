#include<stdio.h>
#include<stdlib.h>

int HEAP_SIZE;

void heapify(int A[], int i){
	int largest;
	int l = (2*i)+1;
	int r = (2*i)+2;

	if(l>HEAP_SIZE){
	    return;
	}
	
	else{
    		if (l<HEAP_SIZE && A[l]>A[i]){
    			
			largest = l;
    		}
    	
    		else{
    			largest = i;
    		}
    	
    		if(r<HEAP_SIZE && A[r]>A[largest]){
    	
    			largest = r;	
    		}
         	
		if (largest != i){
		
			int temp = A[i];
			A[i] = A[largest];
			A[largest] = temp;
			heapify(A, largest);
    		}
	}
}

void build_heap(int A[]){
	for(int i=(HEAP_SIZE/2); i>=0; i--){
	heapify(A, i);
    }
}

void print_heap(int A[]){
    	printf("Heap status");
	for(int i=0 ;i<HEAP_SIZE; i++){
        	printf("%d", A[i]);
    	}
}

void heap_sort(int A[], int SIZE){
	build_heap(A);
	for(int i=SIZE-1; i>0 ; i--){
		int temp = A[0];
		A[0] = A[SIZE];
		A[SIZE] = temp;
		heapify(A, 0);
	}

}

void main(){
	HEAP_SIZE = 5;
	int heap[]={7,5,9,3,2};
    	heap_sort(heap,5);
	print_heap(heap);
}




