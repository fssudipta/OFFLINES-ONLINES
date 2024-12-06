#include <iostream>
using namespace std;

class Stack
{
private:
    int *array;
    // write your code here. Add additional private variables if necessary
    int cap;
    int topIndex;

public:
    // Constructor
    Stack()
    {
        array = new int[1];
        // write your code here. Initialize additional private variables if necessary
        cap = 1;
        topIndex = -1;
    }
    Stack(int initialCapacity)
    {
        array = new int[initialCapacity]; // Allocate initial memory
        // write your code here. Initialize additional private variables if necessary
        cap = initialCapacity;
        topIndex = -1;
    }

    // Destructor
    ~Stack()
    {
        delete[] array; // Free dynamically allocated memory
    }

    // Helper function to resize the array when full
    void resize(int newCapacity)
    {
        int *newArray = new int[newCapacity]; // Allocate new array

        // write your code here. Copy the elements from the old array to the new array
        for (int i = 0; i <= topIndex; i++)
        {
            newArray[i] = array[i];
        }
        delete[] array; // Free old memory
        // write your code here. Update the capacity and array pointers
        array = newArray;
        cap = newCapacity;
    }

    // Push an element onto the stack
    void push(int x)
    {
        // write your code here. Check if the array is full and resize if necessary.
        if (topIndex == cap - 1)
        {
            resize(2 * cap);
        }
        // push the element onto the stack
        topIndex++;
        array[topIndex] = x;
    }

    // Remove and return the topIndex element
    int pop()
    {
        // write your code here. Check if the stack is empty and return -1 if it is.
        if (isEmpty())
        {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        // pop the topIndex element and return it
        int popup = array[topIndex];
        topIndex--;
        // resize the array if necessary
        if (topIndex < cap / 4 && cap > 1)
        {
            resize(cap / 2);
        }
        return popup;
    }

    // Return the top element without removing it
    int top()
    {
        // write your code here. Check if the stack is empty and return -1 if it is.
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        // return the top element
        return array[topIndex];
    }

    // Return the number of elements in the stack
    int length()
    {
        // write your code here. Return the number of elements in the stack
        return topIndex + 1;
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        // write your code here. Return true if the stack is empty, false otherwise
        return topIndex == -1;
    }

    // Clear the stack
    void clear()
    {
        // write your code here. Clear the stack. resize the array to 1
        delete[] array;
        array = new int[1];
        cap = 1;
        topIndex = -1;
    }
};
