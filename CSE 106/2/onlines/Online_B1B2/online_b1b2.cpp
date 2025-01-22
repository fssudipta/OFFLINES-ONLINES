// #include "StackArray.h" // Include Linked-List/ArrayList based Stack implementation
#include <cstdio>            // For FILE*, fopen, fscanf, fprintf


// Function to simulate Fibonacci calls and count how many times the function is called
int countFibCalls(int n)
{
    
    //write your code here

    
    return 0;
}

// Process the test cases
void processTestCases(FILE *inputFile, FILE *outputFile)
{
    int testCases;
    fscanf(inputFile, "%d", &testCases);  // Read the number of test cases

    for (int t = 1; t <= testCases; ++t)
    {
        fprintf(outputFile, "Test Case %d:\n", t);

        int n;
        fscanf(inputFile, "%d", &n);  // Read the Fibonacci number index

        

        // Count the Fibonacci function calls for this test case
        int totalCalls = countFibCalls(n);

        // Output the result
        fprintf(outputFile, "The Fibonacci function is called %d times for n = %d\n", totalCalls, n);
        fprintf(outputFile, "-------------------\n");
    }
}

int main()
{
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL)
    {
        perror("Error opening input or output file");
        return 1;
    }

    fprintf(outputFile, "-------------Testing Fibonacci Call Counting-------------\n");
    processTestCases(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
