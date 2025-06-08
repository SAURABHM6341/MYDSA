#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter the value of n to find the nth Fibonacci number (zeroth fibonacci exist): ";
    cin>>n;
    vector<int>dp(n+1,-1);
    dp[0] = 0; // Base case: F(0) = 0 
    dp[1] = 1; // Base case: F(1) = 1
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2]; // Bottom-up approach
    }
    cout<<"The "<<n<<"th Fibonacci number is: "<<dp[n]<<endl;
    return 0;
}