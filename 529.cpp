#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int slidingPuzzle(vector<vector<int>>& board);
bool isValid(int x,int y);
vector<vector<vector<int>>> possible(vector<vector<int>>& board);
int main() {
    vector<vector<int>> grid;
    vector<int> row1;
    vector<int> row2;

    row1.push_back(1);
    row1.push_back(2);
    row1.push_back(3);
    row2.push_back(4);
    row2.push_back(0);
    row2.push_back(5);

    grid.push_back(row1);
    grid.push_back(row2);

    int res=slidingPuzzle(grid);
    cout<<res<<endl;


}
bool isValid(int x,int y){

    return x>=0&&x<2&&y>=0&&y<3;

}

vector<vector<vector<int>>> possible(vector<vector<int>>& board){
    vector<vector<vector<int>>> res;
    int i=0;int j=0;
    for(int x=0;x<2;x++){
        for(int y=0;y<3;y++){
            if(board[x][y]==0){
                i=x;
                j=y;
            }
        }
    }

    if(isValid(i,j-1)){//左
        vector<vector<int>> b=board;
        swap(b[i][j-1],b[i][j]);
        res.push_back(b);
    }
    if(isValid(i,j+1)){
        vector<vector<int>> b=board;
        swap(b[i][j+1],b[i][j]);
        res.push_back(b);
    }
    if(isValid(i-1,j)){
        vector<vector<int>> b=board;
        swap(b[i-1][j],b[i][j]);
        res.push_back(b);
    }
    if(isValid(i+1,j)){
        vector<vector<int>> b=board;
        swap(b[i+1][j],b[i][j]);
        res.push_back(b);
    }
    return res;
}
int slidingPuzzle(vector<vector<int>>& board) {



    vector<vector<int>> target;
    vector<int> row1;
    vector<int> row2;
    row1.push_back(1);
    row1.push_back(2);
    row1.push_back(3);
    row2.push_back(4);
    row2.push_back(5);
    row2.push_back(0);
    target.push_back(row1);
    target.push_back(row2);
    if(target==board)
        return 0;

    queue<vector<vector<int>>> Q;
    map<vector<vector<int>>,int> visited;
    Q.push(board);
    visited[board]=0;
    while(!Q.empty()){
        vector<vector<int>> cur=Q.front();
        Q.pop();
        int level=visited[cur];

        vector<vector<vector<int>>> list=possible(cur);
        for(int i=0;i<list.size();i++){
            if(visited.find(list[i])==visited.end()){
                if(list[i]==target)
                    return level+1;
                visited[list[i]]=level+1;
                Q.push(list[i]);
            }
        }
    }
    return -1;
}