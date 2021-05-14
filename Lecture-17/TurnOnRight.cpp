//Program to turn off rightmost bit of a number
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    //In (n+1), all right 1's before first 0 will become 0 and rightmost 1 will become 1
    //After ORing n with (n+1) all number after rightmost 0 will not effected and before it, all are 1's will remain 1 and that 0 will become 1
    n=n|(n+1);
    cout<<n<<"\n";
    return 0;
}