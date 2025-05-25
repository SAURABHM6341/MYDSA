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
int main()
{
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
    return 0;
}