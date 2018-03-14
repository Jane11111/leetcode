#include <iostream>
#include <vector>
using namespace std;

int numIslands(vector<vector<char>>& grid);
bool isValid(pair<int,int> p,int m,int n);
bool isOne(pair<int,int> p,vector<vector<char>> & grid);
void setZero(pair<int,int> p,vector<vector<char>> & grid);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
bool isValid(pair<int,int> p,int m,int n){
    int x=p.first;
    int y=p.second;

    return x>=0&&x<m&&y>=0&&y<n;
}
bool isOne(pair<int,int> p,vector<vector<char>> & grid){
    int x=p.first;
    int y=p.second;
    return grid[x][y]=='1';
}
void setZero(pair<int,int> p,vector<vector<char>> & grid){
    int x=p.first;
    int y=p.second;
    grid[x][y]='0';
}
int numIslands(vector<vector<char>>& grid) {

    int res=0;
    int m=grid.size();
    if(m==0)
        return res;
    int n=grid[0].size();
    if(n==0)
        return res;

    for(int i=0;i<m;i++){

        for(int j=0;j<n;j++){
            if(grid[i][j]=='1'){
                res++;
                vector<pair<int,int>> Q;
                Q.push_back(pair<int,int>(i,j));
                grid[i][j]='0';

                while(!Q.empty()){
                    pair<int,int> p=Q[0];
                    Q.erase(Q.begin());
                    int x=p.first;
                    int y=p.second;

                    pair<int,int> up=pair<int,int>(x-1,y);
                    pair<int,int> down=pair<int,int>(x+1,y);
                    pair<int,int> left=pair<int,int>(x,y-1);
                    pair<int,int> right=pair<int,int>(x,y+1);

                    if(isValid(up,m,n)&&isOne(up,grid)){
                        Q.push_back(up);
                        setZero(up,grid);
                    }
                    if(isValid(down,m,n)&&isOne(down,grid)){
                        Q.push_back(down);
                        setZero(down,grid);
                    }
                    if(isValid(left,m,n)&&isOne(left,grid)){
                        Q.push_back(left);
                        setZero(left,grid);
                    }
                    if(isValid(right,m,n)&&isOne(right,grid)){
                        Q.push_back(right);
                        setZero(right,grid);
                    }



                }


            }
        }


    }
    return res;

}