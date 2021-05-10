#include<iostream>
#include<limits.h>
using namespace std;
int findAnswer(int n, int a[]){
    int dp[n+1];
    for(int i=1;i<=n;i++){
        dp[i]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[i]>a[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    int ans=dp[1];
    for(int i=2;i<=n;i++){
        if(dp[i]>ans) ans=dp[i];
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    for(int q=1;q<=t;q++){
        int n;
        cin>>n;
        int a[n+1];
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int ans=findAnswer(n,a);
        cout<<ans<<"\n";
    }
    return 0;
}