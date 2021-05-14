//Program to find number in in array of unique (n-1) elements in range of 1...n
#include<bits/stdc++.h>
using namespace std;

int findMissing(int a[], int n){
    int xor1=0,xor2=0;
    for(int i=1;i<=n;i++){
        xor1^=i;
    }
    for(int i=0;i<n-1;i++){
        xor2^=a[i];
    }
    return (xor1^xor2);
}

int main(){
    int n;
    cin>>n;
    int a[n-1];
    for(int i=0;i<n-1;i++) cin>>a[i];
    int ans=findMissing(a,n);
    cout<<ans<<"\n";
    return 0;
}