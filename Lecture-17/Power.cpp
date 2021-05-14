//Program to compute A^n using bit manipulation
#include<bits/stdc++.h>
using namespace std;

//Time Complexity : O(lg(n)) (In brute force, it is O(n))
//Space Complexity : O(1)
int power(int a, int n){
    int ans=1;
    while(n){
        //(n&1) will give last bit if n (one by one we will explore all bits of n)
        int last_bit=n&1;
        if(last_bit==1) ans*=a; // if last bit is one, we need to take this value to a in consideration
        a=a*a;//at each time value becoming square
        n=n>>1;// to get next bit in next iteration
    }
    return ans;
}

int main(){
    int a,n;
    cin>>a>>n;
    int ans=power(a,n);
    cout<<ans<<"\n";
    return 0;
}