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

class Queue
{
private:
    Node *peekNode; // Points to the front of the queue
    int currentSize;

public:
    // Constructor
    Queue()
    {
        peekNode = nullptr;
        currentSize = 0;
    }

    // Enqueue an element onto the queueu
    void enqueue(int x)
    {
        // write your code here. Create a new node with the value x and enqueue it onto the queue
        Node *newNode = new Node(x);
        // update the peekNode and currentSize
        if (peekNode == nullptr)
            peekNode = newNode;
        else
        {
            Node *temp = peekNode;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        currentSize++;
    }

    // Remove and return the peek element
    int dequeue()
    {
        // write your code here. Check if the queueu is empty and return -1 if it is.
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        // dequeue the peek element and return it
        int elem = peekNode->data;
        Node *temp = peekNode;
        // update the peekNode and currentSize
        peekNode = peekNode->next;
        // delete the node that was dequeued
        delete temp;
        currentSize--;
        return elem;
    }

    // Return the peek element without removing it
    int peek()
    {
        // write your code here. Check if the queueu is empty and return -1 if it is.
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        // return the peek element
        return peekNode->data;
    }

    // Return the number of elements in the queueu
    int length()
    {
        // write your code here. Return the number of elements in the queueu
        return currentSize;
    }

    // Check if the queueu is empty
    bool isEmpty()
    {
        // write your code here. Return true if the queueu is empty, false otherwise
        return currentSize == 0;
    }

    // Clear the queueu
    void clear()
    {
        while (!isEmpty())
        {
            dequeue(); // Continuously dequeue elements until the queueu is empty
        }
    }

    // Destructor
    ~Queue()
    {
        clear();
    }
};
