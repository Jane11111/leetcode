#include <iostream>
#include <vector>
#include <map>
using namespace std;

void solve(vector<vector<char>>& board);
bool isRegion(pair<int,int> p,int m,int n);
bool isValid(pair<int,int> p,int m,int n);
bool isO(pair<int,int> p,vector<vector<char>> & board);
int main() {
    vector<vector<char>> board;
    vector<char> row1(3,'O');
    vector<char> row2(3,'O');
    vector<char> row3(3,'O');
    board.push_back(row1);
    board.push_back(row2);
    board.push_back(row3);
    solve(board);

}
bool isRegion(pair<int,int> p,int m,int n){
    int x=p.first;
    int y=p.second;
    return (x==0||x==m-1||y==0||y==n-1);
}
bool isValid(pair<int,int> p,int m,int n){
    int x=p.first;
    int y=p.second;
    return x>=0&&x<m&&y>=0&&y<n;
}
bool isO(pair<int,int> p,vector<vector<char>> & board){
    int x=p.first;
    int y=p.second;
    return board[x][y]=='O';
}
void solve(vector<vector<char>>& board) {

    int m=board.size();
    if(m==0)
        return ;
    int n=board[0].size();
    if(n==0)
        return ;

    map<pair<int,int>,bool> visited;
    vector<pair<int,int>>Q;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){

            if(!visited.count(pair<int,int>(i,j))&&board[i][j]=='O'){//开始进行深度优先

                Q.push_back(pair<int,int>(i,j));//put
                visited[pair<int,int>(i,j)]=true;//已visited

                int index=0;
                bool canLive=false;
                while(index<Q.size()){
                    pair<int,int> p=Q[index];
                    index++;
                    int x=p.first;
                    int y=p.second;
                    if(isRegion(p,m,n))
                        canLive=true;

                    pair<int,int> up=pair<int,int>(x-1,y);
                    pair<int,int> down=pair<int,int>(x+1,y);
                    pair<int,int> left=pair<int,int>(x,y-1);
                    pair<int,int> right=pair<int,int>(x,y+1);

                    if(isValid(up,m,n)&&isO(up,board)&&!visited.count(up)){
                        visited[up]=true;
                        Q.push_back(up);
                    }
                    if(isValid(down,m,n)&&isO(down,board)&&!visited.count(down)){
                        visited[down]=true;
                        Q.push_back(down);
                    }
                    if(isValid(left,m,n)&&isO(left,board)&&!visited.count(left)){
                        visited[left]=true;
                        Q.push_back(left);
                    }
                    if(isValid(right,m,n)&&isO(right,board)&&!visited.count(right)){
                        visited[right]=true;
                        Q.push_back(right);
                    }


                }

                if(!canLive){
                    for(int k=0;k<Q.size();k++){
                        pair<int,int> p=Q[k];
                        board[p.first][p.second]='X';
                    }
                }
                Q.clear();

            }



        }
    }

}