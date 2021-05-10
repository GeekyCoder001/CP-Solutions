#include <bits/stdc++.h>
using namespace std;

//Solution 1 via DP
long long noOfWays1(int m, int n, int x) {
    long long dp[n+1][x+1];

    //Initailizing 2d array with 0
    for(int i=0;i<=n;i++){
        for(int j=0;j<=x;j++){
            dp[i][j]=0;
        }
    }

    //Making first row
    for(int i=1;i<=x && i<=m;i++){
        dp[1][i]=1;
    }

    //Further
    for(int i=2;i<=n;i++){//i : No. of dice
        for(int j=i;j<=m*i && j<=x;j++){//j : Sum of dices
            for(int k=1;k<j && k<=m;k++){
                dp[i][j]+=dp[i-1][j-k];//As assuming one dice to be taking values from 1 to m-1 and rest (i-1) dices having sum (j-k)
            }
        }
    }
    return dp[n][x];
}

//Optimized Space DP version
long long noOfWays2(int m, int n, int x) {
    long long dp[2][x+1];

    //Initailizing array with 0
    for(int i=1;i<=x;i++){
        dp[0][i]=0;
        dp[1][i]=0;
    }

    //Making for only one dice
    for(int i=1;i<=x && i<=m;i++){
        dp[0][i]=1;
    }

    //Further increasing number of dice
    for(int i=2;i<=n;i++){ // i: Number of dices
        for(int j=i;j<=m*i && j<=x;j++){ // j : Sum on dices
            for(int k=1;k<j && k<=m;k++){
                dp[1][j]+=dp[0][j-k];//As assuming one dice to be taking values from 1 to m-1 and rest (i-1) dices having sum (j-k)
            }
        }
        for(int j=1;j<=x;j++){
            dp[0][j]=dp[1][j];
            dp[1][j]=0;
        }
    }
    return dp[0][x];
}

int main(){
    int m,n,x;
    cin>>m>>n>>x;
    // cout<<noOfWays1(m,n,x)<<"\n";
    cout<<noOfWays2(m,n,x)<<"\n";
    return 0;
}