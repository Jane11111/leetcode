#include <iostream>
#include <vector>
#include <map>
using namespace std;

class MagicDictionary {
public:

    struct TrieNode {
        string str;
        char c;
        TrieNode *nodes[26];
        TrieNode *pre;

        TrieNode() {
            str = "";
            pre = NULL;
            for (int i = 0; i < 26; i++)
                nodes[i] = NULL;
        }

    };

    TrieNode *root;

    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new TrieNode();
    }

    /** Build a dictionary through a list of words */
    void buildDict(vector <string> dict) {
        for (string word:dict) {
            TrieNode *p = root;
            for (char c: word) {
                int n = c - 'a';
                if (p->nodes[n] == NULL) {
                    p->nodes[n] = new TrieNode();
                    p->nodes[n]->c=c;
                    p->nodes[n]->pre = p;
                }

                p = p->nodes[n];
            }
            p->str = word;
        }
    }

    //root当前所指为第start个字符所在位置，希望start这个位置的字符错误。
    bool searchSubstr(string word, int start, TrieNode *root) {
        if (start == -1)
            return false;
        int cur = word[start] - 'a';
        TrieNode *p = root->pre;
        TrieNode* tmp=p;

        bool f = false;
        for (int i = 0; i < 26; i++) {
            p = tmp->nodes[i];
            if (i != cur && p) {
                for (int index = start + 1; index < word.size(); index++) {
                    if (p == NULL)
                        break;
                    char c = word[index];
                    int n = c - 'a';
                    p = p->nodes[n];
                }
                if (p && p->str != "")
                    f = true;

            }
            if (f)
                return f;
        }
        return searchSubstr(word, start - 1, root->pre);

    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        TrieNode *p = root;

        int i = 0;
        for (; p && i < word.size(); i++) {
            int n = word[i] - 'a';

            if(p->nodes[n]==NULL){
                p->nodes[n]=new TrieNode();
                p->nodes[n]->pre=p;
                p=p->nodes[n];
                i++;
                break;
            }
            p = p->nodes[n];
        }
        i--;
        return searchSubstr(word, i, p);
    }
};


int main() {
    MagicDictionary obj;
    vector<string> dict;
    dict.push_back("hello");
    dict.push_back("leetcode");
    obj.buildDict(dict);
    string word="leetcoded";
    bool r=obj.search(word);
    if(r)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;


}
