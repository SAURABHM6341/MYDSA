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
void dfs(int node, int &parent, vector<int> &disc, vector<int> &low, vector<bool> &visited, vector<vector<int>> &result, int &timer, graph<int> &g)
{
    visited[node] = true;
    disc[node] = timer;
    low[node] = timer;
    timer++;
    int child = 0;
    for (auto neigh : g.adj[node])
    {        // if the neighbour is the parent, we skip it
        if (neigh == parent)
        {
            continue;
        }
        if (!visited[neigh])
        {
            dfs(neigh, node, disc, low, visited, result, timer, g);
            // update the low node
            low[node] = min(low[node], low[neigh]);
            // check for bridge
            if (low[neigh] > disc[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neigh);
                result.push_back(ans);
            }
        }
        else
        {
            // back edge case h
            low[node] = min(low[node], disc[neigh]);
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
    int timer = 0;
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    vector<bool> visited(n, false);
    vector<int> ap(n, 0);
    vector<vector<int>> result;
    int parent = -1;
    for(int i = 0;i<n;i++){
    if(!visited[i]){
        dfs(i, parent, disc, low, visited, result, timer, g);
    }
}

    return 0;
}

/*

#include <bits/stdc++.h>
void dfs(int node, int parent, int &timer,vector<int>&low,
vector<int>&disc,vector<bool>&visited, vector<vector<int>>&result,unordered_map<int,list<int>>&adj){
    visited[node] = true;
    disc[node] = timer;
    low[node] = timer;
    timer++;
    //now for all connected edges
    for(auto neigh:adj[node]){
        if(neigh==parent){
            continue;
        }
        if(!visited[neigh]){
            dfs(neigh,node,timer,low,disc,visited,result,adj);
            //update the low node
            low[node] = min(low[node], low[neigh]);
            //check for bridge
            if(low[neigh]>disc[node]){
                vector<int>ans;
                ans.push_back(node);
                ans.push_back(neigh);
                result.push_back(ans);
            }
        }
        else{
            //back edge case h
            low[node] = min(low[node],disc[neigh]);
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
unordered_map<int,list<int>>adj;
for(int i =0;i<e;i++){
    int u = edges[i][0];
    int v1 = edges[i][1];
    adj[u].push_back(v1);
    adj[v1].push_back(u);
}
int timer = 0;
vector<vector<int>>result;
vector<int>low(v,-1);
vector<int>disc(v,-1);
int parent = -1;
vector<bool>visited(v,false);
for(int i = 0;i<v;i++){
    if(!visited[i]){
        dfs(i,parent,timer,low,disc,visited,result,adj);
    }
}
return result;
}

*/