#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool isPalindrome(queue<char> &q, int n)
{
    stack<char> s;
    for (int i = 0; i < n; i++)
    {
        s.push(q.front());
        q.pop();
    }
    for (int i = 0; i < n; i++)
    {
        if (q.front() != s.top())
            return false;
        s.pop();
        q.pop();
    }

    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        queue<char> q;
        char ch;
        for (int i = 0; i < n; i++)
        {
            cin >> ch;
            q.push(ch);
        }
        if (isPalindrome(q, n))
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
