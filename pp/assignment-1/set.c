#include <stdio.h>

void distinct(int arr[], int n)
{
	// Pick all elements one by one
	for (int i=0; i<n; i++)
	{
		// Check if the picked element is already printed
		int j;
		for (j=0; j<i; j++)
		if (arr[i] == arr[j])
			break;

		// If not printed earlier, then print it
		if (i == j)
		printf("%d \t", arr[i]);
	}
}

