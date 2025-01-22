#include <iostream>
using namespace std;

const int SIZE = 10;

// Create a generic stack class
template <class StackType>
class stack {
    StackType stck[SIZE]; // holds the stack
    int tos; // index of top-of-stack
public:
    stack() { tos = 0; } // initialize stack
    void push(StackType ob); // push object on stack
    StackType pop(); // pop object from stack
};

template <class StackType>
void stack<StackType>::push(StackType ob) {
    if (tos == SIZE) {
        cout << "Stack is full.\n";
        return;
    }
    stck[tos] = ob;
    tos++;
}

template <class StackType>
StackType stack<StackType>::pop() {
    if (tos == 0) {
        cout << "Stack is empty.\n";
        return 0; // return null on empty stack
    }
    tos--;
    return stck[tos];
}

int main() {
    stack<int> intStack;
    stack<double> doubleStack;

    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    doubleStack.push(1.1);
    doubleStack.push(2.2);
    doubleStack.push(3.3);

    cout << "Popped from intStack: " << intStack.pop() << endl;
    cout << "Popped from doubleStack: " << doubleStack.pop() << endl;
    return 0;
}