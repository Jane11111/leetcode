#include <iostream>
#include <vector>
using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


class MapSum {
public:
    struct TrieNode{

        string str;
        int sum;
        int num;
        TrieNode * nodes[26];
        TrieNode(){
            str=NULL;
            sum=0;
            num=0;
            for(int i=0;i<26;i++){
                nodes[i]=NULL;
            }
        }
    };
    TrieNode* root;
    /** Initialize your data structure here. */
    MapSum() {
        root=new TrieNode();

    }

    void insert(string key, int val) {
        int num;
        TrieNode * p=root;
        for(char c :key){
            int n=c-'a';
            if(p->nodes[n]==NULL)
                (p->nodes)[n]=new TrieNode();
            p=(p->nodes)[n];
        }
        p->str=key;
        num=val-(p->num);
        p->num=val;
        p->sum=(p->sum)+num;

        p=root;
        for(char c: key){
            p->sum=(p->sum)+num;
            int n=c-'a';
            p=(p->nodes)[n];

        }
    }

    int sum(string prefix) {
        TrieNode * p=root;
        for(char c :prefix){
            if(p==NULL)
                return 0;
            int n=c-'a';
            p=(p->nodes)[n];
        }
        return p->sum;

    }
};
