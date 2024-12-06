#include <iostream>
using namespace std;

class Queue
{
private:
    int *array;
    // write your code here. Add additional private variables if necessary
    int front, capacity, count;

public:
    // Constructor
    Queue()
    {
        array = new int[1];
        // write your code here. Initialize additional private variables if necessary
        capacity = 1;
        front = 0;
        count = 0;
    }
    Queue(int initialCapacity)
    {
        array = new int[initialCapacity]; // Allocate initial memory
        // write your code here. Initialize additional private variables if necessary
        capacity = initialCapacity;
        front = 0;
        count = 0;
    }

    // Destructor
    ~Queue()
    {
        delete[] array; // Free dynamically allocated memory
    }

    // Helper function to resize the array when full
    void resize(int newCapacity)
    {
        int *newArray = new int[newCapacity]; // Allocate new array

        // write your code here. Copy the elements from the old array to the new array
        for (int i = 0; i < count; i++)
        {
            newArray[i] = array[front + i];
        }

        delete[] array; // Free old memory

        // write your code here. Update the capacity and array pointers
        array = newArray;
        capacity = newCapacity;
        front = 0;
    }

    // Enqueue an element onto the queue
    void enqueue(int x)
    {
        // write your code here. Check if the array is full and resize if necessary.
        if (count == capacity)
            resize(2 * capacity);
        array[front+count] = x;
        count++;
    }

    // Remove and return the peek element
    int dequeue()
    {
        // write your code here. Check if the stack is empty and return -1 if it is.
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        // remove the peek element and return it
        int elem = array[front];
        for(int i=1; i<count; i++)
        {
            array[i-1]=array[i];
        }
        count--;
        // resize the array if necessary
        if (count > 0 && count <= capacity / 4)
            resize(capacity / 2);
        return elem;
    }

    // Return the peek element without removing it
    int peek()
    {
        // write your code here. Check if the queue is empty and return -1 if it is.
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        // return the peek element
        return array[front];
    }

    // Return the number of elements in the queue
    int length()
    {
        // write your code here. Return the number of elements in the queue
        return count;
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        // write your code here. Return true if the queue is empty, false otherwise
        return count == 0;
    }

    // Clear the queue
    void clear()
    {
        // write your code here. Clear the queue. resize the array to 1
        delete[] array;
        capacity = 1;
        array = new int[capacity];
        front = 0;
        count = 0;
    }
};
