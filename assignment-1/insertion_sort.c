// C program for insertion sort
#include <stdio.h>
#include <math.h>

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
int i, key, j;
for (i = 1; i < n; i++)
{
	key = arr[i];
	j = i-1;

	while (j >= 0 && arr[j] > key)
	{
		arr[j+1] = arr[j];
		j = j-1;
	}
	arr[j+1] = key;
}
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
int i;
for (i=0; i < n; i++)
	printf("%d ", arr[i]);
printf("\n");
}

