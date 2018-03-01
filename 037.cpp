#include <iostream>
#include <vector>
using namespace std;

void solveSudoku(vector<vector<char>>& board);
bool isOk(vector<vector<char>>&board,int row,int col,vector<vector<bool>>& row_ok,vector<vector<bool>>& col_ok);
int CharToInt(char c);
char IntToChar(int i);
int main() {
    vector<vector<char>> board;
    vector<char> row1(9,'.');
    vector<char> row2(9,'.');
    vector<char> row3(9,'.');
    vector<char> row4(9,'.');
    vector<char> row5(9,'.');
    vector<char> row6(9,'.');
    vector<char> row7(9,'.');
    vector<char> row8(9,'.');
    vector<char> row9(9,'.');
    row1[2]='9';
    row1[3]='7';
    row1[4]='4';
    row1[5]='8';
    row2[0]='7';
    row3[1]='2';
    row3[3]='1';
    row3[5]='9';
    row4[2]='7';
    row4[6]='2';
    row4[7]='4';
    board.push_back(row1);
    board.push_back(row2);
    board.push_back(row3);
    board.push_back(row4);
    board.push_back(row5);
    board.push_back(row6);
    board.push_back(row7);
    board.push_back(row8);
    board.push_back(row9);

    solveSudoku(board);



}
int CharToInt(char c){
    switch(c){
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            return 0;
    }
}
char IntToChar(int i){
    switch(i){
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
        default:
            return '0';
    }
}

bool isOk(vector<vector<char>>&board,int row,int col,vector<vector<bool>>& row_ok,vector<vector<bool>>& col_ok){
    int j=col;
    for(int i=row;i<9;i++){
        for(;j<9;j++){
            if(board[i][j]=='.'){
                for(int m=1;m<10;m++){//i行j列可否方m这个数字
                    if(row_ok[i][m]&&col_ok[j][m]){

                        bool f=true;//判断四周是否有m
                        int x=i/3;
                        int y=j/3;
                        for(int l=0;l<3;l++){
                            for(int k=0;k<3;k++){
                                int n=CharToInt(board[3*x+l][3*y+k]);
                                if(n==m)
                                    f=false;

                            }
                        }
                        if(!f)
                            continue;

                        row_ok[i][m]=false;
                        col_ok[j][m]=false;
                        board[i][j]=IntToChar(m);
                        bool r=isOk(board,i,j+1,row_ok,col_ok);
                        if(!r){
                            board[i][j]='.';
                            row_ok[i][m]=true;
                            col_ok[j][m]=true;
                        }else
                            return true;
                    }
                }
                return false;//m都不可以
            }
        }
        j=0;
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    vector<vector<bool>> row_ok;
    vector<vector<bool>> col_ok;
    for(int i=0;i<9;i++){
        vector<bool> t1;
        vector<bool> t2;
        for(int j=0;j<10;j++){
            t1.push_back(true);
            t2.push_back(true);
        }
        row_ok.push_back(t1);
        col_ok.push_back(t2);
    }


    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            char c=board[i][j];
            if(c!='.'){
                int n=CharToInt(c);
                row_ok[i][n]=false;
                col_ok[j][n]=false;



            }
        }
    }

    isOk(board,0,0,row_ok,col_ok);
    return ;
}