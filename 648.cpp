#include <iostream>
#include <vector>
using namespace std;

struct TrieNode{
    string str;
    TrieNode* nodes[26];
    TrieNode(){
        str="";
        for(int i=0;i<26;i++)
            nodes[i]=NULL;
    }
};
string replaceWords(vector<string>& dict, string sentence);
int main() {
    vector<string> dict;
    dict.push_back("cat");
    dict.push_back("bat");
    dict.push_back("rat");

    string sentenct="the cattle was rattled by the battery";

    string str=replaceWords(dict,sentenct);
    cout<<str<<endl;
}



string replaceWords(vector<string>& dict, string sentence) {

    TrieNode* root=new TrieNode();
    for(string word: dict){
        TrieNode*p=root;
        for(char c:word){
            int n=c-'a';
            if(p->nodes[n]==NULL)
                p->nodes[n]=new TrieNode();
            p=p->nodes[n];
        }
        p->str=word;
    }

    string res;

    int pre=0;
    for(int cur=0;cur<sentence.size();cur++){
        char c=sentence[cur];
        if(c==' '||cur==sentence.size()-1){
            string str=sentence.substr(pre,cur-pre);
            if(cur==sentence.size()-1)
                str=sentence.substr(pre,cur+1-pre);
            pre=cur+1;

            TrieNode* p=root;
            for(char ch:str){
                if(!p||p->str!="")
                    break;
                int n=ch-'a';
                p=p->nodes[n];

            }
            if(p==NULL||p->str==""){
                res+=str;
                res+=" ";
            }
            else if(p->str!=""){
                res+=p->str;
                res+=" ";
            }

        }

    }
    if(res.size()){
        res=res.substr(0,res.size()-1);
    }
    return res;
}