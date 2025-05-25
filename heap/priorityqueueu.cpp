#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int>pq;
    //it is by default a maxheap;
    pq.push(1);    
    pq.push(2);    
    pq.push(3);    
    pq.push(4);    
    pq.push(5);    
    pq.push(6);    
    cout<<pq.top();
    pq.pop();
    cout<<" "<<pq.top();
    //now minheap;
    priority_queue<int,vector<int>,greater<int> > minheap;
    minheap.push(6);
    minheap.push(5);
    minheap.push(4);
    minheap.push(3);
    minheap.push(2);
    minheap.push(1);
    cout<<" "<<minheap.top();
    return 0;
};
