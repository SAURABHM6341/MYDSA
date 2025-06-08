#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter the value of n to find the nth Fibonacci number (zeroth fibonacci exist): ";
    cin>>n;
    int prev1 = 0;
    int prev2 = 1;
    if(n == 0){
        cout<<"The "<<n<<"th Fibonacci number is: "<<prev1<<endl;
        return 0;
    }
    if(n == 1){
        cout<<"The "<<n<<"th Fibonacci number is: "<<prev2<<endl;
        return 0;
    }
    int curr = 0;
    for(int i = 2;i<=n;i++){
        curr = prev1+prev2;
        prev1 = prev2;
        prev2 = curr;
    }
    cout<<"The "<<n<<"th Fibonacci number is: "<<curr<<endl;
    cout<<"Space Optimised Fibonacci number calculation completed."<<endl;
    return 0;
}