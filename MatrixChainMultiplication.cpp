#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
void matrixMultiplication(int p, int arr[], vvi &m, vvi &s){
    int n=p-1;
    for(int i=1;i<=n;i++){
        m[i][i]=0;
    }
    for(int l=2;l<=n;l++){
        for(int i=1;i<=n-l+1;i++){
            int j=i+l-1;
            m[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                int temp=m[i][k]+m[k+1][j]+arr[i-1]*arr[k]*arr[j];
                if(temp<m[i][j]){
                    m[i][j]=temp;
                    s[i][j]=k;
                }
            }
        }
    }
}
void print(vvi s, int i, int j){
    if(i==j) cout<<" A"<<i<<" ";
    else{
        cout<<"(";
        print(s,i,s[i][j]);
        print(s,s[i][j]+1,j);
        cout<<")";
    }
}
int LookUp(int n, int arr[], vvi &m, vvi &s, int i, int j){
    if(m[i][j]<INT_MAX) return m[i][j];
    if(i==j){
        m[i][j]=0;
    }
    else{
        for(int k=i;k<j;k++){
            int temp=LookUp(n,arr,m,s,i,k)+LookUp(n,arr,m,s,k+1,j)+arr[i-1]*arr[k]*arr[j];
            if(temp<m[i][j]){
                m[i][j]=temp;
                s[i][j]=k;
            }
        }
    }
    return m[i][j];
}
void matrixMultiplicationMemoized(int p, int arr[], vvi &m, vvi &s){
    int n=p-1;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            m[i][j]=INT_MAX;
        }
    }
    LookUp(n,arr,m,s,1,n);
}
int main(){
    int n;
    cin>>n;
    vvi m(n,vi(n)),s(n,vi(n));
    int dim[n];
    for(int i=0;i<n;i++){
        cin>>dim[i];
    }
    // matrixMultiplication(n,dim,m,s);
    matrixMultiplicationMemoized(n,dim,m,s);
    cout<<"Minimum Cost : "<<m[1][n-1]<<"\n";
    cout<<"Optimal Parenthesization : ";
    print(s,1,n-1);
    cout<<"\n";
    return 0;
}