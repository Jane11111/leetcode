#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

vector<string> removeInvalidParentheses(string s);
string Constru(string s,vector<bool> can_keep);
void Rec(string s,int start,stack<int> pos,vector<bool> & can_keep,int longest);
vector<string> res;
map<string,int> mymap;
int main() {
    string s="x(";
    vector<string> r=removeInvalidParentheses(s);
    for(int i=0;i<r.size();i++)
        cout<<r[i]<<endl;
    cout<<r.size()<<endl;
    return 0;
}

string Constru(string s,vector<bool> can_keep){
    string res;
    for(int i=0;i<s.size();i++){
        if((s[i]=='('||s[i]==')')&&!can_keep[i])
            continue;
        res.push_back(s[i]);
    }
    return res;

}

void Rec(string s,int start,stack<int> pos,vector<bool> & can_keep,int longest){
    if(start==s.size()){
        string r=Constru(s,can_keep);
        if(r.size()==longest&&mymap.find(r)==mymap.end()) {
            res.push_back(r);
            mymap[r]=true;
        }
        return ;
    }

    for(int i=start;i<s.size();i++){
        if(s[i]!='('&&s[i]!=')') {
            Rec(s,i+1,pos,can_keep,longest);
            return ;
        }

        if(s[i]=='(') {
            pos.push(i);
            Rec(s,i+1,pos,can_keep,longest);
            return ;
        }
        else {
            Rec(s,i+1,pos,can_keep,longest);//忽略这个位置

            while(!pos.empty()){//让它匹配
                int num=pos.top();
                can_keep[num]=true;
                can_keep[i]=true;
                pos.pop();
                Rec(s,i+1,pos,can_keep,longest);
                can_keep[i]=false;
                can_keep[num]=false;

            }
        }
    }


}
vector<string> removeInvalidParentheses(string s) {

    stack<int> pos;
    vector<bool> can_keep(s.size(),false);
    int longest=0;
    int count=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!='('&&s[i]!=')') {
            longest++;
            continue;
        }

        if(s[i]=='(')
            count++;
        else{
            if(count>0){
                count--;
                longest+=2;
            }
        }
    }

    Rec(s,0,pos,can_keep,longest);
    return res;

}