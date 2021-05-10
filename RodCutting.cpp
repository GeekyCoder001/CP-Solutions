#include<iostream>
#include<limits.h>
#include<vector>
int price[11];
using namespace std;
int getMaxRecursive(int n){
    if(n==0) return 0;
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(price[i],getMaxRecursive(n-i-1));
    }
    return ans;
}
void getMaxBottomUp(int n, vector<int> &ans, vector<int> &way){
    ans[0]=0;
    for(int i=1;i<=n;i++){
        int temp=INT_MIN;
        for(int j=i;j>=1;j--){
            if(temp<(price[j]+ans[i-j])){
                temp=price[j]+ans[i-j];
                way[i]=j;
            }
        }
        ans[i]=temp;
    }
}
int MemoizedCutRodAux(int n, vector<int> &ans){
    if(ans[n]>=0){
        return ans[n];
    }
    int q;
    if(n==0) q=0;
    else{
        q=INT_MIN;
        for(int i=1;i<=n;i++){
            q=max(q,price[i]+MemoizedCutRodAux(n-i,ans));
        }
    }
    ans[n]=q;
    return q;
}
int MemoizedCutRod(int n){
    vector<int> ans(n+1);
    for(int i=0;i<=n;i++){
        ans[i]=INT_MIN;
    }
    return MemoizedCutRodAux(n,ans);
}
int main(){
    price[1]=1;
    price[2]=5;
    price[3]=8;
    price[4]=9;
    price[5]=10;
    price[6]=17;
    price[7]=17;
    price[8]=20;
    price[9]=24;
    price[10]=30;
    int n;
    cin>>n;
    // cout<<getMaxRecursive(n)<<"\n";

    vector<int> ans(n+1),way(n+1);
    getMaxBottomUp(n,ans,way);
    cout<<"Length Cost Pieces\n";
    for(int i=1;i<=n;i++){
        printf("%6d%5d   ",i,ans[i]);
        int j=i;
        while(j>0){
            cout<<way[j];
            j-=way[j];
            if(j) cout<<"+";
        }
        cout<<"\n";
    }

    // cout<<MemoizedCutRod(n)<<"\n";
    return 0;
}