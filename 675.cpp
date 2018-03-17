#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int cutOffTree(vector<vector<int>>& forest);
bool isValid(int x,int y,int m,int n);
int bfs(vector<vector<int>>& forest,int x1,int x2,int y1,int y2);
int main() {
    vector<vector<int>> forest;
    vector<int> row1;
    vector<int> row2;
    vector<int> row3;
    row1.push_back(1);
    row1.push_back(2);
    row1.push_back(3);
    row2.push_back(0);
    row2.push_back(0);
    row2.push_back(4);
    row3.push_back(7);
    row3.push_back(6);
    row3.push_back(5);
    forest.push_back(row1);
    forest.push_back(row2);
    forest.push_back(row3);
    int res=cutOffTree(forest);
    cout<<res<<endl;
}
bool isValid(int x,int y,int m,int n){
    return x>=0&&x<m&&y>=0&&y<n;
}
int bfs(vector<vector<int>>& forest,int x1,int y1,int x2,int y2){
    int m=forest.size();
    int n=forest[0].size();

    int dis[m][n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            dis[i][j]=INT_MAX;

    queue<pair<int,int>>Q;
    dis[x1][y1]=0;
    Q.push(pair<int,int>(x1,y1));
    while(!Q.empty()){
        pair<int,int> p=Q.front();
        Q.pop();
        int x=p.first;
        int y=p.second;
        int step=dis[x][y];

        if(x==x2&&y==y2)
            break;

        if(isValid(x-1,y,m,n)&&forest[x-1][y]&&dis[x-1][y]==INT_MAX){
            dis[x-1][y]=step+1;
            Q.push(pair<int,int>(x-1,y));
        }
        if(isValid(x+1,y,m,n)&&forest[x+1][y]&&dis[x+1][y]==INT_MAX){
            dis[x+1][y]=step+1;
            Q.push(pair<int,int>(x+1,y));
        }
        if(isValid(x,y-1,m,n)&&forest[x][y-1]&&dis[x][y-1]==INT_MAX){
            dis[x][y-1]=step+1;
            Q.push(pair<int,int>(x,y-1));
        }
        if(isValid(x,y+1,m,n)&&forest[x][y+1]&&dis[x][y+1]==INT_MAX){
            dis[x][y+1]=step+1;
            Q.push(pair<int,int>(x,y+1));
        }
    }
    return dis[x2][y2];

}
int cutOffTree(vector<vector<int>>& forest){

    int m=forest.size();
    if(m==0)
        return 0;
    int n=forest[0].size();
    if(n==0)
        return 0;


    vector<pair<int,int>> orders;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(forest[i][j]>1){
                orders.push_back(pair<int,int>(i,j));
                for(int k=orders.size()-2;k>=0;k--){
                    if(forest[orders[k].first][orders[k].second]>forest[i][j])
                        swap(orders[k],orders[k+1]);
                }
            }
        }
    }
    int res=0;
    int x_pre=0;
    int y_pre=0;
    for(int i=0;i<orders.size();i++){
        pair<int,int> p=orders[i];
        int x=p.first;
        int y=p.second;
        int d=bfs(forest,x_pre,y_pre,x,y);
        if(d==INT_MAX)
            return -1;
        res+=d;
        x_pre=x;
        y_pre=y;
    }
    return res;



}
