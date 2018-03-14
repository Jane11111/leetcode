#include <iostream>
#include <vector>
using namespace std;

void gameOfLife(vector<vector<int>>& board);
bool isValid(int i,int j,int m,int n);
int willLive(int i,int j,int m,int n,vector<vector<int>>& board);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

bool isValid(int i,int j,int m,int n){
    if(i>=0&&i<m&&j>=0&&j<n)
        return true;
    return false;
}
//1 3表示原来是1  0 2表示原来是0  1 0 表示将会活
int willLive(int i,int j,int m,int n,vector<vector<int>>& board){
    int count=0;
    //上
    if(isValid(i-1,j,m,n)&&board[i-1][j]%2)
        count++;
    //下
    if(isValid(i+1,j,m,n)&&board[i+1][j]%2)
        count++;
    //左
    if(isValid(i,j-1,m,n)&&board[i][j-1]%2)
        count++;
    //右
    if(isValid(i,j+1,m,n)&&board[i][j+1]%2)
        count++;
    //左上
    if(isValid(i-1,j-1,m,n)&&board[i-1][j-1]%2)
        count++;
    //左下
    if(isValid(i+1,j-1,m,n)&&board[i+1][j-1]%2)
        count++;
    //右上
    if(isValid(i-1,j+1,m,n)&&board[i-1][j+1]%2)
        count++;
    //右下
    if(isValid(i+1,j+1,m,n)&&board[i+1][j+1]%2)
        count++;
    return count;
}
void gameOfLife(vector<vector<int>>& board) {

    int m=board.size();
    if(m==0)
        return ;
    int n=board[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int num=willLive(i,j,m,n,board);
            if(board[i][j]==0&&num==3||board[i][j]==1&&(num==2||num==3))
                board[i][j]+=2;
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==2||board[i][j]==3)
                board[i][j]=1;
            else
                board[i][j]=0;
        }
    }
}