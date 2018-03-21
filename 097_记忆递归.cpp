#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool MemoRec(string s1,int i1,string s2,int i2,string s3,int i3,map<vector<int>,bool> & M);
bool isInterleave(string s1, string s2, string s3);
int main() {
    string s1="aabc";
    string s2="abad";
    string s3="aabadabc";
    bool res=isInterleave(s1,s2,s3);
    if(res)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}
bool MemoRec(string s1,int i1,string s2,int i2,string s3,int i3,map<vector<int>,bool> & M){
    if(M.find({i1,i2,i3})!=M.end())
        return M[{i1,i2,i3}];
    if(s3.size()!=s1.size()+s2.size())
        return false;

    bool f;
    if(i1==s1.size()&&i2==s2.size()&&i3==s3.size()){
        f=true;
    }else if(i1==s1.size()){
        if(i2==s2.size()||i3==s3.size())
            f=false;
        else
            f=s2.substr(i2)==s3.substr(i3);
    }else if(i2==s2.size()){
        if(i3==s3.size())
            f=false;
        else
            f=s1.substr(i1)==s3.substr(i3);
    }else if(i3==s3.size()){
        f=false;
    }else{
        bool f1=false;
        bool f2=false;
        if(s1[i1]==s3[i3])
            f1=MemoRec(s1,i1+1,s2,i2,s3,i3+1,M);
        if(s2[i2]==s3[i3]){
            f2=MemoRec(s1,i1,s2,i2+1,s3,i3+1,M);
        }
        f=f1||f2;
    }
    M[{i1,i2,i3}]=f;
    return f;
}
bool isInterleave(string s1, string s2, string s3){

    map<vector<int>,bool> M;
    bool res=MemoRec(s1,0,s2,0,s3,0,M);
    return res;

}