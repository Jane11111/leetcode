#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n);
bool isValid(int x,int y ,int n);
pair<int,int> getNext(int x,int y,int n,int &direction,int n);
bool isRightValid(int x,int y,int n);
bool isDownValid(int x ,int y,int n);
bool isLeftValid(int x ,int y,int n);
bool isUpValid(int x,int y,int n);
vector<vector<int>> matrix;
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
bool isRightValid(int i,int j,int n){
    if(isValid(i,j+1,n)&&matrix[i][j+1]==-1)//右
        return true;
    return false;

}
bool isDownValid(int i ,int j,int n){
    if(isValid(i+1,j,n)&&matrix[i+1][j]==-1){//下
        return true;
    }
    return false;
}

bool isLeftValid(int i ,int j,int n){
    if(isValid(i,j-1,n)&&matrix[i][j-1]==-1){
        return true;
    }
    return false;
}
bool isUpValid(int i,int j,int n){
    if(isValid(i-1,j,n)&&matrix[i-1][j]==-1){
        return true;
    }
    return false;
}

bool isValid(int x,int y ,int n){
    if(x>=0&&x<n&&y>=0&&y<n)
        return true;
    return false;
}
pair<int,int> getNext(int x,int y,int n,int &direction){
    if(direction==1){
        if(isRightValid(x,y,n)){
            direction=1;
            return pair<int,int>(x,y+1);
        }
        if(isDownValid(x,y,n)){
            direction=2;
            return pair<int,int>(x+1,y);
        }
        if(isLeftValid(x,y,n)){
            direction=3;
            return pair<int,int>(x,y-1);
        }
        if(isUpValid(x,y,n)){
            direction=4;
            return pair<int,int>(x-1,y);
        }
    }else if(direction==2){

        if(isDownValid(x,y,n)){
            direction=2;
            return pair<int,int>(x+1,y);
        }
        if(isLeftValid(x,y,n)){
            direction=3;
            return pair<int,int>(x,y-1);
        }
        if(isUpValid(x,y,n)){
            direction=4;
            return pair<int,int>(x-1,y);
        }
        if(isRightValid(x,y,n)){
            direction=1;
            return pair<int,int>(x,y+1);
        }
    }else if(direction ==3){
        if(isLeftValid(x,y,n)){
            direction=3;
            return pair<int,int>(x,y-1);
        }
        if(isUpValid(x,y,n)){
            direction=4;
            return pair<int,int>(x-1,y);
        }
        if(isRightValid(x,y,n)){
            direction=1;
            return pair<int,int>(x,y+1);
        }
        if(isDownValid(x,y,n)){
            direction=2;
            return pair<int,int>(x+1,y);
        }

    }else if(direction==4){

        if(isUpValid(x,y,n)){
            direction=4;
            return pair<int,int>(x-1,y);
        }
        if(isRightValid(x,y,n)){
            direction=1;
            return pair<int,int>(x,y+1);
        }
        if(isDownValid(x,y,n)){
            direction=2;
            return pair<int,int>(x+1,y);
        }
        if(isLeftValid(x,y,n)){
            direction=3;
            return pair<int,int>(x,y-1);
        }
    }
};
vector<vector<int>> generateMatrix(int n) {

    int count=n*n;
    int cur=1;

    for(int i=0;i<n;i++){
        vector<int> row;
        for(int j=0;j<n;j++)
            row.push_back(-1);
        matrix.push_back(row);
    }

    int i=0;int j=0;
    int direction=1;
    while(cur<=count){
        matrix[i][j]=cur;

        cur++;
        if(cur<=count){
            pair<int,int> p=getNext(i,j,n,direction);

            i=p.first;
            j=p.second;
        }

    }
    return matrix;


}