#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);
int main() {
    vector<vector<int>> obstacleGrid;
    vector<int> row1(3,0);
    vector<int> row2;
    row2.push_back(0);
    row2.push_back(1);
    row2.push_back(0);
    obstacleGrid.push_back(row1);
    obstacleGrid.push_back(row2);
    obstacleGrid.push_back(row1);

    int res=uniquePathsWithObstacles(obstacleGrid);
    cout<<res<<endl;
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();
    if(m==0||n==0)
        return 0;

    int res_grid[m][n];
    if(obstacleGrid[0][0]==0)
        res_grid[0][0]=1;
    else
        res_grid[0][0]=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0&& j==0)
                continue;
            res_grid[i][j]=0;
            if(obstacleGrid[i][j]==1)
                res_grid[i][j]=0;
            else{
                if(i-1>=0)
                    res_grid[i][j]+=res_grid[i-1][j];
                if(j-1>=0)
                    res_grid[i][j]+=res_grid[i][j-1];
            }
        }
    }
    return res_grid[m-1][n-1];


}