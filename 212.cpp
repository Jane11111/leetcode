#include <iostream>
#include<vector>
using namespace std;

struct TrieNode{
    string str;
    TrieNode* next [26];
    TrieNode(){
        str="";
        for(int i=0;i<26;i++)
            next[i]=NULL;
    }

};
vector<string> res;
vector<string> findWords(vector<vector<char>>& board, vector<string>& words);
void RecFind(vector<vector<char>>& board,int x,int y,vector<vector<bool>>& used);
bool isValid(int x,int y,int m,int n);
int main() {
    vector<vector<char>> board;
    vector<char> t1={'o','a','a','n'};
    vector<char> t2={'e','t','a','e'};
    vector<char> t3={'i','h','k','r'};
    vector<char> t4={'i','f','l','v'};

    board.push_back(t1);
    board.push_back(t2);
    board.push_back(t3);
    board.push_back(t4);
    vector<string> words;
    words.push_back("eat");
    words.push_back("oath");
    vector<string> res=findWords(board,words);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
    return 0;
}
bool isValid(int x,int y,int m,int n){
    return x>=0&&x<m&&y>=0&&y<n;
}

void RecFind(vector<vector<char>>& board,int x,int y,vector<vector<bool>>& used,TrieNode* p){
    if(!p)
        return ;
    if(!(p->str).empty()) {
        res.push_back(p->str);
        p->str="";
    }
    used[x][y]=true;

    int m=board.size();
    int n=board[0].size();

    int t1=x-1,t2=y;
    if(isValid(t1,t2,m,n)&&!used[t1][t2]&&p->next[board[t1][t2]-'a']){
        RecFind(board,t1,t2,used,p->next[board[t1][t2]-'a']);
    }
    t1=x+1,t2=y;
    if(isValid(t1,t2,m,n)&&!used[t1][t2]&&p->next[board[t1][t2]-'a']){
        RecFind(board,t1,t2,used,p->next[board[t1][t2]-'a']);
    }
    t1=x,t2=y-1;
    if(isValid(t1,t2,m,n)&&!used[t1][t2]&&p->next[board[t1][t2]-'a']){
        RecFind(board,t1,t2,used,p->next[board[t1][t2]-'a']);
    }
    t1=x,t2=y+1;
    if(isValid(t1,t2,m,n)&&!used[t1][t2]&&p->next[board[t1][t2]-'a']){
        RecFind(board,t1,t2,used,p->next[board[t1][t2]-'a']);
    }
    used[x][y]=false;


}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words){

    int m=board.size();
    if(!m)
        return res;
    int n=board[0].size();
    if(!n)
        return res;

    TrieNode* head=new TrieNode();
    for(int i=0;i<words.size();i++){
        TrieNode* p=head;
        string word=words[i];
        for(int j=0;j<word.size();j++){
            if(p->next[word[j]-'a']==NULL)
                p->next[word[j]-'a']=new TrieNode();
            p=p->next[word[j]-'a'];
        }
        p->str=word;
    }

    vector<vector<bool>> used(m,vector<bool>(n,false));
    for(int i=0;i<m;i++){

        for(int j=0;j<n;j++){
            if(head->next[board[i][j]-'a']){
                RecFind(board,i,j,used,head->next[board[i][j]-'a']);
            }
        }
    }

    return res;
}