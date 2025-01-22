#include <iostream>
#include "StackUsingQueue.h"

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Queue q;
        int num;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            q.enqueue(num);
        }
        Stack stack;
        while (!q.isEmpty())
        {
            stack.push(q.dequeue());
        }
        Queue sortedQueue;
        stack.sortQueue();
        while (!stack.isEmpty())
        {
            sortedQueue.enqueue(stack.pop());
        }
        while (!sortedQueue.isEmpty())
        {
            cout << sortedQueue.dequeue() << " ";
        }
        cout << endl;
    }
    return 0;
}
