#include <iostream>
#include <vector>
using namespace std;
int maxAreaOfIsland(vector<vector<int>>& grid);
bool isValid(int x,int y,int row,int col);
int main() {
    vector<vector<int>>grid;
    vector<int> row1;
    vector<int> row2;
    //vector<int> row3(3,0);
    //vector<int> row4(3.0);
    row1.push_back(0);
    row1.push_back(1);
    row1.push_back(1);
    row2.push_back(1);
    row2.push_back(0);
    row2.push_back(1);
    //row3.push_back(1);
   // row3.push_back(1);
   // row4.push_back(1);
   // row4.push_back(1);
    grid.push_back(row1);
    grid.push_back(row2);
   // grid.push_back(row3);
   // grid.push_back(row4);

    int area=maxAreaOfIsland(grid);
    cout<<area<<endl;
}
bool isValid(int x,int y,int row,int col){
    if(x>=0&&x<row&&y>=0&&y<col)
        return true;
    return false;
}
int maxAreaOfIsland(vector<vector<int>>& grid) {

    int res=0;
    int row=grid.size();
    if(row==0)
        return 0;
    int col=grid[0].size();
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j]==1){
                int area=0;
                vector<pair<int,int>> Q;
                Q.push_back(pair<int,int>(i,j));
                grid[i][j]=0;
                while(!Q.empty()){
                    pair<int,int> pos=Q[0];
                    int x=pos.first;
                    int y=pos.second;
                    Q.erase(Q.begin());
                    area++;
                    if(isValid(x,y-1,row,col)&&grid[x][y-1]==1){//左
                        Q.push_back(pair<int,int>(x,y-1));
                        grid[x][y-1]=0;
                    }
                    if(isValid(x,y+1,row,col)&grid[x][y+1]==1){//右
                        Q.push_back(pair<int,int>(x,y+1));
                        grid[x][y+1]=0;
                    }
                    if(isValid(x-1,y,row,col)&&grid[x-1][y]==1){//上
                        Q.push_back(pair<int,int>(x-1,y));
                        grid[x-1][y]=0;
                    }
                    if(isValid(x+1,y,row,col)&&grid[x+1][y]==1){//下
                        Q.push_back(pair<int,int>(x+1,y));
                        grid[x+1][y]=0;
                    }
                }
                res=res>area?res:area;
            }
        }
    }
    return res;

}