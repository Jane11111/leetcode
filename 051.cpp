#include <iostream>
#include <vector>
using namespace std;

void isOk(vector<string>undone,bool col_used[],bool left_used[],bool right_used[],int n);
vector<vector<string>> solveNQueens(int n);
vector<vector<string>> res;
string conStr(int n,int pos);
int main() {
    int n=1;
    vector<vector<string>>r=solveNQueens(n);
    cout<<r.size()<<endl;
}

string conStr(int n,int pos){
    string str;
    for(int i=0;i<n;i++){
        if(i==pos)
            str.push_back('Q');
        else
            str.push_back('.');
    }
    return str;

}
void isOk(vector<string>undone,bool col_used[],bool left_used[],bool right_used[],int n){
    if(undone.size()==n){
        res.push_back(undone);//应该需要再copy一份吧
        return ;
    }
    int row=undone.size();
    for(int i=0;i<n;i++){
        if(!col_used[i]){
            if(!left_used[row+i]&&!right_used[i-row+n-1]){
                col_used[i]=true;
                left_used[row+i]=true;
                right_used[i-row+n-1]=true;
                string str=conStr(n,i);
                undone.push_back(str);
                isOk(undone,col_used,left_used,right_used,n);
                col_used[i]=false;
                left_used[row+i]= false;
                right_used[i-row+n-1]=false;
                undone.erase(undone.begin()+row);
            }
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    if(n==0)
        return res;
    int len=(n-1)*2;
    bool col_used[len+1];
    bool left_used[len+1];
    bool right_used[len+1];
    for(int i=0;i<=len;i++){
        col_used[i]=false;
        left_used[i]=false;
        right_used[i]=false;
    }
    vector<string> undone;
    isOk(undone,col_used,left_used,right_used,n);
    return res;
}