#include "StackLinkedList.h"  // Use Stack from Linked-List/ArrayList based implementation
#include <cstdio>             // For FILE*, fopen, fscanf, fprintf

void printStack(Stack &stack, FILE *outputFile)
{
    Stack tempStack;
    while (!stack.isEmpty())
    {
        int value = stack.pop();
        tempStack.push(value);
    }
    while (!tempStack.isEmpty())
    {
        int value = tempStack.pop();
        stack.push(value);
        fprintf(outputFile, "%d ", value);
    }
    fprintf(outputFile, "\n");
}

// Function to find visible buildings from the right side
void findVisibleBuildings(int heights[], int n, FILE *outputFile)
{
    Stack stack;  // Stack to store the visible buildings
   

    // Output the visible buildings in the correct order (from left to right)
    fprintf(outputFile, "Visible buildings: ");
    
    printStack(stack, outputFile);
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
        fscanf(inputFile, "%d", &n);  // Read the number of buildings

        int heights[n];  // Create an array to store the building heights
        for (int i = 0; i < n; ++i)
        {
            fscanf(inputFile, "%d", &heights[i]);  // Read each building's height
        }

        // Find the visible buildings for this test case
        findVisibleBuildings(heights, n, outputFile);

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

    fprintf(outputFile, "-------------Testing Visible Buildings-------------\n");
    processTestCases(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
