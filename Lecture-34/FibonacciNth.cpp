//Program to print nth term of a fibonacci series
#include<iostream>
using namespace std;
int nthTerm(int n){
    //First two values are 1
    if(n==1 || n==2) return 1;
    else{
        //Building Initial Value
        int lastT=1,lastST=1;
        for(int i=3;i<=n;i++){
            int temp=lastST;
            lastST=lastT;
            lastT=temp+lastT;//By Definition
        }
        return lastT;
    }
}
int main(){
    int n;
    cin>>n;
    int ans=nthTerm(n);
    cout<<ans<<"\n";
    return 0;
}