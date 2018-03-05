#include <iostream>

using namespace std;
string removeDuplicateLetters(string s);

int main()
{
    string s="cbacdcbc";
    string res=removeDuplicateLetters(s);
    cout<<res<<endl;
}




string removeDuplicateLetters(string s) {

    string res="";
    int freq[26];
    for(int i=0;i<26;i++)
        freq[i]=0;
    for(int i=0;i<s.size();i++)
        freq[s[i]-'a']++;

    int pos=0;
    for(int i=0;i<s.size();i++){
        if(s[i]<s[pos])
            pos=i;
        int n=s[i]-'a';
        freq[n]--;
        if(freq[n]==0)
            break;
    }

    if(s.size()==0)
        return "";

    char c=s[pos];

    string str=s.substr(pos+1);
    string str2;
    for(int i=0;i<str.size();i++){
        if(str[i]!=c)
            str2+=str[i];

    }
    return c+removeDuplicateLetters(str2);



}
