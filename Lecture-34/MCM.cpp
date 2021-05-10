//Program to get minimum multipliction for a Matrix Chain Multiplication
#include<iostream>
#include<limits.h>
using namespace std;

int MCM(int n, int p[]){

    //2D array storage for string optimized subsolutions
    int dp[n+1][n+1];

    //Initializing diagonal elements to 0 as it represent multiplication of single matrix
    for(int i=1;i<=n;i++){
        dp[i][i]=0;
    }

    //Taking chain length from 2 to n
    for(int l=2;l<=n;l++){
        //Row index 
        for(int i=1;i<=n-l+1;i++){
            //Coloumn index
            int j=i+l-1;
            //Taking out minimum number of multiplication for chain A(i)*A(i+1)*----*A(j)
            int min=INT_MAX;
            for(int k=i;k<j;k++){
                int temp=dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
                if(temp<min){
                    min=temp;
                }
            }
            dp[i][j]=min;
        }
    }

    //Because we need answer for chain A(1)*A(2)*----*A(n)
    return dp[1][n];
}

int main(){
    int n;
    //Input the number of matrices
    cin>>n;
    int p[n+1];
    //Size of matrices in continous order (n+1) entries
    for(int i=0;i<=n;i++){
        cin>>p[i];
    }
    int ans=MCM(n,p);
    cout<<ans<<"\n";
    return 0;
}