#include "bfs.h"
#include "dfs.h"
#include <iostream>
using namespace std;

void solveWithBFS()
{
    int n, m;
    cin >> n >> m;
    BFS bfs(n, m);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        bfs.addEdge(a, b);
    }

    int count = 0;
    int component[1000];
    bfs.findConnectedComponents(count, component);

    cout << count - 1 << endl;
    for (int i = 0; i < count-1; ++i)
    {
        cout << component[i]+1 << " " << component[i+1]+1 << endl;
    }
}
void solveWithDFS()
{
    int n, m;
    cin >> n >> m;
    DFS dfs;
    dfs.initialize(n, m);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        dfs.addEdge(a, b);
    }

    int count = 0;
    int component[1000];
    dfs.findConnectedComponents(count, component);

    cout << count - 1 << endl;
    for (int i = 1; i < count; ++i)
    {
        cout << component[i - 1] << " " << component[i] << endl;
    }
}

int main()
{
    solveWithBFS();
    //solveWithDFS();
    return 0;
}
