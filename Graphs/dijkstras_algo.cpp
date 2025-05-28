#include <bits/stdc++.h>
using namespace std;
template <typename T>
class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;
    void addedge(int u, int v, int w)
    {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    void printadj()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j.first << ", weight = " << j.second << "\n";
            }
            cout << endl;
        }
    }
};
/*steps:
1. make adjacency list
2. make distace of source  =  0
3. push it into set and then take the top of set and update the distance array just like shotest path using DAG code
4. check for all neighbours if neighbour condition satisfied then update the distance array and push into set
5. repeat step 3 until death
*/
int main()
{
    graph<int> g;
    cout << "enter the number of nodes\n";
    int n;
    cin >> n;
    cout << "Enter the number of edges: ";
    int e;
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        cout << "Enter the edges (u v): ";
        int u, v;
        cin >> u >> v;
        cout << "enter weight : ";
        int w;
        cin >> w;
        g.addedge(u, v, w);
    }
    cout << "Adjacency List:" << endl;
    g.printadj();
    cout << "Topological Sort using DFS:" << endl;
    unordered_map<int, bool> visited;
    set<pair<int, int>> s;
    int source;
    cout << "enter source\n";
    cin >> source;
    vector<int> distance(n, INT_MAX);
    distance[source] = 0;
    s.insert({0, source});
    while(!s.empty()){
        int node = s.begin()->second;
        int nodeweight = s.begin()->first;
        s.erase(s.begin());
        for(auto i: g.adj[node]){
            int neighbour = i.first;
            int edgedistance = i.second;
            if(nodeweight + edgedistance < distance[neighbour]){
                int olddistance = distance[neighbour];
                distance[neighbour] = nodeweight + edgedistance;
                if(s.find({olddistance, neighbour}) != s.end()){
                    s.erase(s.find({olddistance, neighbour}));
                }
                s.insert({distance[neighbour], neighbour});
            }
        }
    }
    cout<<"shortest distance of all node from "<<source<<" is as follows\n";
    for(auto i:distance){
        cout<<i<<" ";
    }
    return 0;
}