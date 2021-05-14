//Program to find length of longest sequence of '1' in binary representation of a given number provided one flip of '0' to '1' is allowed
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

//Simply taking each bit and making decision based on it and previous bit
//Time Complexity : O(lg(n))
//Space Complexity : O(1)
int findLongest1(int n){
    int maxLen=0,tempLen=0,pre_last=0,pos=1,zeroPos=0;
    while(n){
        int last_digit=n&1;
        if(last_digit==1){
            tempLen++;
        }
        else if(last_digit==0 && pre_last==0){
            zeroPos=pos;
            tempLen=1;
        }
        else{
            tempLen=pos-zeroPos;
            zeroPos=pos;
        }
        if(tempLen>maxLen) maxLen=tempLen;
        n>>=1;
        pre_last=last_digit;
        pos++;
    }
    if(zeroPos==0) maxLen++;
    return maxLen;
}

//Storing count of 0 and 1 alternatively in another array and then finding best way to attach to 1 string
//Time Complexity : O(lg(n))
//Space Complexity : O(lg(n)) 
int findLongest2(int n){
    vector<int> count(1);
    count[0]=0;
    int i=0;
    while(n){
        int last_digit=n&1;
        if(i%2==0){
            if(last_digit==0){
                count[i]++;
            }
            else{
                i++;
                count.push_back(1);
            }
        }
        else{
            if(last_digit==1){
                count[i]++;
            }
            else{
                i++;
                count.push_back(1);
            }
        }
        n=n>>1;
    }
    int ans=1;
    int s=count.size();
    if(s==1) ans=1;
    else if(s==2) ans=count[1]+1;
    else{
        if(count[0]==0) ans=count[1];
        else ans=count[1]+1;
        for(i=2;i<s-1;i+=2){
            if(count[i]==1) ans=max(count[i-1]+count[i+1]+1,ans);
            else ans=max(ans,max(count[i-1],count[i+1])+1);
        }
    }
    return ans;
}
void print(int n){
    if(n>0){
        print(n>>1);
        cout<<(n&1);
    }
}

int main(){
    int n;
    cin>>n;
    cout<<"Binary Representation : \n";
    print(n);
    cout<<"\n";
    // int ans=findLongest1(n);
    int ans=findLongest2(n);
    cout<<ans<<"\n";
    return 0;
}