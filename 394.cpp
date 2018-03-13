#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

string decodeString(string s);
int StrToInt(string s);
int main() {
    string s="3[a2[c]]";
    string res=decodeString(s);
    cout<<res<<endl;
}
int StrToInt(string s){
    istringstream is(s);
    int n;
    is>>n;
    return n;
}

string decodeString(string s) {

    vector<string> stack;
    string res;

    string str;
    for(int i=0;i<s.size();i++){

        char c=s[i];
        if(c=='['){
            stack.insert(stack.begin(),str);
            str="";
        }else if(c==']'){
            int n=1;
            if(!stack.empty()){
                n=StrToInt(stack[0]);
                stack.erase(stack.begin());
            }
            string tmp=str;
            while(n>1){
                str+=tmp;
                n--;
            }
            while(!stack.empty()&&!isdigit(stack[0][0])){
                str=stack[0]+str;
                stack.erase(stack.begin());
            }
            if(stack.empty()) {
                res = res + str;
                str="";
            }



        }else{
            if(!str.empty()&&(isdigit(str[0])&&!isdigit(c)||!isdigit(str[0])&&isdigit(c))){
                stack.insert(stack.begin(),str);
                str="";
            }
            str.push_back(c);
        }
    }
    return res+str;

}