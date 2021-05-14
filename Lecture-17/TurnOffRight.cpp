//Program to turn off rightmost bit of a number
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    //In (n-1), all right 0's before first 1 will become 1 and rightmost 1 will become 0
    //After ANDing n with (n-1) all number after rightmost 1 will not effected and before it, all are 0's will remain 0 and that 1 will become 0
    n=n&(n-1);
    cout<<n<<"\n";
    return 0;
}