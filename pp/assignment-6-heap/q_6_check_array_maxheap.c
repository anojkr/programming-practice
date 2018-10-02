#include <stdio.h>
#include <stdlib.h>

void swap(int *arr, int largest, int i){
        
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
}

int heapify(int *arr, int i, int n){
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;

        if (arr[l] > arr[largest] && l < n){
                largest = l;
        }

        if (arr[r] > arr[largest] && r < n){
                largest = r;
        }

        if (largest != i){
            return 0;
            swap(arr, largest, i);
            heapify(arr, largest, n);
            	
	    }
    return 1;

}

int build_heap(int *arr, int n){
	
        for (int i = n/2 ; i >= 0; i--){
		  int x = heapify(arr, i, n);
          if (x == 0){
                break;
                return 0;
          }
	}

}


void print_ll(int *arr, int n){

        printf("\n");
        for (int i = 0; i < n; i ++){
                printf("%d ", arr[i]);

        }

}

void main(){

        int t;
        scanf("%d", &t);
        
        while (t){
        	int n;
        	scanf("%d", &n);


        	int arr[100];

        	for (int i = 0; i < n; i ++){
        		int item;
        		scanf("%d", &arr[i]);
        	}
       	
            int x = build_heap(arr, n);
                if (x  == 0){
                    printf("no\n");
                }else {
                    printf("yes\n");
                }
                //print_ll(arr, n );
            t--;
        }
}
