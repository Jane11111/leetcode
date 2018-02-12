#include <iostream>
#include <string>
using namespace std;
bool isSubsequence(string s, string t);
int main() {
    string s="axc";
    string t="ahbgdc";
    bool res=isSubsequence(s,t);
    if(res)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}

bool isSubsequence(string s, string t) {
    if(s.size()==0)
        return true;
    int s_len=s.size();
    int t_len=t.size();
    int index=0;
    for(int i=0;i<t_len;i++){
        if(index<s_len&&s[index]==t[i])
            index++;
    }

    if(index==s_len)
        return true;
    else
        return false;


}