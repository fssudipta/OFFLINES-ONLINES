#include <iostream>
#include <list>
#include <stack>

using namespace std;

class DFS
{
private:
    list<int> adj[1000];
    bool visited[1000];
    int n, m;

public:
    void initialize(int nodes, int edges)
    {
        n = nodes;
        m = edges;
        for (int i = 1; i <= n; ++i)
        {
            adj[i].clear();
        }
        fill(visited, visited + n + 1, false);
    }

    void addEdge(int a, int b)
    {
        // a and b two ends of an edge
        adj[a].push_back(b);
        adj[b].push_back(a);
        //adding b to the adjacency list of a and vice versa.
        //mainly adj is an array of lists, where adj[i] represents the
        //list of adjacent nodes for node[i]. the fn push_back(b) appends
        //b to the adj list of node a. this means that node b is now a neighbor
        //of node a
    }

    void dfs(int start, int &count, int component[]) 
    {
        //start: starting node for DFS
        //count: counter that keeps track of the number of connected components
        //component[]: array storing the nodes of each connected component
        stack<int> s;
        s.push(start);
        visited[start] = true; //starting node visit korlam

        while (!s.empty())
        {
            int u = s.top();
            s.pop();
            for (auto v : adj[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    s.push(v);
                    //explored the adjacent nodes, marked them visited, 
                    //and pushed them to the stack
                }
            }
        }
        component[count++] = start;
        //added the starting node to the component array
    }

    void findConnectedComponents(int &count, int component[])
    {
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                //calling dfs fn for each unvisited node
                dfs(i, count, component);
            }
        }
    }
};
