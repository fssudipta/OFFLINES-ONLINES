#include <iostream>
#include <queue>
using namespace std;

// Print the queue
void print_queue(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " "; // Print only the front
        q.pop();
    }
    cout << '\n';
}

int main()
{
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);

    cout << "The first queue is : ";
    print_queue(q1);

    return 0;
}
