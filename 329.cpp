#include <iostream>
#include <vector>
using namespace std;

int longestIncreasingPath(vector<vector<int>>& matrix);
void dfs(vector<vector<int>>& matrix,int & step,int x,int y,vector<vector<int>>& M);
bool isValid(int x,int y,int m,int n);
int main() {
    vector<vector<int>> matrix;
    vector<int> row1;
    vector<int> row2;
    vector<int> row3;
    row1.push_back(3);
    row1.push_back(4);
    row1.push_back(5);
    row2.push_back(3);
    row2.push_back(2);
    row2.push_back(6);
    row3.push_back(2);
    row3.push_back(2);
    row3.push_back(1);
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    int res=longestIncreasingPath(matrix);
    cout<<res<<endl;
    return 0;
}
bool isValid(int x,int y,int m,int n){
    return x>=0&&x<m&&y>=0&&y<n;
}
void dfs(vector<vector<int>>& matrix,int& step,int x,int y,vector<vector<int>>& M){

    if(M[x][y]!=INT_MIN){
        step+=M[x][y];
        return ;
    }

    int base=matrix[x][y];
    int m=matrix.size();
    int n=matrix[0].size();

    int count=INT_MIN;
    if(isValid(x-1,y,m,n)&&matrix[x-1][y]>base){
        int n1=1;
        dfs(matrix,n1,x-1,y,M);
        count=max(n1,count);
    }
    if(isValid(x+1,y,m,n)&&matrix[x+1][y]>base){
        int n1=1;
        dfs(matrix,n1,x+1,y,M);
        count=max(n1,count);
    }
    if(isValid(x,y-1,m,n)&&matrix[x][y-1]>base){
        int n1=1;
        dfs(matrix,n1,x,y-1,M);
        count=max(n1,count);
    }
    if(isValid(x,y+1,m,n)&&matrix[x][y+1]>base){
        int n1=1;
        dfs(matrix,n1,x,y+1,M);
        count=max(n1,count);
    }
    if(count!=INT_MIN) {
        M[x][y]=count;
        step += count;
    }else{
        M[x][y]=0;
    }



}
int longestIncreasingPath(vector<vector<int>>& matrix) {
    int m=matrix.size();
    if(m==0)
        return 0;
    int n=matrix[0].size();
    if(n==0)
        return 0;
    vector<vector<int>> M;
    for(int i=0;i<m;i++){
        vector<int> t;
        for(int j=0;j<n;j++){
            t.push_back(INT_MIN);
        }
        M.push_back(t);
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(M[i][j]==INT_MIN) {
                int step=0;
                dfs(matrix, step,i, j, M);
            }
        }
    }
    int res=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            res=max(res,M[i][j]+1);
        }
    }
    return res;

}