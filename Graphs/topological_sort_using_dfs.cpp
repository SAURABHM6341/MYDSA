#include <bits/stdc++.h>
using namespace std;
template <typename T>
class graph
{
public:
    unordered_map<int, list<int>> adj;
    void addedge(int u, int v)
    {
        adj[u].push_back(v);
    }
    void printadj()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << ",";
            }
            cout << endl;
        }
    }
};

void validtopologicalsort(graph<int> &g, int n, stack<int> &st, unordered_map<int, bool> &visited, int node)
{
    // call dfs
    visited[node] = true;
    for (auto i : g.adj[node])
    {
        if (!visited[i])
        {
            validtopologicalsort(g, n, st, visited, i);
        }
    }
    st.push(node);
    return;
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
        g.addedge(u, v);
    }
    cout << "Adjacency List:" << endl;
    g.printadj();
    cout << "Topological Sort using DFS:" << endl;
    unordered_map<int, bool> visited;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            // call dfs
            validtopologicalsort(g, n, st, visited, i);
        }
    }
    vector <int>ans;
    while(st.size() > 0)
    {
        // pop from stack
        ans.push_back(st.top());
        st.pop();
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;   
}