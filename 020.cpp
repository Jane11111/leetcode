#include <iostream>
#include<vector>
using namespace std;

bool isValid(string s);
int main()
{

}
bool isValid(string s) {

    vector<char> chars;
    for(int i=0;i<s.size();i++){
        char c=s[i];
        if(c=='('||c=='{'||c=='[')
            chars.insert(chars.begin(),c);
        else if(c==')'){
            if(!chars.empty()&&chars[0]=='(')
                chars.erase(chars.begin());
            else
                return false;
        }
        else if(c=='}'){
            if(!chars.empty()&&chars[0]=='{')
                chars.erase(chars.begin());
            else
                return false;

         }
         else if (c==']'){
            if(!chars.empty()&&chars[0]=='[')
                chars.erase(chars.begin());
            else
                return false;
         }
    }

    return chars.empty();

}
