#include<bits/stdc++.h>
using namespace std;

int knapSackRecursiveUtil(int w, int wt[], int val[], int i, int tempW, int total){

    if(tempW>w) return 0; //Sack overloaded
    if(tempW==w || i==-1) return total;//Capacity reached or items exhausted

    //There are two possibilies for each each:-
    //(i):Keep it in sack
    int temp=knapSackRecursiveUtil(w,wt,val,i-1,tempW+wt[i],total+val[i]);
    //(ii):Dont keep it in sack
    temp=max(temp,knapSackRecursiveUtil(w,wt,val,i-1,tempW,total));

    return temp;

}

//Recursive Solution
int knapSackRecursive(int w, int wt[], int val[], int n){

    int tempW=0;
    int total=0;
    return knapSackRecursiveUtil(w,wt,val,n-1,tempW,total);

}

//DP Solution
int knapSackDP(int w, int wt[], int val[], int n){

    int dp[n+1][w+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            dp[i][j]=INT_MIN;
        }
    }

    //Initialization
    dp[0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=w;j++){
            if(dp[i][j]!=INT_MIN){
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]);//Not Taking (i+1)th value
                if((j+wt[i+1])<=w) dp[i+1][j+wt[i+1]]=max(dp[i+1][j+wt[i+1]],(dp[i][j]+val[i+1]));//Taking (i+1)th value
            }
        }
    }

    //Now, answer is max out of last row  
    int ans=dp[n][0];
    for(int i=1;i<=w;i++){
        if(dp[n][i]>ans) ans=dp[n][i];
    }
    return ans;

}
int main(){
    //n:-Number of items
    //w:-Capacity of knap Sack
    int n,w;
    cin>>w>>n;
    //wt:-Array containing the weight of each item
    //val:-Array containing corresponding value
    int wt[n+1],val[n+1];
    for(int i=1;i<=n;i++){
        cin>>wt[i]>>val[i];
    }
    // cout<<knapSackRecursive(w,wt,val,n)<<"\n";
    cout<<knapSackDP(w,wt,val,n)<<"\n";
    return 0;
}