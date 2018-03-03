#include <iostream>
#include <vector>
using namespace std;
struct TrieNode{
    bool isStr;
    TrieNode* nodes[26];
    TrieNode(){
        isStr=false;
        for(int i=0;i<26;i++)
            nodes[i]=NULL;
    }
};

string longestWord(vector<string>& words);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

string longestWord(vector<string>& words) {

    TrieNode* root=new TrieNode;
    string res="";

    int len=words.size();
    for(int i=0;i<len;i++){
        string word=words[i];
        for(int j=i-1;j>=0;j--){
            if(word.size()<words[j].size())
                swap(words[j],words[j+1]);
        }
    }

    for(string word:words){
        TrieNode* p=root;
        bool f=true;
        for(int i=0;i<word.size();i++){
            char c=word[i];
            int n=c-'a';
            if(p->nodes[n]==NULL)
                p->nodes[n]=new TrieNode();

            p=p->nodes[n];
            if(i!=word.size()-1&&p->isStr==false)
                f=false;

        }
        p->isStr=true;
        if(f && (word.size()>res.size()||(word.size()==res.size()&&word<res)))
            res=word;

    }

    return res;


}