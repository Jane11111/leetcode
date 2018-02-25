#include <iostream>
using namespace std;

void isOk(int row,bool col_used[],bool left_used[],bool right_used[],int n);
int totalNQueens(int n);
int count;
int main() {
    int n=1;
    int res=totalNQueens(n);
    cout<<n<<endl;
}


void isOk(int row,bool col_used[],bool left_used[],bool right_used[],int n){
    if(row==n)
        count++;
    for(int i=0;i<n;i++){
        if(!col_used[i]&&!left_used[row+i]&&!right_used[i-row+n-1]){
            col_used[i]=true;
            left_used[row+i]=true;
            right_used[i-row+n-1]=true;
            isOk(row+1,col_used,left_used,right_used,n);
            col_used[i]=false;
            left_used[row+i]=false;
            right_used[i-row+n-1]=false;
        }
    }
}
int totalNQueens(int n) {
    count=0;
    if(n==0)
        return count;
    int len=(n-1)*2;
    bool col_used[len+1];
    bool left_used[len+1];
    bool right_used[len+1];
    for(int i=0;i<=len;i++){
        col_used[i]=false;
        left_used[i]=false;
        right_used[i]=false;
    }
    isOk(0,col_used,left_used,right_used,n);

    return count;
}