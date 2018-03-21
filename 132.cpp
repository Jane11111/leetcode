#include <iostream>
#include <vector>
using namespace std;

int FindMin(vector<vector<bool>>&M,int s,vector<int>& record);
int minCut(string s);
int main() {
    string s="aaabaa";
    int res=minCut(s);
    cout<<res<<endl;
    return 0;
}
int FindMin(vector<vector<bool>>&M,int s,vector<int>& record){
    if(record[s]!=-1)
        return record[s];
    if(s==M.size()) {
        record[s]=0;
        return 0;
    }
    int res=INT_MAX;
    for(int i=s;i<M.size();i++){
        if(M[s][i]){
            int r=1+FindMin(M,i+1,record);
            res=min(res,r);
        }
    }
    record[s]=res;
    return res;
}
int minCut(string s) {
    if(s.empty())
        return 0;

    int len=s.size();

    vector<vector<bool>> M(len,vector<bool>(len,false));

    for(int i=0;i<len;i++)
        M[i][i]=true;

    for(int step=1;step<len;step++){

        for(int i=0;i<len-step;i++){
            M[i][i+step]=s[i]==s[i+step]&&(i+1>i+step-1||M[i+1][i+step-1]);
        }
    }
    vector<int> record(len+1,-1);
    int res=FindMin(M,0,record);
    return res-1;

}