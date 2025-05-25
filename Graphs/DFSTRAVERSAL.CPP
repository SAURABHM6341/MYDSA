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
void dfs(int source, unordered_map<int, bool> &visited, graph<int> &g, vector<int> &ans)
{
    visited[source] = true;
    ans.push_back(source);
    for (auto i : g.adj[source])
    {
        if (!visited[i])
        {
            dfs(i, visited, g, ans);
        }
    }
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
    cout << "DFS Traversal: (source node is zero)\n" << endl;
    unordered_map<int, bool> visited;
    vector<int> ans;
   /* for (int i = 0; i < n; i++)
    {
        // for disconnected graph
        if (!visited[i])
        {
            dfs(i, visited, g, ans);
        }
    }
        */
    // for connected graph
    cout<<"Enter the source node: ";
    int source;
    cin >> source;
    dfs(source, visited, g, ans);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}