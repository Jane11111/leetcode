#include <iostream>
#include <vector>
using namespace std;

int minDistance(string word1, string word2);
int MemoRec(string word1,string word2,vector<vector<int>>& M);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
int MemoRec(string word1,string word2,vector<vector<int>>& M){
    int len1=word1.size();
    int len2=word2.size();

    if(M[len1][len2]!=-1)
        return M[len1][len2];
    if(len1==0) {
        M[len1][len2] = len2;
        return len2;
    }
    if(len2==0) {
        M[len1][len2] = len1;
        return len1;
    }

    int n1=1+MemoRec(word1.substr(0,len1-1),word2,M);//删除
    int n2=1+MemoRec(word1,word2.substr(0,len2-1),M);//增加
    int n3=(word1[len1-1]==word2[len2-1]?0:1)+MemoRec(word1.substr(0,len1-1),word2.substr(0,len2-1),M);

    int res=min(n1,n2);
    res=min(res,n3);

    M[len1][len2]=res;
    return res;


}
int minDistance(string word1, string word2){

    int len1=word1.size();
    int len2=word2.size();
    vector<vector<int>> M;
    for(int i=0;i<=len1;i++){
        vector<int>t(len2+1,-1);
        M.push_back(t);
    }
    int res=MemoRec(word1,word2,M);
    return res;

}