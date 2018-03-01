#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool exist(vector<vector<char>>& board, string word);
bool isExit(vector<vector<char>>& board,map<char,vector<pair<int,int>>> mymap,string word,int start,int row,int col);
bool isNeighbor(int x1,int y1,int x2,int y2);
int main() {
    vector<vector<char>> board;
    vector<char> row1;
    row1.push_back('a');
    row1.push_back('a');
    /*row1.push_back('C');
    row1.push_back('E');

    vector<char> row2;
    row2.push_back('S');
    row2.push_back('F');
    row2.push_back('C');
    row2.push_back('S');

    vector<char> row3;
    row3.push_back('A');
    row3.push_back('D');
    row3.push_back('E');
    row3.push_back('E');*/

    board.push_back(row1);
   // board.push_back(row2);
   // board.push_back(row3);


    string word="aaa";
    bool r=exist(board,word);
    if(r)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}
bool isNeighbor(int x1,int y1,int x2,int y2){
    if(x1==x2&&(y1-y2==1||y2-y1==1))
        return  true;
    if(y1==y2&&(x1-x2==1||x2-x1==1))
        return true;
    return false;
}
//row,col是word[start-1]的坐标
bool isExit(vector<vector<char>>& board,map<char,vector<pair<int,int>>> mymap,string word,int start,int row,int col){
    int len=word.size();
    if(start==len)
        return true;
    char c=word[start];
    if(mymap.count(c)==0)
        return false;

    vector<pair<int,int>> positions=mymap[c];
    for(pair<int,int> p:positions){
        if(board[p.first][p.second]==c&&isNeighbor(p.first,p.second,row,col)) {
            char c=board[p.first][p.second];
            board[p.first][p.second]='.';//标记为已用
            bool r = isExit(board, mymap, word, start + 1, p.first, p.second);
            if(r)
                return true;
            board[p.first][p.second]=c;//回溯
        }

    }
    return false;
}
bool exist(vector<vector<char>>& board, string word) {

    int len=word.size();
    if(len==0)
        return true;

    map<char,vector<pair<int,int>>> mymap;//初始化 mymap
    int m=board.size();
    int n=board[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            char c=board[i][j];
            if(mymap.count(c)==0){
                vector<pair<int,int>> t;
                mymap[c]=t;
            }
            mymap[c].push_back(pair<int,int>(i,j));
        }
    }

    char c=word[0];
    if(mymap.count(c)==0)
        return false;

    vector<pair<int,int>> positions=mymap[c];
    for(pair<int,int>p:positions){
        char c=board[p.first][p.second];
        board[p.first][p.second]='.';
        if(isExit(board,mymap,word,1,p.first,p.second))
            return true;
        board[p.first][p.second]=c;
    }

    return false;
}