#include <stdio.h>
#include <stdlib.h>

void findSecondLargest(int arr[], int n)
{
	// Your code here
	if (n < 2)
	{
		printf("invalid input\n");
		return;
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] < arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			printf("%d\n", arr[i + 1]);
			break;
		}
		else
		{
			printf("second largest element not found\n");
			break;
		}
	}
}

int main()
{
	int T, t, n, i, second;
	int *arr;
	FILE *fin, *fout;
	// Redirect input and output streams
	fin = freopen("input.txt", "r", stdin);
	fout = freopen("output.txt", "w", stdout);

	// Input the number of test cases
	scanf("%d", &T);

	for (t = 0; t < T; t++)
	{
		// Input the size of  the array
		scanf("%d", &n);
		// Dynamically allocate the size of the array
		arr = (int *)malloc(n * sizeof(int));
		// Input the elements of the array
		for (i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}
		// Find and print the second largest element
		findSecondLargest(arr, n);
		free(arr);
	}
	// Close the file streams
	fclose(fin);
	fclose(fout);
	return 0;
}
