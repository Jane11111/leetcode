#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>>& grid);
bool isValid(int x,int y,int m,int n);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
bool isValid(int x,int y,int m,int n){
    return x>=0&&x<m&&y>=0&&y<n;
}
int minPathSum(vector<vector<int>>& grid){
    int m=grid.size();
    if(m==0)
        return 0;
    int n=grid[0].size();

    int dis[n];
    dis[0]=grid[0][0];
    for(int i=1;i<n;i++){
        dis[i]=dis[i-1]+grid[0][i];
    }

    for(int i=1;i<m;i++){
        for(int j=0;j<n;j++){
            int left=j==0?INT_MAX:dis[j-1];
            int up=dis[j];
            dis[j]=min(left,up)+grid[i][j];
        }
    }
    return dis[n-1];
}