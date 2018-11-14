#include <stdio.h>
#include <stdlib.h>
#include "heap.c"

int print_sumarr(int *sum_arr, int k)
{	
	int sum = 0;
	for (int i = 0; i <= k; i++){
		sum = sum_arr[i] + sum;
		//printf("%d ", sum_arr[i]);
	}
	printf("%d\n", sum);

	return sum;
}

int optimal_merge_pattern(int *arr, int k, int *n)
{		
	int sum_arr[k];
	for (int i = 0; i < k-1; i++) {
			int x = get_min_element(arr, n);
			int y = get_min_element(arr, n);

			sum_arr[i] = x+y;
			insert_heap(arr, x+y, n);
	}
	//print_ll(arr, *n);
	print_sumarr(sum_arr, sizeof(sum_arr)/sum_arr[0]);

}

void main()
{
	int n;
	scanf("%d", &n);
	int arr[n];
	
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	build_heap(arr, n);
	optimal_merge_pattern(arr, n, &n);

}