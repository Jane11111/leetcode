#include <iostream>
#include <vector>
using namespace std;

int countBattleships(vector<vector<char>>& board);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
int countBattleships(vector<vector<char>>& board) {
    int count=0;
    int row=board.size();
    if(row==0)
        return count;
    int col=board[0].size();

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(board[i][j]=='X'){
                if(i-1>=0&&board[i-1][j]=='X'||j-1>=0&&board[i][j-1]=='X')
                    continue;
                count++;
            }
        }
    }
    return count;

}