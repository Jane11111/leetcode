#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int findPaths(int m, int n, int N, int i, int j);
bool isMargin(int i,int j,int m,int n);
bool isValid(int i,int j,int m,int n);
int main() {
    int m=1;
    int n=3;
    int N=3;
    int i=0;
    int j=1;
    int res=findPaths(m,n,N,i,j);
    cout<<res<<endl;
    return 0;
}
bool isMargin(int i,int j,int m,int n){
    return i==0||i==m-1||j==0||j==n-1;
}

bool isValid(int i,int j,int m,int n){
    return i>=0&&i<m&&j>=0&&j<n;
}
int findPaths(int m, int n, int N, int i, int j) {

    if(N<=0)
        return 0;
    if(N==1){
        int res=0;
        if(i==0)
            res++;
        if(i==m-1)
            res++;
        if(j==0)
            res++;
        if(j==n-1)
            res++;
        return res;
    }

    int t=pow(10,9)+7;
    int res=0;

    if(i==0)
        res++;
    if(i==m-1)
        res++;
    if(j==0)
        res++;
    if(j==n-1)
        res++;
    //res+=findPaths(m,n,N-1,i,j);
    //res%=t;

    if(isValid(i-1,j,m,n))
        res+=findPaths(m,n,N-1,i-1,j);
    res%=t;
    if(isValid(i+1,j,m,n))
        res+=findPaths(m,n,N-1,i+1,j);
    res%=t;
    if(isValid(i,j-1,m,n))
        res+=findPaths(m,n,N-1,i,j-1);
    res%=t;
    if(isValid(i,j+1,m,n))
        res+=findPaths(m,n,N-1,i,j+1);
    res%=t;
    return res;

}