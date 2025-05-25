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
    void deletion(){
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
void heapify(int n,int arr[],int i){
int largest = i;
int left = 2*i;
int right = 2*i+1;
if(left<=n&&arr[largest]<arr[left]){
    largest = left;
}
if(right<=n&&arr[largest]<arr[right]){
    largest = right;
}
if(largest!=i){
    swap(arr[largest],arr[i]);
    heapify(n,arr,largest);
}

}
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
    h.deletion();
    h.print();
    //heapify code
    int arr[] = {-1,1,2,3,4,5,6};
    int j = 6;
    for (int i = j/2; i >0; i--)
    {
        heapify(j,arr,i);
    }
    for (int i = 1; i <=  j; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
};
