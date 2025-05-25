#include <bits/stdc++.h>
using namespace std;
template <typename T>// isko likhne ke baad int ya string likhne ki zarurat nahi mtlb data structure ka type btane ki jarurat nhi h graph class ke andr define krne ki, phir ksii bhi function ke andr agr int ka graph chahiye to bas graph<int> g; likhna hoga aur int ka graph ban jayega aur jha string ka graph chahiye to string ka bna lena 
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
//in this traversal we need two data structures one is queue and other is unordered map for tracking the visited nodes
/*this is 5 step process
1. push the source node in the queue and take as front node
2. dequeue from the queue
3. marks the node as visited
4. print that node
5. push all neighbours of that node in the queue
6. repeat the process until queue is empty
*/
int main(){
    vector<int> answer;
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
    g.printadjlist();
    queue<int> q;
    unordered_map<int, bool> visited;
    int front;
    cout<<"enter the source node\n";
    cin>>front;
    q.push(front);
    visited[front] = true;
    cout<<"TRAVERSAL ORDER\n";
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout<<node<<endl;
        for(auto it:g.adj[node]){
            if (!visited[it])
            {
                q.push(it);
                visited[it] = true;
            }
        }
    }
    
    return 0;
}

/*
//foor disconnected graph one more loop is required ensured that every vertex is visited
vector<int> bfsTraversal(int n, vector<vector<int>> &adj) {
    vector<int> ans;
    vector<bool> visited(n, false);
    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                ans.push_back(node);

                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
        }
    }

    return ans;
}

*/