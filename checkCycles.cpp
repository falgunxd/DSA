#include <bits/stdc++.h>
using namespace std;
void DFSRec(vector<int> adj[], bool visited[], int s)
{
    visited[s] = 1;
    cout << s;
    for (auto x : adj[s])
    {
        if (visited[x] == 0)
        {
            DFSRec[adj, visited, x];
        }
    }
}
void DFS(vector<int> adj[], int V)
{
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            DFSRec(adj, visited, i);
        }
    }
}
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void traversal(vector<int> adj[], int V)
{
    for (int i = 0; i < V; i++)
    {
        cout << i << "    ";
        for (auto x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}
bool recCheckCyclesDFS(vector<int> adj[], bool visited[], int s, int parent)
{
    visited[s] = 1;
    for (auto x : adj[s])
    {
        if (visited[x] == 0)
        {
            if (recCheckCyclesDFS(adj, visited, x, s) == 1)
            {
                return true;
            }
        }
        else if (x != parent)
            return true;
    }
    return false;
}
bool CheckCyclesDFS(vector<int> adj[], int V)
{
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            if (recCheckCyclesDFS(adj, visited, i, -1) == 1)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);
    // addEdge(adj,);
    // addEdge(adj,);
    // addEdge(adj,);
    // addEdge(adj,);
    // addEdge(adj,);
    traversal(adj, V);
    DFS(adj, V);
}