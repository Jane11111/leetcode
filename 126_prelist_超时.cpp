#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList);
int calDiff(string a,string target);
bool isNeighbor(string a,string b);
vector<vector<string>> DFS(string cur,map<string,vector<string>> & prelist);
int main() {
    string begin="a";
    string end="c";
    vector<string> words;
    words.push_back("a");
    words.push_back("c");
    words.push_back("b");
   // words.push_back("lot");
   // words.push_back("log");
   // words.push_back("cog");
    vector<vector<string>> res=findLadders(begin,end,words);
    cout<<res.size()<<endl;
    return 0;
}

int calDiff(string a,string target){
    int count=0;
    for(int i=0;i<a.size();i++)
        if(a[i]!=target[i])
            count++;
    return count;
}
bool isNeighbor(string a,string b){
    return calDiff(a,b)==1;
}


vector<vector<string>> DFS(string cur,map<string,vector<string>> & prelist){
    vector<string> pres=prelist[cur];
    vector<vector<string>> res;

    if(pres.empty()){
        vector<string> t;
        t.push_back(cur);
        res.push_back(t);
        return res;
    }

    for(int i=0;i<pres.size();i++){
        vector<vector<string>> t=DFS(pres[i],prelist);
        for(int j=0;j<t.size();j++){
            t[j].push_back(cur);
            res.push_back(t[j]);
        }
    }
    return res;
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

    vector<vector<string>> res;

    map<string,bool>visited;
    map<string,vector<string>> prelist;
    map<string,int> level;
    vector<string> Q;

    int len=wordList.size();
    for(int i=0;i<len;i++){
        string word=wordList[i];
        vector<string> t;
        prelist[word]=t;
        visited[word]=false;
        level[word]=INT_MAX;
    }
    if(!visited.count(endWord))//不含有endword 不存在路径
        return res;

    visited[beginWord]=true;
    level[beginWord]=1;
    Q.push_back(beginWord);
    while(!Q.empty()){
        string s=Q[0];
        Q.erase(Q.begin());
        int l=level[s];
        for(int i=0;i<len;i++){
            string word=wordList[i];
            if(isNeighbor(s,word)){//首先需要是邻居
                if(l+1<=level[word])//其次需要是条最短路径
                    prelist[word].push_back(s);
                if(!visited[word]){
                    visited[word]=true;
                    level[word]=l+1;
                    Q.push_back(word);
                }
            }
        }
    }

    if(prelist[endWord].size()==0)//没有路径可达
        return res;

    res=DFS(endWord,prelist);
    return res;
}