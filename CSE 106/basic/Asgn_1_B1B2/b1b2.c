#include <stdio.h>
#include <stdlib.h>

void countInversion(int arr[], int n) {
	// Your code here 
	if(n<=1)
	{
		printf("invalid input\n");
		return;
	}
	int cnt=0;
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(arr[i]>arr[j]) cnt++;
		}
	}
	printf("%d\n", cnt);
}

int main() {
	int T, t, n, i, inv;
	int *arr;
	FILE *fin, *fout;
	// Redirect input and output streams
	fin  = freopen("input.txt", "r", stdin);
	fout = freopen("output.txt", "w", stdout);

	// Input the number of test cases
	scanf("%d", &T);

	for (t = 0; t < T; t++) {
		// Input the size of  the array
		scanf("%d", &n);
		// Dynamically allocate the size of the array
		arr = (int *)malloc(n * sizeof(int));
		 // Input the elements of the array
    		for (i = 0; i < n; i++) {
    			scanf("%d", &arr[i]);
		}
		// Find and print the max-triplet
		countInversion(arr, n);
		free(arr);
	}
	// Close the file streams
	fclose(fin);
	fclose(fout);
	return 0;
}

