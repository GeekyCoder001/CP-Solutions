//Program to clear kth bit of a number
#include<bits/stdc++.h>
using namespace std;
int clearingKth(int &n, int k){
    //(1<<(k-1)) will create a bit mask of form such that all bits are 0 other than kth bit
    // After negation, all bits of it will become 1 other than kth bit
    // if kth bit is 0 in n, after ANDing, it will remain 0
    // else if kth bit is 1 in n, after ANDing, it will become 0
    return (n & ~(1<<(k-1)));
}

int main(){
    int n,k;
    cin>>n;
    cin>>k;
    int ans=clearingKth(n,k);
    cout<<ans<<endl;  
    return 0;
}