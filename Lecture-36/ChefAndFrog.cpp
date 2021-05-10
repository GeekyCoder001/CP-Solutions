#include<bits/stdc++.h>
using namespace std;
void canTalk(int n, pair<int, int> arr[], int k, int goUpto[]){
    sort(arr,arr+n);
    goUpto[arr[n-1].second]=arr[n-1].first;
    for(int i=(n-2);i>=0;i--){
        if((arr[i+1].first-arr[i].first)<=k) goUpto[arr[i].second]=goUpto[arr[i+1].second];
        else goUpto[arr[i].second]=arr[i].first;
    }
}
int main(){
    int n,p,k;
    cin>>n>>k>>p;
    pair<int,int> arr[n];
    int goUpto[n+1];
    for(int i=1;i<=n;i++){
        int temp;
        cin>>temp;
        arr[i-1].first=temp;
        arr[i-1].second=i;
    }
    canTalk(n,arr,k,goUpto);
    for(int q=1;q<=p;q++){
        int a,b;
        cin>>a>>b;
        cout<<((goUpto[a]==goUpto[b])?"Yes":"No")<<"\n";
    }
    return 0;
}