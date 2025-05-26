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
    void printadjlist()
    {
        for (auto it : adj)
        {
            cout << it.first << "->";
            for (auto i : it.second)
            {
                cout << i << ",";
            }
            cout << endl;
        }
    }
};
int main()
{
    int n;
    cout << "enter the number of nodes\n";
    cin >> n;
    int m;
    cout << "enter the number of edges\n";
    cin >> m;
    graph<int> g;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "enter the edge\n";
        cin >> u >> v;
        g.addedge(u, v, 0); // zero ka mtlb undirected graph h agr '1' kr de to direction aa jayegi "u" se "v" ki taraf
    }
    g.printadjlist();
    // BFS for shortest path in unweighted undirected graph
    int source;
    cout << "Enter the source node: ";
    cin >> source;
    int destination;
    cout << "Enter the destination node: ";
    cin >> destination;
    queue<int> q;
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    q.push(source);
    visited[source] = true;
    parent[source] = -1; // Source has no parent
    bool found = false; // Flag to check if destination is found
    while (!q.empty()&& !found)
    {
        int node = q.front();
        q.pop();
        for (auto neighbour : g.adj[node])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true; // Mark neighbour as visited
                parent[neighbour] = node;  // Set parent of neighbour
                q.push(neighbour);         // Add neighbour to the queue
                if (neighbour == destination)
                {
                    // Destination found, break out of the loop
                    found = true;
                    break;
                }
            }
        }
        if (found)
            break; // Exit the while loop if destination is found
    }
    for (auto it : parent)
    {
        cout << it.first << " -> " << it.second << endl; // Print parent-child relationships
    }
    // To find the path from source to destination
    vector<int> path;
    int current = destination;
    while (current != -1)
    {
        path.push_back(current);
        current = parent[current]; // Move to the parent
    }
    reverse(path.begin(), path.end()); // Reverse the path to get it from source to destination
    cout << "Shortest path from " << source << " to " << destination << ": ";
    for (int node : path)
    {
        cout << node << " ";
    }
}