

//           ============USING BFS============


#include <bits/stdc++.h>
using namespace std;
template <typename T>
class graph
{
public:
    unordered_map<T, list<T>> adj;
    void addedge(T u, T v, bool direction)
    {
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }
    void printadj()
    {
        for (auto i : adj)
        {
            cout << i.first << "-->";
            for (auto j : i.second)
            {
                cout << j << ",";
            }
            cout << endl;
        }
    }
};
bool bfs(graph<int> &g, int n, int source, unordered_map<int, bool> &visited)
{
    queue<int> q;
    q.push(source);
    visited[source] = true;
    unordered_map<int, int> parent;
    parent[source] = -1;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        // cout << front << " ";
        for (auto i : g.adj[front])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
                parent[i] = front;
            }
            else if (i != parent[front])
            {
                cout << "cycle detected\n";
                return true;
            }
        }
    }
    return false;
}
bool is_cycle_detect_BFS(graph<int> &g, int n)
{
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (bfs(g, n, i, visited))
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    graph<int> g;
    cout << "enter the number of nodes\n";
    int n;
    cin >> n;
    cout << "Enter the number of edges: ";
    int e;
    cin >> e;
    cout << "Enter the edges (u v): ";
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addedge(u, v, 0);
    }
    cout << "Adjacency List:" << endl;
    g.printadj();
    if (is_cycle_detect_BFS(g, n))
    {
        cout << "cycle present in given graph\n";
    }
    else
    {
        cout << "cycle not found\n";
    }
    return 0;
}