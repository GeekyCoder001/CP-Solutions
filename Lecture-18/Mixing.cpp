//Given two integers M and N (max 32 bit) and given two bit positions i and j, insert all bits of N into M such that bits oof N
//start at index j and end at index i.
#include<bits/stdc++.h>
using namespace std;

void binaryMix(int& m, int n, int i, int j){
    //first check whether values of i and j are correct
    if(i<0 | j>31 | (j-i+1)!=((int)log2(n)+1)){
        m=-1;
        return;
    }

    //creating a bitMask to make all required bits 0
    int bitMask=pow(2,j-i+1)-1;
    bitMask=~(bitMask<<i);
    m=m&bitMask;

    //Inserting n into m
    n=n<<i;
    m|=n;
}
void printBinary32(int num){
    for(unsigned i=1<<31;i>0;i=i>>1){
        cout<<((num&i)?"1":"0");
    }
}
int main(){
    int m,n,i,j;
    cin>>m>>n>>i>>j;
    binaryMix(m,n,i,j);
    if(m==-1) cout<<m<<"\n";
    else printBinary32(m);
    return 0;
}