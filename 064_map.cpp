#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;


int minPathSum(vector<vector<int>>& grid);
bool isValid(int x,int y,int m,int n);

int main() {
    vector<vector<int>> grid;
    vector<int> row1;
    vector<int> row2;
    // vector<int> row3;
    row1.push_back(1);
    row1.push_back(2);
    //  row1.push_back(1);
    row2.push_back(1);
    row2.push_back(1);
    // row2.push_back(1);
    // row3.push_back(4);
    // row3.push_back(2);
    // row3.push_back(1);
    grid.push_back(row1);
    grid.push_back(row2);
    // grid.push_back(row3);
    int res=minPathSum(grid);
    cout<<res<<endl;
}
bool isValid(int x,int y,int m,int n){
    return x>=0&&x<m&&y>=0&&y<n;
}

int minPathSum(vector<vector<int>>& grid) {
    int m=grid.size();
    if(m==0)
        return 0;
    int n=grid[0].size();
    if(n==0)
        return 0;

    int dis[m][n];
    map<pair<int,int>,bool> Q;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++) {
            dis[i][j] = INT_MAX;
           // Q.push_back(pair<int,int>(i,j));
        }

    dis[0][0]=grid[0][0];
    Q[pair<int,int>(0,0)]=grid[0][0];
    while(!Q.empty()){
        int x=0,y=0;
        int min=INT_MAX;
        int index=0;
        for(auto ite:Q){
            if(dis[ite.first.first][ite.first.second]<min){
                x=ite.first.first;
                y=ite.first.second;
                min=dis[x][y];
            }

        }
        if(min==INT_MAX)
            break;
        if(x==m-1&&y==n-1)
            break;
        Q.erase(pair<int,int>(x,y));

        //if(isValid(x-1,y,m,n)&&dis[x-1][y]>min+grid[x-1][y]){
        //    dis[x-1][y]=grid[x][y];
        //}
        if(isValid(x+1,y,m,n)&&dis[x+1][y]>min+grid[x+1][y]){
            dis[x+1][y]=min+grid[x+1][y];
            Q[pair<int,int>(x+1,y)]=true;
        }
        //if(isValid(x,y-1,m,n)&&dis[x][y-1]>min+grid[x][y-1]){
        //    dis[x][y-1]=min+grid[x][y-1];
        // }
        if(isValid(x,y+1,m,n)&&dis[x][y+1]>min+grid[x][y+1]){
            dis[x][y+1]=min+grid[x][y+1];
            Q[pair<int,int>(x,y+1)]=true;
        }




    }

    return dis[m-1][n-1];

}