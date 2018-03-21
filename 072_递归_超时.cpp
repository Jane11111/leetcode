#include <iostream>
#include <vector>
using namespace std;

int minDistance(string word1, string word2);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int minDistance(string word1, string word2) {


    if(word1.empty())
        return word2.size();
    if(word2.empty())
        return word1.size();


    int len1=word1.size();
    int len2=word2.size();
    int n1=0;
    int n2=0;
    int n3=0;
    int t=1;
    if(word1[len1-1]==word2[len2-1]){
        t=0;
    }
    n1=t+minDistance(word1.substr(0,len1-1),word2.substr(0,len2-1));//替换
    n2=minDistance(word1,word2.substr(0,len2-1));//增加
    n3=minDistance(word1.substr(0,len1-1),word2);//删除
    int res=min(n1,n2);
    res=min(res,n3);
    return res;
}