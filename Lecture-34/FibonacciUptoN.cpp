//Program to print first n terms of a fibonacci series
#include<iostream>
using namespace std;
void nthTerm(int n, int ans[]){
    //First two values are 1
    ans[1]=1;
    ans[2]=1;
    //Remaining
    for(int i=3;i<=n;i++){
        ans[i]=ans[i-1]+ans[i-2];//Definition
    }
}
int main(){
    int n;
    cin>>n;
    int ans[n+1];
    nthTerm(n,ans);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}