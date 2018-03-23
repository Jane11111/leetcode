#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<string> removeInvalidParentheses(string s);
void Remove(string s,int index,int left,int right,int pair,string sub);
map<string ,bool> mymap;
int main() {

}
void Remove(string s,int index,int left,int right,int pair,string sub){
    if(index==s.size()){
        if(left==0&&right==0&&pair==0)
            mymap[sub]=true;
        return ;
    }

    if(s[index]!='('&&s[index]!=')') {
        sub.push_back(s[index]);
        Remove(s, index + 1, left, right, pair,sub);
    }
    if(s[index]=='('){
        if(left>0){//不要它
            Remove(s,index+1,left-1,right,pair,sub);
        }
        //留下它
        sub.push_back(s[index]);
        Remove(s,index+1,left,right,pair+1,sub);
    }else{
        if(right>0){//不要它
            Remove(s,index+1,left,right-1,pair,sub);
        }

        if(pair>0) {//留下它
            sub.push_back(s[index]);
            Remove(s, index + 1,left,right,pair-1,sub);
        }
    }

}

vector<string> removeInvalidParentheses(string s){
    int left=0;
    int right=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(')
            left++;
        if(s[i]==')'){
            if(left>0)
                left--;
            else
                right++;
        }
    }
    string sub;
    Remove(s,0,left,right,0,sub);
    vector<string> res;
    map<string,bool> ::iterator ite=mymap.begin();
    while(ite!=mymap.end()){
        res.push_back(ite->first);
        ite++;
    }
    return res;


}
