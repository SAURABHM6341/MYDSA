#include <bits/stdc++.h>
using namespace std;
template <typename T>
// Function to perform DFS and detect cycles
class graph{
    public:
    unordered_map<int, list<int>> adj;
    void addedge(int u,int v){
        adj[u].push_back(v);
    }
    void printadj(){
        for(auto i: adj){
            cout<<i.first<<"->";
            for(auto j: i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};
bool dfs(int node,unordered_map<int,bool> &visited,unordered_map<int,bool>&dfs_visited, graph <int>&g){
    visited[node] = true;
    dfs_visited[node] = true;
    for(auto i:g.adj[node]){
        if(!visited[i]){
            if(dfs(i,visited,dfs_visited,g)){
                return true;
            }
        }
        else if(dfs_visited[i]){
            return true;
        }
    }
    dfs_visited[node] = false;
    return false;

}
bool is_cycle_detect_DFS_directed(graph<int>&g, int n){
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfs_visited;
    for (auto& pair : g.adj) {
        int node = pair.first;
        if (!visited[node]) {
            if (dfs(node, visited, dfs_visited, g)) {
                return true;
            }
        }
    }
    return false;
}
int main(){
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
    if (is_cycle_detect_DFS_directed(g, n))
    {
        cout << "cycle present in given graph\n";
    }
    else
    {
        cout << "cycle not found\n";
    }
    return 0;
}