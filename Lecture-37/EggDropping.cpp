//Egg dropping Puzzle Solution using DP
#include<iostream>
#include<limits.h>
using namespace std;

//DP Solution
//Time Complexity : O(n*k^2)
//Space Comlexity : O(n*k)
int eggDrop1(int n, int k){
    //dp[i][j] shows attemps with i eggs and k floors
    int dp[n+1][k+1];

    //Initial values
    for(int i=0;i<=n;i++){
        dp[i][0]=0;//As with 0 floors, we have 0 ways
    }
    for(int i=0;i<=k;i++){
        dp[0][i]=0;//As with 0 eggs, we have 0 ways
        dp[1][i]=i;//As with 1 eggs, in worst case, we have to try with all floors one by one from down to top
    }

    //Further creating bottom-up Solution
    for(int i=2;i<=n;i++){ // i : Number of eggs
        for(int j=1;j<=k;j++){ // j : Number of floors
            dp[i][j]=INT_MAX;
            for(int m=1;m<=j;m++){ // m : trying with all floors to find floor with minimum tests in worst case
                // dp[i-1][m-1] : If egg broke at mth floor
                // dp[i][j-m] : If egg survive at mth floor
                // Take max out of above two(worst case)
                // 1 : for mth floor
                // Take minimum out of al floors
                dp[i][j]=min(dp[i][j],(1+max(dp[i-1][m-1],dp[i][j-m])));
            }
        }
    }

    //Answer is dp[n][k] as we have to find attempts with n eggs and k floors
    return dp[n][k];
}


//If u understand above solution, then this is just space optimized version of it
//instead of using dp[n][k] space, we will use only dp[2][k] becoz we need only last second row to compute last row
//Time Complexity : O(n*k^2)
//Space Comlexity : O(k)
int eggDrop2(int n, int k){
    int dp[2][k+1];
    for(int i=0;i<=k;i++){
        dp[0][i]=i;
    }
    for(int i=2;i<=n;i++){
        dp[1][0]=0;
        for(int j=1;j<=k;j++){
            dp[1][j]=INT_MAX;
            for(int m=1;m<=j;m++){
                dp[1][j]=min(dp[1][j],(1+max(dp[0][m-1],dp[1][j-m])));
            }
        }
        for(int i=0;i<=k;i++){
            dp[0][i]=dp[1][i];
        }
    }
    return dp[0][k];
}

//Driver Code
int main(){

    // n -> number of eggs
    // k -> number of floors
    int n,k;
    cin>>n>>k;

    // int ans=eggDrop1(n,k);
    int ans=eggDrop2(n,k);

    cout<<"Minimum Number of Trials = "<<ans<<"\n";
    
    return 0;
}