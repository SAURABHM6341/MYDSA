#include <bits/stdc++.h>
using namespace std;
template <typename T>
/*
steps:
1. find toposort stack
2. ek distance array bnao jisme intially infinite distanc kro
3. source ki distance ko zero kro
4. dist. array me ek ek krke saare elements me unka weight lo + neighbour tk pahuchne ka edge weight add kro
5. agr sum of weight smaller than previous distance feeded in dist. array then update kro 
6. ye kaam hr ek neighbour ke saath kro aur fir node ko stack se hta do
7. aur jab kisi node se raaste na bche ho ruk jao
8. distance array hi tumhari sorce se shortest distance ki aaray h 
*/
class graph
{
public:
    unordered_map<int, list<pair<int,int>>> adj;
    void addedge(int u, int v,int w)
    {
        adj[u].push_back({v,w});
    }
    void printadj()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j.first << ", weight = "<<j.second<<"\n";
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
        if (!visited[i.first])
        {
            validtopologicalsort(g, n, st, visited, i.first);
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
        cout<<"enter weight : ";
        int w;
        cin>>w;
        g.addedge(u, v, w);
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
    int source;
    cout<<"enter source\n";
    cin>>source;
    vector<int>distance(n+1,INT_MAX);
    distance[source] = 0;
    while(!st.empty()){
        list<pair <int,int>> node = g.adj[st.top()];
        for(auto i:node){
            if(i.second + distance[st.top()]<distance[i.first]){
                distance[i.first] = i.second + distance[st.top()];
            }
        }
        st.pop();
    }
    cout<<"shortest distance from "<<source<<"is \n";
    for(auto i:distance){
        cout<<i<<", ";
    }
    return 0;   
}