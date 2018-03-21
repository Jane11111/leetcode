#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

bool isValidSudoku(vector<vector<char>>& board) {

    int flag=0;
    int len=9;
    map<char,int> cmap;
    for(int i=0;i<len+1;i++){
        cmap['0'+i]=0;
    }
    for(int i=0;i<len;i++){//检查行列
        flag++;
        for(int j=0;j<len;j++){
            if(board[i][j]!='.'){
                if(cmap[board[i][j]]==flag)
                    return false;
                cmap[board[i][j]]=flag;
            }

        }
        flag++;
        for(int j=0;j<len;j++){
            if(board[j][i]!='.'){
                if(cmap[board[j][i]]==flag)
                    return false;
                cmap[board[j][i]]=flag;
            }
        }
    }

    for(int i=0;i<len;i+=3){


        for(int j=0;j<len;j+=3){
            flag++;
            for(int r=i;r<i+3;r++){
                for(int c=j;c<j+3;c++){
                    char ch=board[r][c];
                    if(ch!='.'){
                        if(cmap[ch]==flag)
                            return false;
                        cmap[ch]=flag;
                    }

                }
            }
        }

    }
    return true;

}