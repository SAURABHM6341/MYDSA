// tarjan's articulation point algorithm

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
void dfs(int node,int &parent,vector<int>&disc, vector <int>&low, vector<bool>&visited, vector<int>&ap,int &timer, graph<int>&g){
    visited[node] = true;
    disc[node] = timer;
    low[node] = timer;
    timer++;
    int child = 0;
    for(auto nei:g.adj[node]){
        if(nei ==parent){
            continue;
        }
        if(!visited[nei]){
            dfs(nei,node,disc,low,visited,ap,timer,g);
            low[node] = min(low[node], low[nei]);
            if(low[nei] >= disc[node] && parent != -1){
                ap[node] = true; // node is an articulation point
            }
            child++;
        }
        else{
            low[node] = min(low[node], disc[nei]);
        }

    }
    if(parent== -1 && child >1){
        ap[node] = true; // root node is an articulation point if it has more than one child
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
    int timer = 0;
    vector<int>disc(n,-1);
    vector<int>low(n,-1);
    vector<bool>visited(n,false);
    vector<int>ap(n,0);
    int parent = -1;
    for (int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i,parent,disc,low,visited,ap,timer,g);
        }
    }
    cout << "Articulation Points in the graph are: ";
    for(int it = 0; it < n; it++){
        if(ap[it] != 0){
            cout << it << " "; 
        }
       return 0;
}