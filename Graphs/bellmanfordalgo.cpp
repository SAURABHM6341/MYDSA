#include <bits/stdc++.h>
using namespace std;
template <typename T>
/*

--> bellman algo is used to find shortest path when there is an negative weight edge is present 
--> it is also used to find negative cycle in a graph 
--> dijkstra algo is not applicable when there is an negative weight is present in graph 
--> for bellman ford algo to apply 1. graph should not contain and negative cycle and usually applied in directed graoh 
--> undirected graph can easily change to directed by making two edges hence we can apply it on both 


*/
class graph{
    public:
    unordered_map<int,list<pair<int,int>>>adj;
    void addedge(T u, T v, bool direction)
    {
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }
    void printadjlist(){
        for (auto it:adj){
            cout<<it.first<<"->";
            for (auto i:it.second){
                cout<<i<<",";
            }
            cout<<endl;
        }
    }
};
/*

Q. How bellman works?
ANS : 

*/
int main(){
    int n;
    cout<<"enter the number of nodes\n";
    cin>>n;
    int m;
    cout<<"enter the number of edges\n";
    cin>>m;
    graph<int> g;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "enter the edge\n";
        cin >> u >> v;
        g.addedge(u, v, 0); // zero ka mtlb undirected graph h agr '1' kr de to direction aa jayegi "u" se "v" ki taraf
    }
    int src;
    cout<<"enter the source node \n";
    cin>>src;
    g.printadjlist();
    vector<int>distance(n+1,INT_MAX);
    distance[src] = 0;
    vector<vector<int>>edges(n,vector<int>(3));
    for(int i = 0;i<n;i++){
    for(auto it:g.adj[i]){
        edges[i][0] = i;
        edges[i][1] = it.first;
        edges[i][2] = it.second;
    }
}
bool nc = false;
    for(int j = 1;j<=n;j++){
        if(j!=n){
            for(int i = 0;i<m;i++){
                int u = edges[i][0];
                int v = edges[i][1];
                int w = edges[i][2];
                if(distance[u]!=INT_MAX && distance[u] + w < distance[v]){
                    distance[v] = distance[u]+w;
                }
            }
        }
        else{
            vector<int>dist2 = distance;
            for(int i = 0;i<m;i++){
                int u = edges[i][0];
                int v = edges[i][1];
                int w = edges[i][2];
                if(distance[u]!=1e8&&distance[u]+w<distance[v]){
                    nc = true;
                }
            }
        }
        
    }
    // just print the distance array i am leaving it  
    if(nc){
        cout<<"negative cycle detected\n";
    }
    return 0;
}