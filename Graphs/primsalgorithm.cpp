#include <bits/stdc++.h>
using namespace std;
// Function to find the minimum spanning tree using Prim's algorithm
/*
what is MST?
agr kisi graph ke sabhi vertices ko kisi tree form me bna de such that ki saare vertices ek dusre se reachable ho
and the total weight of the edges in the tree is minimized, then that tree is called a minimum spanning tree (MST).
now steps for prims alogorithm:
we need three data structures:
1. mst with bool array that keeps track of the vertices that are included in the MST
2. a priority queue to store the edges of the graph and to provide a minimum edge at each step
3. a parent array to keep track of the parent of each vertex in the MST
now how to implement this algorithm:
1. start with any vertex and add it to the MST
2. add all the edges of the vertex to the priority queue
3. while the priority queue is not empty:
   a. pop the minimum edge from the priority queue
   b. if the vertex at the end of the edge is not in the MST, add it to the MST and update the parent array and mark as true that it is included in the MST
   c. add all the edges of the new vertex to the priority queue 
   d. repeat step 3 until all vertices are included in the MST and also ifvertex is included in the MST then we will not add its edges to the priority queue
*/
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
    vector<int> parent(n, -1);
    vector<bool> mst(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int>distance(n,INT_MAX);
    int source;
    cout << "enter source\n";
    cin >> source;
    pq.push({0, source});
    distance[source] = 0;
    while(!pq.empty()){
        int node = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        if(mst[node]) continue;
        mst[node] = true;
        list<pair<int,int>>neighbours = g.adj[node];
        for(auto i:neighbours){
            if(mst[i.first]!=true&&distance[i.first]>i.second){
            parent[i.first] = node;
            pq.push({i.second,i.first});
            distance[i.first] = i.second; 
            }
        }
    }
    int totalWeight;
    for (int v = 0; v < n; v++) {
    if (v == source) {
        cout << v << " is the source node\n";
    } else if (parent[v] != -1) {
        cout << parent[v] << " --> " << v << ", weight = " << distance[v] << "\n";
        totalWeight += distance[v];
    }
}
    return 0;
}
/*
0 3 6
0 1 2
3 1 8
1 4 5
1 3 2
4 2 7
*/