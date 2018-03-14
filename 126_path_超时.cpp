#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList);
int calDiff(string a,string target);
bool isNeighbor(string& a,string& b);
int main() {
    string begin="hit";
    string end="cog";
    vector<string> words;
    words.push_back("hot");
    words.push_back("dot");
    words.push_back("dog");
    words.push_back("lot");
    words.push_back("log");
    words.push_back("cog");
    vector<vector<string>> res=findLadders(begin,end,words);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++)
            cout<<res[i][j];
        cout<<endl;
    }
}


int calDiff(string a,string target){

}
bool isNeighbor(string& a,string& b){
    int count=0;
    for(int i=0;i<a.size();i++)
        if(a[i]!=b[i])
            count++;
    return count==1;
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {


    vector<vector<string>> res;

    map<string,vector<vector<string>>> prelist;
    map<string,int> level;
    vector<string> Q;




    int len=wordList.size();




    for(int i=0;i<len;i++){
        string word=wordList[i];
        vector<vector<string>> t;
        prelist[word]=t;
        level[word]=INT_MAX;
    }
    if(!level.count(endWord))//不含有endword 不存在路径
        return res;





    level[beginWord]=1;
    vector<string> t;
    t.push_back(beginWord);
    prelist[beginWord].push_back(t);
    Q.push_back(beginWord);


    while(!Q.empty()){

        int count=Q.size();

        string s=Q[0];
        Q.erase(Q.begin());
        int l=level[s];
        vector<vector<string>> pres=prelist[s];
        for(int i=0;i<len;i++){
            string word=wordList[i];
            //已visited过且找到了另外一条路径,或者未visited过且是邻居 这样可以减少比较次数
            if(l+1<=level[word]&&isNeighbor(s,word)){
                for(int k=0;k<pres.size();k++){
                    pres[k].push_back(word);
                    prelist[word].push_back(pres[k]);
                    pres[k].erase(pres[k].begin()+pres[k].size()-1);
                }
                if(level[word]==INT_MAX){
                    level[word]=l+1;
                    Q.push_back(word);
                }
            }

        }
    }

    return prelist[endWord];
}