#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;
public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; ++i)
        {
            parent[i] = i;
        }
    }
    int find(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u != root_v)
        {
            if (rank[root_u] < rank[root_v])
            {
                parent[root_u] = root_v;
            }
            else if (rank[root_u] > rank[root_v])
            {
                parent[root_v] = root_u;
            }
            else
            {
                parent[root_v] = root_u;
                rank[root_u]++;
            }
        }
    }
    void unionBySize(int u, int v)
    {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u != root_v)
        {
            if (size[root_u] < size[root_v])
            {
                parent[root_u] = root_v;
                size[root_v] += size[root_u];
            }
            else
            {
                parent[root_v] = root_u;
                size[root_u] += size[root_v];
            }
        }
    }
};

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> &edges)
    {
        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        int mstWeight = 0;
        for (const auto &edge : edges)
        {
            int wt = edge[0];
            int u = edge[1];
            int v = edge[2];
            if (ds.find(u) != ds.find(v))
            {
                mstWeight += wt;
                ds.unionBySize(u, v);
            }
        }
        return mstWeight;
    }
};

int main()
{
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    if (!inputFile)
    {
        cerr << "Error opening input file!" << endl;
        return 1;
    }
    if (!outputFile)
    {
        cerr << "Error opening output file!" << endl;
        return 1;
    }
    int V, E;
    inputFile >> V >> E;
    vector<vector<int>> edges;
    for (int i = 0; i < E; ++i)
    {
        int wt, u, v;
        inputFile >> wt >> u >> v;
        edges.push_back({wt, u, v});
    }
    Solution obj;
    int mst = obj.spanningTree(V, edges);
    outputFile << mst << endl;
    inputFile.close();
    outputFile.close();
    return 0;
}