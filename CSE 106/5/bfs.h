#include <iostream>
#include <queue>

using namespace std;

class BFS
{
private:
    int **adj;
    bool *visit;
    int n, m;

public:
    BFS(int nodes, int edges)
    {
        n = nodes;
        m = edges;
        adj = new int *[n]; //initialize a square matrix
        for (int i = 0; i < n; i++)
        {
            adj[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                adj[i][j] = 0;
            }
        }
        visit = new bool[n];
        for (int i = 0; i < n; i++)
        {
            visit[i] = false; //initialize visited nodes 
        }
    }

    ~BFS()
    {
        for (int i = 0; i < n; i++)
        {
            delete[] adj[i]; //delete each row
        }
        delete[] adj; //delete the pointer to the matrix
        delete[] visit; //delete!
    }

    void addEdge(int a, int b)
    {
        //two ends of the edge ab/ba
        // if(a<=n && b<=n)
        adj[a - 1][b - 1] = 1;
        adj[b - 1][a - 1] = 1;
        //indicates bothway
    }

    void bfs(int start, int &count, int component[])
    {
        //start: 0-based index
        //count: a ref to keep the track of the number of the connected components
        //component: an array that stores the nodes of each connected comp.
        queue<int> q;
        q.push(start);
        visit[start] = true;

        //almost same
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v = 0; v < n; v++)
            {
                //is there an edge between u and v?
                if (adj[u][v] == 1 && !visit[v]) //node v is an unvisited neighbor of node u
                {
                    visit[v] = true;
                    q.push(v);
                    //adding v to the q so that i can find v's neighbors as well
                }
            }
        }
        component[count++] = start;
    }

    void findConnectedComponents(int &count, int component[])
    {
        for (int i = 0; i < n; i++)
        {
            if (!visit[i])
            {
                bfs(i, count, component);
            }
        }
    }
};