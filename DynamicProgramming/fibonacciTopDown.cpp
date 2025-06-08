#include <bits/stdc++.h>
using namespace std;
// Function to calculate the nth Fibonacci number using dynamic programming
int fibo(vector<int>&dp,int n){
    if(n==0||n==1){
        return dp[n]; // Base case: F(0) = 0, F(1) = 1
        /*  return n;  // both will be okay */
    }
    if(dp[n] != -1){
        return dp[n];
    } else {
        dp[n] = fibo(dp, n-1) + fibo(dp, n-2); // Recursive case
        return dp[n];
    }
}
int main(){
    int n;
    cout<<"enter the value of n to find the nth Fibonacci number (zeroth fibonacci exist): ";
    cin>>n;
    vector<int>dp(n+1,-1);
    dp[0] = 0; // Base case: F(0) = 0 we can remove these two lines but after that use return n in fibo function 
    dp[1] = 1; // Base case: F(1) = 1
    cout<<"The "<<n<<"th Fibonacci number is: "<<fibo(dp, n)<<endl;
    return 0;
}