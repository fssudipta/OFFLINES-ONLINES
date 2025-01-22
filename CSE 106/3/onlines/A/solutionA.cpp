#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void solution(queue<int> &q, int n)
{
    queue<int> arekta;
    int half = n / 2;
    for (int i = 0; i < half; i++)
    {
        arekta.push(q.front());
        q.pop();
    }
    for (int i = 0; i < half; i++)
    {
        q.push(arekta.front());
        arekta.pop();
        q.push(q.front());
        q.pop();
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        queue<int> q;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            q.push(arr[i]);
        }
        solution(q, n);
        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }
    return 0;
}