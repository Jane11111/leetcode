#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int longestValidParentheses(string s);
int main() {
    string s="()";
    int res=longestValidParentheses(s);
    cout<<res<<endl;
    return 0;
}

int longestValidParentheses(string s) {

    int len=s.size();
    int res=0;
    if(len==0)
        return res;
    vector<int> valid_match(len,-1);
    stack<int>mystack;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(')
            mystack.push(i);
        else{
            if(!mystack.empty()){
                int index=mystack.top();
                mystack.pop();
                valid_match[index]=i;
            }
        }
    }

    for(int i=0;i<len;){
        int count=0;
        while(i<len&&valid_match[i]!=-1){
            int next=valid_match[i];
            count+=next-i+1;
            i=next+1;
        }
        res=max(res,count);
        i++;
    }
    return res;


}