#include <bits/stdc++.h>
using namespace std;
void dfs(vector<bool>&visited,int node,stack<int>&s,unordered_map<int,list<int>>&adj){
	visited[node] = true;
	for(auto neigh:adj[node]){
		if(!visited[neigh])
		{
			dfs(visited,neigh,s,adj);
		}
	}
	s.push(node);
}
void dfs2(vector<bool>&visited,int node,unordered_map<int,list<int>>&adj){
	visited[node] = true;
	for(auto neigh:adj[node]){
		if(!visited[neigh])
		{
			dfs2(visited,neigh,adj);
		}
	}
}
int main()
{   
    cout << "enter the number of nodes\n";
    int n;
    cin >> n;
    cout << "Enter the number of edges: ";
    int e;
    cin >> e;
    cout << "Enter the edges (u v): ";
    vector<vector<int>>edges(e,vector<int>(2));
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[i][0] = u;
        edges[i][1] = v;
    }
	unordered_map<int,list<int>>adj;
	for(int i = 0;i<e;i++){
		int f = edges[i][0];
		int s = edges[i][1];
		adj[f].push_back(s);
	}
	vector<bool>visited(n,false);
	stack<int>s;
	for(int i = 0;i<n;i++){
		if(!visited[i]){
			dfs(visited,i,s,adj);
		}
	}
	for(int i = 0;i<n;i++){
		visited[i] = false;
	}
	adj.clear();
	for(int i = 0;i<e;i++){
		int f = edges[i][0];
		int s = edges[i][1];
		adj[s].push_back(f);
	}
	int count = 0;
	while(!s.empty()){
		int node = s.top();
		s.pop();
		if(!visited[node]){
			dfs2(visited,node,adj);
			count++;
        }
	}
    cout<<"Number of Strongly connected Components is "<<count<<endl;
	return 0;
}