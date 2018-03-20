#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words);
int main() {
    vector<string> words;
    words.push_back("foo");
    words.push_back("bar");
    string s="barfoothefoobarman";
    vector<int> res=findSubstring(s,words);
    cout<<res.size()<<endl;
    return 0;
}

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    if(s.empty()||words.empty()||words[0].empty())
        return res;

    map<string,int> wmap;
    map<string,int> cmap;
    for(int i=0;i<words.size();i++){
        wmap[words[i]]=i;
        cmap[words[i]]++;
    }

    //vector<int> isstart(s.size(),-1);
    vector<int> used(words.size(),-1);

    int n=words[0].size();
    /*for(int i=0;i<s.size()-(n-1);i++){
        string tmp=s.substr(i,n);
        map<string,int> ::iterator ite=wmap.find(tmp);
        if(ite!=wmap.end()){
            isstart[i]=ite->second;
        }
    }*/

    for(int i=0;i<s.size()-(n*words.size()-1);i++){
        string cur=s.substr(i,n);
        if(wmap.find(cur)!=wmap.end()){
            map<string,int> tmp;//纪录每个单词出现的个数
            bool f=true;
            for(int j=i;j<i+words.size()*n;j=j+n){
                string w=s.substr(j,n);

                //string w=words[isstart[j]];
                tmp[w]++;
                if(tmp[w]>cmap[w]){
                    f=false;
                    break;
                }
            }
            if(f)
                res.push_back(i);

        }
    }
    return res;



}