#include <bits/stdc++.h>
using namespace std;
// Kahn's Algorithm for Topological Sorting using BFS
template <typename T>
/*
steps:
1. Calculate in-degree of each node.
2. Push all nodes with in-degree 0 into a queue.
3. While the queue is not empty:
   a. Pop a node from the queue.
   b. Add it to the topological order.
   c. For each of its neighbors, reduce their in-degree by 1.
   d. If any neighbor's in-degree becomes 0, push it into the queue.
4. If the topological order contains all nodes, return it; otherwise, return an empty vector (indicating a cycle).
*/
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
        g.addedge(u, v, 1); // zero ka mtlb undirected graph h agr '1' kr de to direction aa jayegi "u" se "v" ki taraf
    }
    g.printadjlist();
    // Kahn's Algorithm for Topological Sort
    unordered_map<int, int> inDegree;
    for(auto i :g.adj){
        for(auto j:i.second){
            inDegree[j]++;
        }
    }
    queue<int>q;
    // indegree zero walo ko push kro
    for(auto i:g.adj){
        if(inDegree[i.first]==0){
            q.push(i.first);
        }
    }
    //ab bfs kro
    vector<int>ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for(auto i:g.adj[front]){
            inDegree[i]--;
            if(inDegree[i]==0){
                q.push(i);
            }
        }
    }
    int count = ans.size();
    if(count==n){
        cout<<"cycle is not present\n";
    }
    else{
        cout<<"cycle is present\n";
    }
    return 0;

}