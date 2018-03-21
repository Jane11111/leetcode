#include <iostream>
#include <vector>
using namespace std;


int Find(string s,int start,int cur,string& target,vector<vector<int>>& M);
int numDistinct(string s, string t);
int main() {
    string s="rabbbit";
    string t="rabbit";
    int res=numDistinct(s,t);
    cout<<res<<endl;
    return 0;
}
int Find(string s,int start,int cur,string& target,vector<vector<int>>& M){

    if(M[start][cur]!=-1)
        return M[start][cur];

    if(cur==target.size()){
        M[start][cur]=1;
        return 1;
    }

    int r=0;
    for(int i=start;i<s.size();i++){
        if(s[i]==target[cur]){
            int t=Find(s,i+1,cur+1,target,M);
            r+=t;

        }
    }

    M[start][cur]=r;
    return r;


}
int numDistinct(string s, string t){

    if(t.empty())
        return 0;
    int len1=s.size();
    int len2=t.size();
    vector<vector<int>>M(len1+1,vector<int>(len2+1,-1));
    int res=Find(s,0,0,t,M);
    return res;

}