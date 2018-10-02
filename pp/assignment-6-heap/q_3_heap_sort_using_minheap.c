#include <stdio.h>
#include <stdlib.h>

void swap(int *arr, int largest, int i){
        
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
}

void heapify(int *arr, int i, int n){
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;

        if (arr[l] < arr[largest] && l < n){
                largest = l;
        }

        if (arr[r] < arr[largest] && r < n){
                largest = r;
        }

        if (largest != i){
                swap(arr, largest, i);
		heapify(arr, largest, n);	
	}

}

void build_heap(int *arr, int n){
	
        for (int i = n/2 ; i >= 0; i--){
		heapify(arr, i, n);
	}

}

void heap_sort(int *arr, int n){

        build_heap(arr, n);
        for (int i = n-1; i >=0; i--){
                swap(arr, 0, i);
                heapify(arr, 0, i);
        }

}

void delete_heap_element(int *arr, int *n){
        int temp = arr[0];
        arr[0] = arr[*n-1];
        *n = *n - 1;
        heapify(arr, 0, *n);

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
       	
        build_heap(arr, n);
        print_ll(arr, n);

        }
}
