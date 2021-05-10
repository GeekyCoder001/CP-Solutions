//Maximum Product Cutting
#include<iostream>
using namespace std;

// DP Solution
// Time Complexity : O(n^2)
// Space Complexity : O(n) 
int maxProduct(int n){

    int dp[n+1]={};

    dp[0]=dp[1]=0;

    for(int i=2;i<=n;i++){ // i : Rod Length
        for(int j=1;j<i;j++){ // j : Checking where to cut
            // (i*(i-j)) : We have just a cut a jth position, no other cut
            // j*dp[i-j] : Cut at jth position, and keep rod of length j and for remaining length of (i-j) using optimization
            dp[i]=max(dp[i],max((i*(i-j)),j*dp[i-j]));
        }
    }

    return dp[n];
}

//Driver Code
int main(){
    int n;
    // n : length of rod
    cin>>n;
    int ans=maxProduct(n);
    cout<<ans<<"\n";

    return 0;
}