#include <iostream>
#include "QueueLinkedList.h"

using namespace std;

class Stack
{
private:
    // write your code here. Add additional private variables if necessary
    Queue q1;

public:
    // Constructor
    Stack()
    {
        // write your code here. Initialize additional private variables if necessary
    }
    Stack(int initialCapacity)
    {
        // write your code here. Initialize additional private variables if necessary
    }

    // Destructor
    ~Stack() { }

    // Push an element onto the stack
    void push(int x)
    {
        // write your code here.
        q1.enqueue(x);
        // push the element onto the stack
        int size=q1.length();
        for(int i=0; i<size-1; i++)
        {
            q1.enqueue(q1.dequeue());
        }
    }

    // Remove and return the top element
    int pop()
    {
        // write your code here. Check if the stack is empty and return -1 if it is.
        if (q1.isEmpty())
        {
            cout << "Stack is empty." << endl;
            return -1;
        }
        // pop the top element and return it
        return q1.dequeue();
    }

    // Return the top element without removing it
    int top()
    {
        // write your code here. Check if the stack is empty and return -1 if it is.
        if (q1.isEmpty())
        {
            cout << "Stack is empty." << endl;
            return -1;
        }
        // return the top element
        return q1.peek();
    }

    // Return the number of elements in the stack
    int length()
    {
        // write your code here. Return the number of elements in the stack
        return q1.length();
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        // write your code here. Return true if the stack is empty, false otherwise
        return q1.length() == 0;
    }

    // Clear the stack
    void clear()
    {
        // write your code here. Clear the stack.
        q1.clear();
    }

    void sortQueue()
    {
        Queue tempQueue;

        while (!q1.isEmpty())
        {
            int current = q1.dequeue();
            
            while (!tempQueue.isEmpty() && tempQueue.peek() < current)
            {
                q1.enqueue(tempQueue.dequeue());
            }

            tempQueue.enqueue(current);
        }

        while (!tempQueue.isEmpty())
        {
            q1.enqueue(tempQueue.dequeue());
        }
    }
};
