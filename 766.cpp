#include <iostream>
#include <vector>
using namespace std;

bool isToeplitzMatrix(vector<vector<int>>& matrix);
bool isValid(int x,int y,int row,int col);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
bool isValid(int x,int y,int row,int col){
    if(x>=0&&x<row&&y>=0&&y<col)
        return true;
    return false;
}

bool isToeplitzMatrix(vector<vector<int>>& matrix) {

    int row=matrix.size();
    int col=matrix[0].size();
    for(int step=row;step>=-col;step--){
        if(row>col){
            bool first=true;
            int num;
            for(int i=0;i<col;i++){
                int x=i+step;
                int y=i;
                if(isValid(x,y,row,col)){
                    if(first){
                        first=false;
                        num=matrix[x][y];
                    }else{
                        if(matrix[x][y]!=num)
                            return false;
                    }
                }
            }

        }else{
            bool first=true;
            int num;
            for(int i=0;i<row;i++){
                int x=i;
                int y=x-step;
                if(isValid(x,y,row,col)){
                    if(first){
                        first=false;
                        num=matrix[x][y];
                    }else{
                        if(matrix[x][y]!=num)
                            return false;
                    }
                }
            }

        }
    }
    return true;

}