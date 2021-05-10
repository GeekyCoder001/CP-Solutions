#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
void LCS(string x, string y, int m, int n, vvi &b, vvi &c){
    for(int i=0;i<m+1;i++){
        c[i][0]=0;
    }
    for(int i=0;i<n+1;i++){
        c[0][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1]==y[j-1]){
                b[i][j]=0;
                c[i][j]=c[i-1][j-1]+1;
            }
            else{
                if(c[i-1][j]>c[i][j-1]){
                    b[i][j]=1;
                    c[i][j]=c[i-1][j];
                }
                else{
                    b[i][j]=2;
                    c[i][j]=c[i][j-1];
                }
            }
        }
    }
}
void print(string x, vvi b, int i, int j){
    if(i==0 || j==0){
        return;
    }
    if(b[i][j]==0){
        print(x,b,i-1,j-1);
        cout<<x[i-1];
    }
    else if(b[i][j]==1){
        print(x,b,i-1,j);
    }
    else{
        print(x,b,i,j-1);
    }
}
int main(){
    string x,y;
    cin>>x>>y;
    int m=x.length();
    int n=y.length();
    vvi b(m+1,vi(n+1)),c(m+1,vi(n+1));
    LCS(x,y,m,n,b,c);
    cout<<"Length of LCS : "<<c[m][n]<<"\n";
    cout<<"LCS : ";
    print(x,b,m,n);
    return 0;
}