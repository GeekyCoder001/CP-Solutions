#include <bits/stdc++.h>
using namespace std;

//DP solution
int findSolDP(int arr[], int n){

    //Calculating Total Sum of are cures
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }

    //Initialiazing 2D array DP 
    //Here DP[i][j] represents value of cures in first half(A) upto i in arr having j equals sum+(A-B) -->(B o valure of cures in second half)
    //(A-B) should had lead to -ve index hence we add sum to it
    //Soo, answer is dp[n-1][sum]
    int dp[n][2*sum+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<(2*sum+1);j++){
            dp[i][j]=INT_MIN;
        }
    }

    //For every element, we have three choices
    dp[0][sum]=0;//No taking first element  
    dp[0][sum+arr[0]]=arr[0];//Taking it in A
    dp[0][sum-arr[0]]=0;//Taking it in B

    for(int i=0;i<n-1;i++){
        for(int j=0;j<(2*sum+1);j++){
            if(dp[i][j]!=INT_MIN){
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]);//No taking (i+1)th element
                if((j+arr[i+1])<=(2*sum)) dp[i+1][j+arr[i+1]]=max(dp[i+1][j+arr[i+1]],(dp[i][j]+arr[i+1]));//Taking it in A
                if((j-arr[i+1])>=0) dp[i+1][j-arr[i+1]]=max(dp[i+1][j-arr[i+1]],dp[i][j]);//Taking it in B
            }
        }
    }
    
    return dp[n-1][sum];
}

//Recursive solution
int findSolRec(int arr[], int pos, int A, int B){
    if(pos==-1){
        if(A==B) return A;
        else return 0;
    }
    int temp=findSolRec(arr,pos-1,A+arr[pos],B);
    temp=max(temp,findSolRec(arr,pos-1,A,B+arr[pos]));
    temp=max(temp,findSolRec(arr,pos-1,A,B));
    return temp;
}

int main(){
    int t;
    cin>>t;
    for(int q=1;q<=t;q++){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }        
        int A=0,B=0;
        cout<<findSolDP(arr,n)<<"\n";
        // cout<<findSolRec(arr,n-1,A,B)<<"\n";
    }
    return 0;
}