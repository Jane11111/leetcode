#include <iostream>
#include <vector>
#include <map>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList);
bool isNeighbor(string a,string b);
int main() {
    string begin="hit";
    string end="cog";
    vector<string> wordList;
    wordList.push_back("hot");
    wordList.push_back("dot");
    wordList.push_back("dog");
    wordList.push_back("lot");
    wordList.push_back("log");
    wordList.push_back("cog");

    int res=ladderLength(begin,end,wordList);
    cout<<res<<endl;
}
bool isNeighbor(string a,string b){
    int count=0;
    for(int i=0;i<a.size();i++)
        if(a[i]!=b[i])
            count++;
    return count==1;
}
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

    map<string,bool> visited;
    vector<int> level;

    for(int i=0;i<wordList.size();i++)
        visited[wordList[i]]=false;


    if(!visited.count(endWord))
        return 0;
    visited[beginWord]=false;
    visited[endWord]=false;

    vector<string> Q;
    level.push_back(1);
    Q.push_back(beginWord);
    visited[beginWord]=true;

    while(!Q.empty()){
        string s=Q[0];
        Q.erase(Q.begin());
        int l=level[0];
        level.erase(level.begin());
        map<string,bool> ::iterator ite=visited.begin();
        while(ite!=visited.end()){
            string word=ite->first;
            if(!ite->second&&isNeighbor(word,s)){
                if(word==endWord)
                    return l+1;
                visited[word]=true;
                level.push_back(l+1);
                Q.push_back(word);
            }
            ite++;
        }
    }

    return 0;
}