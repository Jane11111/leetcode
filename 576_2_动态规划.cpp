#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int findPaths(int m, int n, int N, int i, int j);
bool isValid(int i,int j,int m,int n);
int main() {
    int m=2;
    int n=2;
    int N=2;
    int k=0;
    int t=0;
    int res=findPaths(m,n,N,k,t);
    cout<<res<<endl;
}
bool isValid(int i,int j,int m,int n){
    return i>=0&&i<m&&j>=0&&j<n;
}
int findPaths(int m, int n, int N, int k, int t){
    if(N==0)
        return 0;

    int paths[N+1][m][n];
    for(int i=0;i<=N;i++)
        for(int j=0;j<m;j++)
            for(int l=0;l<n;l++)
                paths[i][j][l]=0;

    for(int k=1;k<=N;k++) {
        for (int i = 0; i < n; i++) {
            paths[k][0][i]++;
            paths[k][m - 1][i]++;
        }
    }
    for(int k=1;k<=N;k++) {
        for (int i = 0; i < m; i++) {
            paths[k][i][0]++;
            paths[k][i][n - 1]++;
        }
    }

    int base=pow(10,9)+7;

    for(int i=2;i<=N;i++){
        for(int j=0;j<m;j++){
            for(int l=0;l<n;l++){

                if(isValid(j-1,l,m,n))
                    paths[i][j][l]+=paths[i-1][j-1][l];
                paths[i][j][l]%=base;
                if(isValid(j+1,l,m,n))
                    paths[i][j][l]+=paths[i-1][j+1][l];
                paths[i][j][l]%=base;
                if(isValid(j,l-1,m,n))
                    paths[i][j][l]+=paths[i-1][j][l-1];
                paths[i][j][l]%=base;
                if(isValid(j,l+1,m,n))
                    paths[i][j][l]+=paths[i-1][j][l+1];
                paths[i][j][l]%=base;

                paths[i][j][l]%=base;
            }
        }
    }

    return paths[N][k][t];

}