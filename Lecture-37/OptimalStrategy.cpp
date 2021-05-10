//Optimal Strategy for Game

#include<iostream>
using namespace std;

// DP Solution
// Time Complexity : O(n^2)
//Space Complexity : O(n^2) 
long long maximumAmount(int arr[], int n) {

    //dp[i][j] represents solution for array starting from  index i and ending at j
    long long dp[n][n]={};

    for(int i=0;i<n;i++){
        dp[i][i]=arr[i];
        if(i!=(n-1)) dp[i][i+1]=max(arr[i],arr[i+1]);
    }

    for(int d=2;d<n;d++){ // Diagonal of the matrix
        for(int i=0;i<(n-d);i++){ // Row Number of matrix or starting index for sub array solution
            int j=i+d; // Coloumn Number of matrix or ending index for sub array solution

            // We had to take max out of two ways of picking at both the ends for Player
            // Now for each case we have two situations for opponent, but opponent will give minimum out of it to Player in its next turn
            dp[i][j]=max(arr[i]+min(dp[i+2][j],dp[i+1][j-1]),arr[j]+min(dp[i][j-2],dp[i+1][j-1]));
        }
    }

    // Answer will be dp[0][n-1] as we need solution for array starting from 0 and ending at (n-1)
    return dp[0][n-1];
}

//Driver Code
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maximumAmount(arr,n)<<"\n";
    return 0;
}