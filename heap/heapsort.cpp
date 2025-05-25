#include <bits/stdc++.h>
using namespace std;
class heap{
    public:
    int arr[100];
    int size = 0;
    void insert(int value){
        size++;
        int index = size;
        arr[index] = value;
        while (index>1)
        {
            int parent = index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index =parent;
            }
            else{
                return;
            }
        }
        
    }
    void print(){
        for (int i = 1; i <= size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        
    }
    void deletion(int&val){
        val = arr[1];
        arr[1] = arr[size];
        size--;
        int index= 1;
         while (index>1)
        {
            int parent = index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index =parent;
            }
            else{
                index--;
            }
        } //time complexity for this is O(n);
        //using O(logn) solution
        while (index<size)
        {
            int left = index*2;
            int right = 2*index+1;
            if(left<size&&arr[index]<arr[left]&&arr[left]>arr[right]){
                swap(arr[index],arr[left]);
                index = left;
            }
            else if(right<size&&arr[index]<arr[right]){
                swap(arr[index],arr[right]);
                index = right;
            }
            else{
                return;
            }
        }//complexity of this is O(logn);
        
    }
};
int main()
{
    heap h;
    cout<<"enter the number of nodes\n";
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cout<<"enter the value to be inserted\n";
        cin>>val;
        h.insert(val);
    }
    h.print();
    for (int i = 0; i < n; i++)
    {
        int val = 0;
        h.deletion(val);
        cout<<val<<" ";
    }
    //since it is a max heap hence sorting in descending for ascending visit construct min heap problem of cn;
    return 0;
};
