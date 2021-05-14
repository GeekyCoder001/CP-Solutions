//Program to find two repeating numbers in array containing (n+2) numbers in range 1...n
#include<bits/stdc++.h>
using namespace std;
void findRepeating(int a[], int n, int& ans1, int& ans2){
    int xor1=0,xor2=0;
    for(int i=1;i<=n;i++) xor1^=i;   //XOR of 1...n
    for(int i=0;i<n+2;i++) xor2^=a[i];  //XOR of array
    int k=xor1^xor2;  // k is ans1^ans2
    xor1=0;
    xor2=0;
    int bitDiff=k&(~(k-1));   //Finding any set bit of k that will differ ans1 and ans2 (here we are taking first set bit)
    for(int i=1;i<=n;i++){
        if(i&bitDiff) xor1^=i;    //XORing in 1...n having bitDiff bit set
        else xor2^=i;             // bitDiff not set
    }
    for(int i=0;i<n+2;i++){
        if(a[i]&bitDiff) xor1^=a[i];     //XORing in array having bitDiff bit set
        else xor2^=a[i];                 //bitDiff not set
    }
    ans1=xor1; //xor1 and xor2 will give ans1 and ans2 respectively as all other numbers cancel with each other 
    ans2=xor2;
}

int main(){
    int n,ans1,ans2;
    cin>>n;
    int a[n+2];
    for(int i=0;i<n+2;i++) cin>>a[i];
    findRepeating(a,n,ans1,ans2);
    cout<<ans1<<" "<<ans2<<"\n";
    return 0;
}