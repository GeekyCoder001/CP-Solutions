// Program to get next smallest number having same number of 1s in the binary representation as the give number
#include<bits/stdc++.h>
using namespace std;

int nextSmallestNumber(int n){
    int c0=0,temp=n,c1=0;

    //Counting the leftmost 0's before first 1
    while(temp && !(temp&1)){
        c0++;
        temp>>=1;
    }

    //Counting the 1's after that 0's
    while(temp && (temp&1)){
        c1++;
        temp>>=1;
    }

    //Changing 0 after 1's to 1
    int oneInc=1<<(c1+c0);
    n=n|oneInc;

    //Making leftmost 0's and 1's to 0 and rearrange it to make first (c1-1) bits to 1
    n=n&oneInc;
    int ones=pow(2,c1-1)-1;
    n=n|ones;
    
    return n;
}

int main(){
    int n;
    cin>>n;
    int ans=nextSmallestNumber(n);
    cout<<ans<<"\n";
    return 0;
}