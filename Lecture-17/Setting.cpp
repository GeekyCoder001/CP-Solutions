//Program for setting kth bit of a number
#include<bits/stdc++.h>
using namespace std;
int settingKth(int &n, int k){
    //(1<<(k-1)) will create a bit mask of form such that all bits are 0 other than kth bit
    // if kth bit is 1 in n, after ORing, it will remain 1
    // else if kth bit is 0 in n, after ORing, it will become 1
    return (n | (1<<(k-1)));
}

int main(){
    int n,k;
    cin>>n;
    cin>>k;
    int ans=settingKth(n,k);
    cout<<ans<<endl;  
    return 0;
}