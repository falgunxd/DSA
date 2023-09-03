#include <stdio.h>
using namespace std;
class graphs
{
public:
    void addEdge(vector<int> adj[], int u, int v)
    {
        adj[u].pushback(v);
    }
    void printAdjacencyList(vector<int> adj[], int V)
    {
        cout << "Vertices Adjacencies" for (int i = 0; i < V; i++)
        {
            cout << adj[i] << "\t";
            for (int x : adj[i])
                cout << x << " ";
            cout << endl;
        }
    }
    void DFSRec(vector<int> adj[], bool visited[], int i)
    {
        visited[i] = 1;
        cout << i << " ";
        for (int x : adj[i])
        {
            if (visited[x] == 0)
                DFSRec(adj, visited, x);
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
    void BFSRec(vector<int> adj[], bool visited[], queue<int> q, int i)
    {
        visited[i] = 1;
        cout << i << " ";
        for (int x : adj[i])
        {
            q.push(x);
        }
        q.pop();
    }
    void BFS(vector<int> adj[], int V)
    {
        bool visited[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = 0;
        }
        queue<int> q;
        while (!q.empty())
        {
            for (int i = 0; i < V; i++)
            {
                if (visited[i] == 0)
                {
                    BFSRec(adj, visited, q, i);
                }
            }
        }
    }
    void DFSTopologicalSort(vector<int> adj[], stack<int> s, bool visited[], int i)
    {
        visited[i] = 1;
        for (int x : adj[i])
        {
            if (visited[x] == 0)
                DFSTopologicalSort(adj, s, visited, x);
        }
        s.push(i);
    }
    void topologicalSort(vector<int> adj[], int V)
    {
        bool visited[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = 0;
        }
        stack<int> s;
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                DFSTopologicalSort(adj, s, visited, i);
            }
        }
    }
    
} int main()
{
}