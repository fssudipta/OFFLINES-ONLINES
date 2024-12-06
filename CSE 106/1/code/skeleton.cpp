#include <iostream>
using namespace std;

struct listNode
{
    int item;
    struct listNode *next;
    struct listNode *prev;
};

// Both head and tail pointers for the stack
struct listNode *head = nullptr;
struct listNode *tail = nullptr;

// Function to check if the stack is empty
bool isEmpty()
{
    return head == nullptr;
}

// Function to push an element onto the stack
void push(int value)
{
    // Create a new node
    struct listNode *newNode = new listNode();
    newNode->item = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    // If the stack is empty, set both head and tail to the new node
    if (isEmpty())
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        // Insert the new node at the head (LIFO: Last In First Out)
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    cout << value << " pushed onto the stack.\n";
}

// Function to pop an element from the stack
int pop()
{
    if (isEmpty())
    {
        cout << "Stack underflow! The stack is empty.\n";
        return -1; // Return -1 to indicate stack is empty
    }

    // Save the value of the current head
    int poppedValue = head->item;

    // Move the head pointer to the next node
    struct listNode *temp = head;
    head = head->next;

    // If head is not nullptr, set the new head's prev pointer to nullptr
    if (head != nullptr)
    {
        head->prev = nullptr;
    }
    else
    {
        // If the stack is empty after pop, reset the tail as well
        tail = nullptr;
    }

    // Delete the old head node
    delete temp;

    return poppedValue;
}

// Function to view the top element (peek)
int peek()
{
    if (isEmpty())
    {
        cout << "Stack is empty! No top element.\n";
        return -1;
    }
    return head->item;
}

// Function to view the bottom element (tail)
int peekBottom()
{
    if (isEmpty())
    {
        cout << "Stack is empty! No bottom element.\n";
        return -1;
    }
    return tail->item;
}

// Driver function to test the stack
int main()
{
    push(10);
    push(20);
    push(30);

    cout << "Top element is: " << peek() << endl;          // Should print 30
    cout << "Bottom element is: " << peekBottom() << endl; // Should print 10

    cout << pop() << " popped from stack.\n"; // Should print 30
    cout << pop() << " popped from stack.\n"; // Should print 20
    cout << pop() << " popped from stack.\n"; // Should print 10

    // Try popping from an empty stack
    cout << pop() << " popped from stack.\n"; // Should indicate underflow

    return 0;
}
