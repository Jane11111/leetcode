#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<string> wordBreak(string s, vector<string>& wordDict);
bool MemoRec(string s,int start,map<string,bool>& mymap,map<int,vector<int>>& record);
void BackTrack(string s,int start,string tmp,map<int,vector<int>>& record);
vector<string> res;
int main() {
    string s="catsanddog";
    vector<string> words;
    words.push_back("cat");
    words.push_back("cats");
    words.push_back("and");
    words.push_back("sand");
    words.push_back("dog");
    vector<string> res=wordBreak(s,words);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;

    return 0;
}

bool MemoRec(string s,int start,map<string,bool>& mymap,map<int,vector<int>>& record){


    if(record.find(start)!=record.end()){
        return !record[start].empty();
    }
    if(start==s.size())
        return true;
    vector<int> v;
    record[start]=v;
    string tmp;
    for(int i=start;i<s.size();i++){
        tmp.push_back(s[i]);
        if(mymap.find(tmp)!=mymap.end()){
            bool f=MemoRec(s,i+1,mymap,record);
            if(f)
                record[start].push_back(i);
        }
    }
    return !record[start].empty();
}
void BackTrack(string s,int start,string tmp,map<int,vector<int>>& record){
    if(start==s.size()){
        tmp.erase(tmp.begin()+tmp.size()-1);
        res.push_back(tmp);
        return ;
    }
    vector<int> nexts=record[start];
    for(int i=0;i<nexts.size();i++){
        int cur=nexts[i];
        BackTrack(s,cur+1,tmp+s.substr(start,cur-start+1)+" ",record);
    }
}
vector<string> wordBreak(string s, vector<string>& wordDict) {


    if(s.empty())
        return res;

    map<string,bool> mymap;
    for(int i=0;i<wordDict.size();i++)
        mymap[wordDict[i]]=true;

    map<int,vector<int>> record;
    MemoRec(s,0,mymap,record);

    string tmp;
    BackTrack(s,0,tmp,record);
    return res;




}