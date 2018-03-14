#include <iostream>
#include <vector>
#include <map>
using namespace std;


vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList);
vector<vector<string>> res;
void DFS(string start,string end,vector<string> list,map<string,vector<string>> &prelist);
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
    cout<<res.size()<<endl;
    return 0;
}

void DFS(string start,string end,vector<string> list,map<string,vector<string>> &prelist){
    if(start==end){
        list.insert(list.begin(),start);
        res.push_back(list);
        return ;
    }

    vector<string> pres=prelist[end];
    for(int i=0;i<pres.size();i++){
        string e=pres[i];
        list.insert(list.begin(),end);
        DFS(start,e,list,prelist);
        list.erase(list.begin());
    }

}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList){


    vector<string> Q;
    map<string,int> level;//可以被用来代替visited
    map<string,vector<string>> prelist;


    for(int i=0;i<wordList.size();i++){
        level[wordList[i]]=INT_MAX;
    }

    if(!level.count(endWord))
        return res;

    Q.push_back(beginWord);
    level[beginWord]=1;
    while(!Q.empty()){
        string s=Q[0];
        Q.erase(Q.begin());
        if(s==endWord)//无须再遍历
            break;

        int cur=level[s]+1;

        for(int i=0;i<s.size();i++){//不是一个一个比对而是先找出来neighbor
            string s2=s;
            for(int j=0;j<26;j++){
                s2[i]=char('a'+j);
                if(s2==s||!level.count(s2))//不存在s2或者说s2==s
                    continue;
                if(level[s2]<cur)
                    continue;
                if(level[s2]>cur) {
                    level[s2] = cur;
                    Q.push_back(s2);
                }

                if(!prelist.count(s2)){
                    vector<string> t;
                    prelist[s2]=t;
                }
                prelist[s2].push_back(s);


            }
        }
    }
    if(!prelist.count(endWord))
        return res;

    vector<string> list;
    DFS(beginWord,endWord,list,prelist);
    return res;


}



