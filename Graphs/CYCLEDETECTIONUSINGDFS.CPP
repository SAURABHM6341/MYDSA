#include <bits/stdc++.h>
using namespace std;
template <typename T>
class graph{
    public:
    unordered_map<T,list<T>> adj;
    void addedge(T u, T v, int direction){
        adj[u].push_back(v);
        if(direction == 0 ){
            adj[v].push_back(u);
        }
    }
    void printadj(){
        for(auto it:adj){
            cout << it.first <<" --> ";
            for(auto i:it.second){
                cout<<i<< ", "; 
            }
            cout<<endl;
        }
    }
};
bool dfs(graph<int>&g, int n, int source, unordered_map<int,bool> &visited, int parent){
    visited[source] = true;
    for(auto i:g.adj[source]){
        if(!visited[i]){
            if(dfs(g, n, i, visited, source)){
                return true;
            }
        }
        else if(i != parent){
            return true;
        }
    }
    return false;

}
bool is_cycle_detect_DFS(graph<int>g, int n){
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(g, n, i, visited, -1))
            {
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
        g.addedge(u, v, 0);
    }
    cout << "Adjacency List:" << endl;
    g.printadj();
    if (is_cycle_detect_DFS(g, n))
    {
        cout << "cycle present in given graph\n";
    }
    else
    {
        cout << "cycle not found\n";
    }
    return 0;
}