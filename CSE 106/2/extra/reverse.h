#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }

    Node(int value, Node *nextNode)
    {
        data = value;
        next = nextNode;
    }
};

class Stack
{
private:
    Node *topNode; // Points to the top of the stack
    int currentSize;

public:
    // Constructor
    Stack()
    {
        topNode = nullptr;
        currentSize = 0;
    }

    // Push an element onto the stack
    void push(int x)
    {
        // write your code here. Create a new node with the value x and push it onto the stack
        Node *newNode = new Node(x, topNode);
        // update the topNode and currentSize
        topNode = newNode;
        currentSize++;
    }

    // Remove and return the top element
    int pop()
    {
        // write your code here. Check if the stack is empty and return -1 if it is.
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        // pop the top element and return it
        int popup = topNode->data;
        // update the topNode and currentSize
        Node *temp = topNode;
        topNode = topNode->next;
        // delete the node that was popped
        delete temp;
        currentSize--;
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
        return topNode->data;
    }

    // Return the number of elements in the stack
    int length()
    {
        // write your code here. Return the number of elements in the stack
        return currentSize;
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        // write your code here. Return true if the stack is empty, false otherwise
        return topNode == nullptr;
    }

    void reverse()
    {
        if (!isEmpty())
        {
            int topelem = pop();
            reverse();
            insertAtBottom(topelem);
        }
    }

    void insertAtBottom(int val)
    {
        if (isEmpty())
            push(val);
        else
        {
            int topelem = pop();
            insertAtBottom(val);
            push(topelem);
        }
    }
    // Clear the stack
    void clear()
    {
        while (!isEmpty())
        {
            pop(); // Continuously pop elements until the stack is empty
        }
    }

    // Destructor
    ~Stack()
    {
        while (!isEmpty())
        {
            pop(); // Continuously pop elements until the stack is empty
        }
        // or just clear();
    }
};
