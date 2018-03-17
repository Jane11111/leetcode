#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp{
    bool operator()(vector<int> a,vector<int> b){
        return a[2]<b[2];
    }
};

int swimInWater(vector<vector<int>>& grid);
bool canReach(vector<vector<int>>& grid,int x1,int y1,int x2,int y2);
bool isValid(int x,int y,int m,int n);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
bool isValid(int x,int y,int m,int n){
    return x>=0&&x<m&&y>=0&&y<n;
}
bool canReach(vector<vector<int>>& grid,int x1,int y1,int x2,int y2){
    if(grid[x1][y1]==INT_MAX||grid[x2][y2]==INT_MAX)
        return false;
    int m=grid.size();
    int n=grid.size();
    vector<pair<int,int>> Q;
    bool visited[m][n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            visited[i][j]=false;

    visited[x1][y1]=true;
    Q.push_back(pair<int,int>(x1,y1));
    while(!Q.empty()){
        pair<int,int> p=Q[0];
        Q.erase(Q.begin());
        int x=p.first;
        int y=p.second;
        if(x==x2&&y==y2)
            return true;

        if(isValid(x-1,y,m,n)&&!visited[x-1][y]&&grid[x-1][y]!=INT_MAX){
            visited[x-1][y]=true;
            Q.push_back(pair<int,int>(x-1,y));
        }
        if(isValid(x+1,y,m,n)&&!visited[x+1][y]&&grid[x+1][y]!=INT_MAX){
            visited[x+1][y]=true;
            Q.push_back(pair<int,int>(x+1,y));
        }
        if(isValid(x,y-1,m,n)&&!visited[x][y-1]&&grid[x][y-1]!=INT_MAX){
            visited[x][y-1]=true;
            Q.push_back(pair<int,int>(x,y-1));
        }
        if(isValid(x,y+1,m,n)&&!visited[x][y+1]&&grid[x][y+1]!=INT_MAX){
            visited[x][y+1]=true;
            Q.push_back(pair<int,int>(x,y+1));
        }

    }
    return false;
}
int swimInWater(vector<vector<int>>& grid) {

    int m=grid.size();
    if(m==0)
        return 0;
    int n=grid[0].size();
    if(n==0)
        return 0;

    priority_queue<vector<int>,vector<vector<int>>,cmp> orders;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            vector<int> t;
            t.push_back(i);
            t.push_back(j);
            t.push_back(grid[i][j]);
            orders.push(t);
        }
    }

    //vector<int> row(m,n);
    //vector<int> col(n,m);

    while(true){
        vector<int> t=orders.top();

        int x=t[0];
        int y=t[1];
        int h=t[2];
       // row[x]--;
       // col[y]--;
        grid[x][y]=INT_MAX;
        bool f=canReach(grid,0,0,m-1,n-1);
        if(!f)
            break;
        orders.pop();
    }

    if(orders.empty())
        return 0;
    return orders.top()[2];


}